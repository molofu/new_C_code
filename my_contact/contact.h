#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
//#include<errors.h>
#include<errno.h>

typedef struct peopleInfo
{
	char name[20];
	int age;
	char sex[5];
	char tele[12];
	char address[30];
}peopleInfo;

//��̬�汾
//typedef struct contact
//{
//	peopleInfo data[100];
//	int count;
//}contact;

//��̬�汾
typedef struct contact
{
	peopleInfo* data;
	int count;
	int capacity;
}contact;

//��̬
//void initContact(contact* con);

//��̬�汾
int initContact(contact* con);

void addContact(contact* con);

void showContact(const contact* con);

void findContact(const contact* con);

void delContact(contact* con);

void modifyContact(contact* con);

void sortContact(contact* con);