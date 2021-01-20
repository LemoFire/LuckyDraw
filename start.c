#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
#include"struct.h"
int tempnum[20][30];	//全局变量，中奖号码，20组，每组最多记录30人
void start()
{	void check();
	void logtime();
	void main();
	void lognum();	
	void check(int *p,int i); 
	extern struct prize p;
	char(*pn)[20], (*gn)[20], *pp;
	pn = p.prize_name;
	pp = p.prize_people;
	int i, n = 0, x, tn, flag;
	extern int tempnum[20][30];
	int randnum();
	system("cls");
	printf("##############################\n\n");
	printf("           开始抽奖\n\n");
	printf("##############################\n\n\n");
	printf("------------------------------\n\n\n");
	logtime();
	extern struct prize p;
	for (flag = 0; flag<20; flag++)
	{
		if (p.prize_name[flag][1] == '\0')
			break;
	}
	srand((unsigned)time(NULL));	//改变种子值
	for (i = p.num; i > 0; i--)	//倒叙抽奖，从最小的奖品抽起
	{
		printf("\n现在抽取%s:%s，共%d名\n\n", p.prize_name[i - 1], p.goods_name[i - 1], p.prize_people[i - 1]);
		getch();
		FILE *fp;
		if ((fp = fopen("info.txt", "a")) == NULL)
		{
			printf("无法记录日志\n");
		}
		fputs("\n****************\n\n", fp);
		fputs(*(pn + flag -n-1), fp);
		n++;
		fputs("	", fp);
		fputs("中奖号码:", fp);
		fclose(fp);
		for (x = 1; x <= p.prize_people[i - 1]; x++)		//按抽奖人数抽取号码
		{
			tn = randnum();
			check(&tn, i);	//检查抽到的号码是否有重复
			tempnum[i-1][x - 1] = tn;
			printf("第%d位:%d号\t", x, tempnum[i-1][x-1]);
			lognum(i - 1, x-1, x);
			getch();
		}
		printf("\n");
	}
	FILE *fp;
	fp = fopen("info.txt", "a");	//结尾换行
	fputs("\n\n", fp);
	fclose(fp);
	printf("\n抽奖完成，按任意键返回主菜单\n\n");
	getch();
	system("cls");
	memset(tempnum, 0, sizeof(tempnum));	//借助内存赋值函数将整个tempnum数组赋值为0，防止第二次抽奖时程序崩溃
	main();
}
void check(int *p,int i)	//检查抽到的号码是否有重复
{
	int x;
	int randnum();
	extern int tempnum[20][30];
	for (x = 1; x <= 30; x++)
	{
		if (tempnum[i-1][x-1] == *p || *p == 0)
		{
			*p = randnum();
			check(p, i);
		}
	}
}
int randnum()	//随机号码生成
{
	int i;
	extern int pnum;
	i = (rand() % pnum);
	return i;
}