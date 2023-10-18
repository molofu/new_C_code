#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>

//ģ��memset����
void* my_memset(void* p, int value, size_t num)
{
	assert(p);
	char* ret = p;
	while (num--)
	{
		*(char*)p = value;
		(char*)p += 1;
	}
	
	return ret;
}

int main()
{
	char arr[] = "hello world";

	my_memset(arr, 'x', 5);		//ע���� һ���ֽ�һ���ֽڵĸ������� 

	printf("%s\n", arr);

	return 0;
}