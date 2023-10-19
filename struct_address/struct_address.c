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
    struct foo f = { 0 };       //赋值为0  ，指针a的内容为0 ，指向了0地址
    if (f.a->s) {           //a指向的s 数组名代表地址 偏移了一个len 为4;不为0
       // printf(f.a->s);     //printf(地址) 代表打印地址的内容 字符串格式 
                            //类似 printf("hello world") 而此时地址为4 属于无访问权限的空间

                            //只是无权限访问此地址的内容，但仍可以打印该地址

        printf("%x\n", &f.a->len);
    }
    return 0;
}