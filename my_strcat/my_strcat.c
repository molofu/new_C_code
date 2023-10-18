#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

#include<assert.h>

//模拟strcat函数
char* my_strcat(char* dest, const char* src)
{
	assert(dest && src);
	char* ret = dest;

	//int len = strlen(dest);	//最好不使用别人的函数

	//while (*src != '\0')
	//{
	//	*(dest + len) = *src;
	//	src++;
	//	dest++;
	//}

	//找到目标空间的末尾0的位置
	while (*dest != '\0')
	{
		dest++;
	}
	//拷贝字符
	//while (*src != '\0')
	//{
	//	*dest = *src;
	//	src++;
	//	dest++;
	//}

	//拷贝字符另一种实现
	while (*dest++ = *src++)			//等价于 *dest=*src; dest++;src++;		
	{									//同时作出了判断表达式是否为0
		;								//如果*src为0，最终表达式也为0，退出循环
	}

	return ret;
}


int main()
{
	char arr1[20] = "hello ";
	char arr2[] = "world";

	my_strcat(arr1, "hhh");
	my_strcat(arr1, arr2);

	printf("%s\n", arr1);


	return 0;
}