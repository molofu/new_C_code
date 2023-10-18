#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

#include<assert.h>

//ģ��memmove����

void* my_memmove(void* dest, const void* src, size_t num)
{
	assert(dest && src);
	void* ret = dest;
	if (dest < src)			//��ǰ��󿽱�
	{
		while (num--)
		{
			*(char*)dest = *(char*)src;
			(char*)dest += 1;
			(char*)src += 1;
		}
	}
	else	//�Ӻ���ǰ���������ܵ���˵ �ص���Ҫ�ȿ����ٿ������ص�����ƾ�˼���ȷ��������˳��
	{
		while (num--)
		{
			*((char*)dest+num) = *((char*)src+num);
		}
	}
	return ret;
}

int main()
{
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };

	my_memmove(arr, arr + 4, 20);

	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arr[i]);
	}

	return 0;
}