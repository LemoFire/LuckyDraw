#include<stdio.h>
#include<string.h>
#include<conio.h>
#include <windows.h>
#include<time.h>
#include"struct.h"
void prize_inf_input()	//���影Ʒ��Ϣ����
{
	void log(int n);
	void writeinfo();
	void logtime();
	void main();
	void pnumcheck();
	int n = 0;
	char temp[20];
	extern struct prize p;	//�ⲿ�ṹ��
	char(*pn)[20], (*gn)[20];	//ָ�붨���ά����
	printf("\n*****************************\n");
	printf("\n�����뽱������������1-3�Ƚ���������3��");
	scanf("%d", &p.num);	//���뽱������
	if (p.num<1 || p.num>20)	//�жϽ��������Ƿ�����������20������
	{
		printf("\n������󣬰��������������");
		getch();
		getchar();
		prize_inf_input();
	}
	pn = p.prize_name;
	gn = p.goods_name;
	//����ָ�����
	logtime();
	for (n; n + 1 <= p.num; n++)	//ѭ������ÿ������������Ϣ
	{
		printf("\n-----------------------------------------------\n\n");
		printf("������%d�Ƚ��Ľ�Ʒ���ƣ��磺С���ֻ���:", n + 1);
		scanf("%s", temp);
		strcpy(*(gn + n), temp);
		printf("������%d�Ƚ��Ľ������ƣ��磺�صȽ���:", n + 1);
		scanf("%s", temp);
		printf("������%d�Ƚ��Ľ�Ʒ���������30��:", n + 1);
		scanf("%d", &p.prize_people[n]);
		while (1)	//�жϽ�Ʒ�����Ƿ�����
		{
			if (p.prize_people[n] <= 0 || p.prize_people[n] > 30)
			{
				printf("\n���������������30�ˣ�������\n");
				printf("\n������%d�Ƚ��Ľ�Ʒ�������磺3��:", n + 1);
				scanf("%d", &p.prize_people[n]);
			}
			else break;
		}
		strcpy(*(pn + n), temp);
		log(n);
	}
	pnumcheck();
	extern int definitionflag;
	definitionflag = 1;	//���Ϊ�Զ������Ʒ
	printf("\n��Ʒ��Ϣ¼����ɣ�¼����Ϣ�����ڵ�ǰĿ¼�£���������������˵�\n\n");
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
	printf("���������齱��������");
	scanf("%d", &pnum);
	if (pnum < 30)
	{
		if (pnum <= 0)
		{
			printf("������һ����ȷ������");
			pnumcheck();
		}
		else
		{
			for (n = 0; n < 20; n++)
			{
				if (pnum < p.prize_people[n])
				{
					printf("\n������������������\n");
					pnumcheck();
				}
			}
		}
	}
	pnum += 1;
}