#include<stdio.h>
#include<conio.h>
#include <windows.h>
int definitionflag,pnum;	//全局定义definitionflag：是否定义过奖品；pnum：抽奖人数
void main()
{
	void prize_inf_input();	//定义奖品的函数
	void welcome();
	void readinfo();
	void start();	//抽奖函数
	int choose;
	extern int definitionflag;
	welcome();	//欢迎界面
	scanf("%d",&choose);
	if (choose == 1)prize_inf_input();	//1定义抽奖 2开始抽奖
	else {
		if (choose == 3)
		{ 
			readinfo();
			system("cls");
			main();
		}
			else if (choose == 2)
				{
					if (definitionflag != 1)	//未定义奖品，不得进入抽奖环节
					{
						printf("您还未对奖品进行定义，请按任意键重新输入！");
						getch();
						system("cls");
						main();
					}
					else
					{
						start();
					}
				}
			else
			{
				printf("\n输入错误，请按任意键重新输入");
				getch();
				system("cls");
				main();
			} 
		}
}