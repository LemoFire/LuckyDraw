#include<stdio.h>
#include<conio.h>
#include <windows.h>
int definitionflag,pnum;	//ȫ�ֶ���definitionflag���Ƿ������Ʒ��pnum���齱����
void main()
{
	void prize_inf_input();	//���影Ʒ�ĺ���
	void welcome();
	void readinfo();
	void start();	//�齱����
	int choose;
	extern int definitionflag;
	welcome();	//��ӭ����
	scanf("%d",&choose);
	if (choose == 1)prize_inf_input();	//1����齱 2��ʼ�齱
	else {
		if (choose == 3)
		{ 
			readinfo();
			system("cls");
			main();
		}
			else if (choose == 2)
				{
					if (definitionflag != 1)	//δ���影Ʒ�����ý���齱����
					{
						printf("����δ�Խ�Ʒ���ж��壬�밴������������룡");
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
				printf("\n��������밴�������������");
				getch();
				system("cls");
				main();
			} 
		}
}