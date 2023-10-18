#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

#include<assert.h>
//模拟strlen函数

//计数器方法
size_t my_strlen(const char* str)
{
	assert(str);
	size_t count = 0;
	while (*str != '\0')
	{
		str++;
		count++;
	}
	return count;
}

//指针减指针法
size_t my_strlen2(const char* str)
{
	assert(str);
	char* p = str;
	while (*str != '\0')
	{
		str++;
	}

	size_t ret = str - p;
	
	return ret;
}


int main()
{
	char arr[] = "abcdefghi";
	size_t ret = my_strlen(arr);
	//size_t ret = my_strlen2(arr);

	printf("%zu\n", ret);
	return 0;
}