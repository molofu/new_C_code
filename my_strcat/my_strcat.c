#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

#include<assert.h>

//ģ��strcat����
char* my_strcat(char* dest, const char* src)
{
	assert(dest && src);
	char* ret = dest;

	//int len = strlen(dest);	//��ò�ʹ�ñ��˵ĺ���

	//while (*src != '\0')
	//{
	//	*(dest + len) = *src;
	//	src++;
	//	dest++;
	//}

	//�ҵ�Ŀ��ռ��ĩβ0��λ��
	while (*dest != '\0')
	{
		dest++;
	}
	//�����ַ�
	//while (*src != '\0')
	//{
	//	*dest = *src;
	//	src++;
	//	dest++;
	//}

	//�����ַ���һ��ʵ��
	while (*dest++ = *src++)			//�ȼ��� *dest=*src; dest++;src++;		
	{									//ͬʱ�������жϱ��ʽ�Ƿ�Ϊ0
		;								//���*srcΪ0�����ձ��ʽҲΪ0���˳�ѭ��
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