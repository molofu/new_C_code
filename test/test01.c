#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)

#include <stdio.h>
struct str {
    int len;
    char s[0];
};

struct foo {
    struct str* a;
};

int main(int argc, char** argv) {
    struct foo f = { 0 };       //��ֵΪ0  ��ָ��a������Ϊ0 ��ָ����0��ַ
    if (f.a->s) {           //aָ���s �����������ַ ƫ����һ��len Ϊ4;��Ϊ0
        printf(f.a->s);     //printf(��ַ) �����ӡ��ַ������ �ַ�����ʽ 
                            //���� printf("hello world") ����ʱ��ַΪ4 �����޷���Ȩ�޵Ŀռ�
        
                            //ֻ����Ȩ�޷��ʴ˵�ַ�����ݣ����Կ��Դ�ӡ�õ�ַ
        
        printf("%x\n", &f.a->len);      
    }
    return 0;
}