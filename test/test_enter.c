#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include<stdlib.h>
void main()
{

	int x = 0;
	scanf("%d\n", &x);
	printf("���x:%d\n", x);
	fflush(stdin);		//fflush�ڸ߰汾vs����ʧЧ
	system("pause");
	return 0;
}