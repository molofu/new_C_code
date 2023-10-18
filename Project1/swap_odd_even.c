#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//将奇数放数组前面，偶数都放到数组后面
void swap_odd_even(int* arr, int length)
{
	int left = 0;
	int right = length - 1;

	while (left < right)
	{
		//从左起找偶数 
		while ((left<right)&&arr[left] % 2)		//防止内层left一直++ 导致大于right 出现数组越界
		{
			left++;
		}
		
		//从右起找奇数
		while ((left < right) && arr[right] % 2 == 0)
		{
			right--;
		}
		
		//找到后交换奇数和偶数
		if (left < right)
		{
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			left++;
			right--;
		}
	}
}

int main()
{
	int arr[10]={0};
	int length = sizeof(arr) / sizeof(arr[0]);
	//输入数组
	for (int i = 0; i < length; i++)
	{
		scanf("%d", arr + i);
	}

	//交换奇数偶数顺序
	swap_odd_even(arr, length);

	//输出数组
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}