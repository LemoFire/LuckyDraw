#include<stdio.h>
#include<windows.h>
#include"struct.h"
void readinfo()	//读取上次奖品定义数据的函数
{
	void main();
	FILE *data;
	if ((data = fopen("info.dat", "rb")) == NULL)
	{
		printf("无法打开数据文件\n");
		exit(0);
	}
	if (fread(&p, sizeof (struct prize), 1, data) != 1)
	{
		printf("读取数据错误\n");
		getch();
		system("cls");
		main();
	}fclose(data);
	void pnumcheck(int n);
	pnumcheck(0);
	//重新记录当前抽奖人数
	extern int definitionflag;
	definitionflag = 1;	//标记为以定义过奖品
	printf("\n奖品信息录入完成，录入信息保存在当前目录下，按任意键返回主菜单\n\n");
	getch();
}

void writeinfo()	//写入当前奖品定义数组数据到文件
{
	FILE *data;
	if ((data = fopen("info.dat", "wb")) == NULL)
	{
		printf("无法打开数据文件\n");
		getch();
		exit(0);
	}
	if (fwrite(&p, sizeof (struct prize), 1, data) != 1)
		printf("无法写入数据到磁盘\n");
	getch();
	fclose(data);

}

void log(int n)	//抽奖日志记录文件
{
	int a;
	extern struct prize p;
	char(*pn)[20], (*gn)[20];
	pn = p.prize_name;
	gn = p.goods_name;
	FILE *fp;
	if ((fp = fopen("info.txt", "a")) == NULL)
	{
		printf("无法记录日志\n");
	}
	fputs(*(pn + n), fp);
	fputs(":", fp);
	fputs(*(gn + n), fp);
	fputs("\t共", fp);
	fprintf(fp, "%d", p.prize_people[n]);
	fputs("名；\n\n", fp);
	fclose(fp);
}

void lognum(int i,int j,int n)	//输出中奖号码到文本
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
		printf("无法记录日志\n");
	}
	fprintf(fp, "%d ", tempnum[i][j]);
	fclose(fp);
}
logtime()
{
	FILE *fp;
	if (fp = fopen("info.txt", "a"))	//写入当前时间到日志文件
	{
		time_t timeSec = time(NULL);	 //获取1970.1.1至当前秒数time_t 
		struct tm * timeinfo = localtime(&timeSec);	//创建TimeDate,并转化为当地时间
		//struct tm * timeinfo = gmtime ( &timeSec );	 //创建TimeDate,并转化为GM时间
		fprintf(fp, "%s---------------------------------\n\n", asctime(timeinfo));
		fclose(fp);
	}
}