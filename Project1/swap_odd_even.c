#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

//������������ǰ�棬ż�����ŵ��������
void swap_odd_even(int* arr, int length)
{
	int left = 0;
	int right = length - 1;

	while (left < right)
	{
		//��������ż�� 
		while ((left<right)&&arr[left] % 2)		//��ֹ�ڲ�leftһֱ++ ���´���right ��������Խ��
		{
			left++;
		}
		
		//������������
		while ((left < right) && arr[right] % 2 == 0)
		{
			right--;
		}
		
		//�ҵ��󽻻�������ż��
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
	//��������
	for (int i = 0; i < length; i++)
	{
		scanf("%d", arr + i);
	}

	//��������ż��˳��
	swap_odd_even(arr, length);

	//�������
	for (int i = 0; i < length; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}