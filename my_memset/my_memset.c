#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>

//模拟memset函数
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

	my_memset(arr, 'x', 5);		//注意是 一个字节一个字节的更改数据 

	printf("%s\n", arr);

	return 0;
}