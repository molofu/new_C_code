#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>

//Ä£Äâmemcpyº¯Êý
void* my_memcpy(void* dest, const void* src,size_t num)
{
	assert(dest && src);

	void* p = dest;
	
	while (num--)
	{
		*(char*)dest = *(char*)src;
		(char*)dest += 1;
		(char*)src += 1;
	}
	return p;
}

int main()
{
	int arr1[20] = { 1,2,3,4,5 };
	int arr2[] = { 6,7,8,9,10 };

	my_memcpy(arr1+5, arr2,20);

	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arr1[i]);
	}

	return 0;
}