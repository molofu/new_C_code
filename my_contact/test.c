#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include"contact.h"

void menu()
{
	printf("*******************************\n");
	printf("****  1.add      2.del     ****\n");
	printf("****  3.find     4.modify  ****\n");
	printf("****  5.show     6.sort    ****\n");
	printf("****  0.exit               ****\n");
	printf("*******************************\n");
}

int main()
{
	int input = 0;	
	contact con;

	initContact(&con);

	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			addContact(&con);
			break;
		case 2:
			delContact(&con);
			break;
		case 3:
			findContact(&con);
			break;
		case 4:
			modifyContact(&con);
			break;
		case 5:
			showContact(&con);
			break;
		case 6:
			sortContact(&con);
			break;
		case 0:
			printf("�˳�ͨѶ¼\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}

	} while (input);


	return 0;
}