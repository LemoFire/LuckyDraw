#include<stdio.h>
#include<string.h>
#include<conio.h>
#include <windows.h>
#include<time.h>
#include"struct.h"
void prize_inf_input()	//定义奖品信息函数
{
	void log(int n);
	void writeinfo();
	void logtime();
	void main();
	void pnumcheck();
	int n = 0;
	char temp[20];
	extern struct prize p;	//外部结构体
	char(*pn)[20], (*gn)[20];	//指针定义二维数组
	printf("\n*****************************\n");
	printf("\n请输入奖项数量（如有1-3等奖，则输入3）");
	scanf("%d", &p.num);	//输入奖项数量
	if (p.num<1 || p.num>20)	//判断奖项数量是否合理，最大设置20个奖项
	{
		printf("\n输入错误，按任意键重新输入");
		getch();
		getchar();
		prize_inf_input();
	}
	pn = p.prize_name;
	gn = p.goods_name;
	//定义指针变量
	logtime();
	for (n; n + 1 <= p.num; n++)	//循环输入每个奖项的相关信息
	{
		printf("\n-----------------------------------------------\n\n");
		printf("请输入%d等奖的奖品名称（如：小米手机）:", n + 1);
		scanf("%s", temp);
		strcpy(*(gn + n), temp);
		printf("请输入%d等奖的奖项名称（如：特等奖）:", n + 1);
		scanf("%s", temp);
		printf("请输入%d等奖的奖品数量（最大30）:", n + 1);
		scanf("%d", &p.prize_people[n]);
		while (1)	//判断奖品数量是否有误
		{
			if (p.prize_people[n] <= 0 || p.prize_people[n] > 30)
			{
				printf("\n数据输入有误，最大30人，请重试\n");
				printf("\n请输入%d等奖的奖品数量（如：3）:", n + 1);
				scanf("%d", &p.prize_people[n]);
			}
			else break;
		}
		strcpy(*(pn + n), temp);
		log(n);
	}
	pnumcheck();
	extern int definitionflag;
	definitionflag = 1;	//标记为以定义过奖品
	printf("\n奖品信息录入完成，录入信息保存在当前目录下，按任意键返回主菜单\n\n");
	writeinfo();
	getch();
	system("cls");
	main();
}
void pnumcheck()
{
	int n;
	extern int pnum;
	printf("\n-----------------------------------------------\n\n");
	printf("请输入参与抽奖的人数：");
	scanf("%d", &pnum);
	if (pnum < 30)
	{
		if (pnum <= 0)
		{
			printf("请输入一个正确的人数");
			pnumcheck();
		}
		else
		{
			for (n = 0; n < 20; n++)
			{
				if (pnum < p.prize_people[n])
				{
					printf("\n数据输入有误，请重试\n");
					pnumcheck();
				}
			}
		}
	}
	pnum += 1;
}