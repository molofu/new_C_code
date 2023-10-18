#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
int main()
{
	int arr1[10] = { 0 };
	int arr2[10] = { 0 };
	int arr3[20] = { 0 };
	int n = 0;
	int m = 0;
	int j = 0;
	int k = 0;
	int r = 0;		//C89以后 变量已经可以不定义在开头了
	scanf("%d", &n);
	scanf("%d", &m);
	while (getchar() != '\n')		//清空缓存区 防止多输入的数据被直接读到下一个scanf中
	{
		;
	}
	//fflush(stdin);		//清空缓存区，在这里不起作用，？？？未知原因
	for (int i = 0; i < n; i++)
	{
		//fflush(stdin);
		scanf("%d", arr1 + i);
		
	}
	for (int i = 0; i < m; i++)
	{
		//fflush(stdin);
		scanf("%d", arr2 + i);
		
	}
	
	while (j < n && k < m)
	{
		
		if (arr1[j] < arr2[k])
		{
			arr3[r++] = arr1[j++];
		}
		else
		{
			arr3[r++] = arr2[k++];
		}
	}
	if (j < n)
	{
		for (; j < n; j++)
		{
			arr3[r++] = arr1[j];
		}
	}
	else
	{
		for (; k < m; k++)
		{
			arr3[r++] = arr2[k];
		}
	}
	
	for (int i = 0; i < n + m; i++)
	{
		printf("%d ", arr3[i]);
	}
	

	return 0;
}


