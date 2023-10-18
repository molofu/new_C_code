#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

#include<assert.h>	//assertÍ·ÎÄ¼þ

char* my_strcpy(char*dest,const char* src)
{
	//assert(dest);
	//assert(src);
	
	assert(dest && src);
	
	//int i = 0;
	//int j = 0;
	//while (source[i] != '\0')
	//{
	//	destination[j++] = source[i++];
	//}
	//destination[j] = source[i];
	
	char* ret = dest;
	
	//while (*src)
	//{
	//	*dest++ = *src++;
	//}
	//*dest++ = *src++;

	while (*dest++ = *src++)
	{
		;
	}

	return ret;
}

//×Ö·û´®¿½±´
int main()
{
	char c = 'A';
	printf("%d\n", c);
	char arr1[] = "abcedfg";
	char arr2[20] = { 0 };
	my_strcpy(arr2, arr1);
	
	printf("%s\n", arr2);

	return 0;
}


