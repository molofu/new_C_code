#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include<stdlib.h>
void main()
{

	int x = 0;
	scanf("%d\n", &x);
	printf("输出x:%d\n", x);
	fflush(stdin);		//fflush在高版本vs中已失效
	system("pause");
	return 0;
}