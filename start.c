#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
#include"struct.h"
int tempnum[20][30];	//ȫ�ֱ������н����룬20�飬ÿ������¼30��
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
	printf("           ��ʼ�齱\n\n");
	printf("##############################\n\n\n");
	printf("------------------------------\n\n\n");
	logtime();
	extern struct prize p;
	for (flag = 0; flag<20; flag++)
	{
		if (p.prize_name[flag][1] == '\0')
			break;
	}
	srand((unsigned)time(NULL));	//�ı�����ֵ
	for (i = p.num; i > 0; i--)	//����齱������С�Ľ�Ʒ����
	{
		printf("\n���ڳ�ȡ%s:%s����%d��\n\n", p.prize_name[i - 1], p.goods_name[i - 1], p.prize_people[i - 1]);
		getch();
		FILE *fp;
		if ((fp = fopen("info.txt", "a")) == NULL)
		{
			printf("�޷���¼��־\n");
		}
		fputs("\n****************\n\n", fp);
		fputs(*(pn + flag -n-1), fp);
		n++;
		fputs("	", fp);
		fputs("�н�����:", fp);
		fclose(fp);
		for (x = 1; x <= p.prize_people[i - 1]; x++)		//���齱������ȡ����
		{
			tn = randnum();
			check(&tn, i);	//���鵽�ĺ����Ƿ����ظ�
			tempnum[i-1][x - 1] = tn;
			printf("��%dλ:%d��\t", x, tempnum[i-1][x-1]);
			lognum(i - 1, x-1, x);
			getch();
		}
		printf("\n");
	}
	FILE *fp;
	fp = fopen("info.txt", "a");	//��β����
	fputs("\n\n", fp);
	fclose(fp);
	printf("\n�齱��ɣ���������������˵�\n\n");
	getch();
	system("cls");
	memset(tempnum, 0, sizeof(tempnum));	//�����ڴ渳ֵ����������tempnum���鸳ֵΪ0����ֹ�ڶ��γ齱ʱ�������
	main();
}
void check(int *p,int i)	//���鵽�ĺ����Ƿ����ظ�
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
int randnum()	//�����������
{
	int i;
	extern int pnum;
	i = (rand() % pnum);
	return i;
}