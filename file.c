#include<stdio.h>
#include<windows.h>
#include"struct.h"
void readinfo()	//��ȡ�ϴν�Ʒ�������ݵĺ���
{
	void main();
	FILE *data;
	if ((data = fopen("info.dat", "rb")) == NULL)
	{
		printf("�޷��������ļ�\n");
		exit(0);
	}
	if (fread(&p, sizeof (struct prize), 1, data) != 1)
	{
		printf("��ȡ���ݴ���\n");
		getch();
		system("cls");
		main();
	}fclose(data);
	void pnumcheck(int n);
	pnumcheck(0);
	//���¼�¼��ǰ�齱����
	extern int definitionflag;
	definitionflag = 1;	//���Ϊ�Զ������Ʒ
	printf("\n��Ʒ��Ϣ¼����ɣ�¼����Ϣ�����ڵ�ǰĿ¼�£���������������˵�\n\n");
	getch();
}

void writeinfo()	//д�뵱ǰ��Ʒ�����������ݵ��ļ�
{
	FILE *data;
	if ((data = fopen("info.dat", "wb")) == NULL)
	{
		printf("�޷��������ļ�\n");
		getch();
		exit(0);
	}
	if (fwrite(&p, sizeof (struct prize), 1, data) != 1)
		printf("�޷�д�����ݵ�����\n");
	getch();
	fclose(data);

}

void log(int n)	//�齱��־��¼�ļ�
{
	int a;
	extern struct prize p;
	char(*pn)[20], (*gn)[20];
	pn = p.prize_name;
	gn = p.goods_name;
	FILE *fp;
	if ((fp = fopen("info.txt", "a")) == NULL)
	{
		printf("�޷���¼��־\n");
	}
	fputs(*(pn + n), fp);
	fputs(":", fp);
	fputs(*(gn + n), fp);
	fputs("\t��", fp);
	fprintf(fp, "%d", p.prize_people[n]);
	fputs("����\n\n", fp);
	fclose(fp);
}

void lognum(int i,int j,int n)	//����н����뵽�ı�
{
	int a;
	extern struct prize p;
	extern int tempnum[20][30];
	char(*pn)[20], (*gn)[20], *pp;
	pn = p.prize_name;
	pp = p.prize_people;
	FILE *fp;
	if ((fp = fopen("info.txt", "a")) == NULL)
	{
		printf("�޷���¼��־\n");
	}
	fprintf(fp, "%d ", tempnum[i][j]);
	fclose(fp);
}
logtime()
{
	FILE *fp;
	if (fp = fopen("info.txt", "a"))	//д�뵱ǰʱ�䵽��־�ļ�
	{
		time_t timeSec = time(NULL);	 //��ȡ1970.1.1����ǰ����time_t 
		struct tm * timeinfo = localtime(&timeSec);	//����TimeDate,��ת��Ϊ����ʱ��
		//struct tm * timeinfo = gmtime ( &timeSec );	 //����TimeDate,��ת��ΪGMʱ��
		fprintf(fp, "%s---------------------------------\n\n", asctime(timeinfo));
		fclose(fp);
	}
}