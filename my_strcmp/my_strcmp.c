#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

#include<assert.h>

//Ä£Äâstrcmpº¯Êý
int my_strcmp(const char* arr1, const char* arr2)
{
	assert(arr1 && arr2);
	//while (*arr1 || *arr2)
	//{
	//	if (*arr1 > *arr2)
	//	{
	//		return 1;
	//	}
	//	else if (*arr1 < *arr2)
	//	{
	//		return -1;
	//	}
	//	else
	//	{
	//		arr1++;
	//		arr2++;
	//	}
	//}

	while (*arr1 == *arr2)
	{
		if (*arr1 == '\0')
		{
			return 0;
		}
			
		arr1++;
		arr2++;
	}
	
	return (*arr1 - *arr2);
}

int main()
{
	char arr1[] = "abcf";
	char arr2[] = "abcd";

	int ret = my_strcmp(arr1, arr2);


	if (ret < 0)
		printf("<");
	else if (ret > 0)
		printf(">");
	else
		printf("==");

	return 0;
}