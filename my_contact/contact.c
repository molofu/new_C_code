#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include"contact.h"

//��̬�汾
//void initContact(contact* con)
//{
//	assert(con);
//	con->count = 0;
//	memset(con, 0, sizeof(con->data));
//}

//��̬�汾
int initContact(contact* con)
{
	assert(con);
	con->count = 0;
	
	con->data=(peopleInfo*)calloc(3, sizeof(peopleInfo));
	
	if (con->data == NULL)
	{
		printf("initContact::%s\n", strerror(errno));
		return 1;
	}
	con->capacity = 3;
	return 0;
}

//void addContact(contact* con)
//{
//	assert(con);
//	if (con->count == 100)
//	{
//		printf("ͨѶ¼����\n");
//		return;
//	}
//	printf("������Ҫ��ӵ���ϵ��������\n");
//	scanf("%s", con->data[con->count].name);
//	printf("������Ҫ��ӵ���ϵ�����䣺\n");
//	scanf("%d", &con->data[con->count].age);
//	printf("������Ҫ��ӵ���ϵ���Ա�\n");
//	scanf("%s", con->data[con->count].sex);
//	printf("������Ҫ��ӵ���ϵ�˵绰��\n");
//	scanf("%s", con->data[con->count].tele);
//	printf("������Ҫ��ӵ���ϵ�˵�ַ��\n");
//	scanf("%s", con->data[con->count].address);
//
//	con->count++;
//	printf("��ӳɹ���\n");
//	system("pause");
//	system("cls");
//}

int checkCapacity(contact* con)
{
	if (con->capacity == con->count)
	{
		peopleInfo* ptr=(peopleInfo*)realloc(con->data, (con->capacity + 2) * sizeof(peopleInfo));
		if (ptr == NULL)
		{
			printf("checkContact::%s\n", strerror(errno));
			return 1;
		}
		con->data = ptr;
		con->capacity += 2;
		printf("���ݳɹ���\n");
	}
	
	return 0;
}

//��̬�汾
void addContact(contact* con)
{
	assert(con);
	
	checkCapacity(con);

	printf("������Ҫ��ӵ���ϵ��������\n");
	scanf("%s", con->data[con->count].name);
	printf("������Ҫ��ӵ���ϵ�����䣺\n");
	scanf("%d", &con->data[con->count].age);
	printf("������Ҫ��ӵ���ϵ���Ա�\n");
	scanf("%s", con->data[con->count].sex);
	printf("������Ҫ��ӵ���ϵ�˵绰��\n");
	scanf("%s", con->data[con->count].tele);
	printf("������Ҫ��ӵ���ϵ�˵�ַ��\n");
	scanf("%s", con->data[con->count].address);

	con->count++;
	printf("��ӳɹ���\n");
	system("pause");
	system("cls");
}

void showContact(const contact* con)
{
	assert(con);
	if (0 == con->count)
	{
		printf("ͨѶ¼Ϊ��\n");

		system("pause");
		system("cls");
		return;
	}
	//printf("����\t����\t�Ա�\t�绰\t��ַ\t\n");
	printf("%-10s\t%-5s\t%-5s\t%-12s\t%-20s\t\n", "����", "����", "�Ա�", "�绰", "��ַ");
	for (int i = 0; i < con->count; i++)
	{		
		printf("%-8s\t%-5d\t%-5s\t%-15s\t%-20s\t\n",
			con->data[i].name, 
			con->data[i].age, 
			con->data[i].sex, 
			con->data[i].tele, 
			con->data[i].address);
	}

	system("pause");
	system("cls");
}

static int find_by_name(const contact* con,const char* find_name)
{
	assert(con && find_name);
	for (int i = 0; i < con->count; i++)
	{
		if (0==strcmp(find_name, con->data[i].name))
			return i;
	}
	return -1;
}

void findContact(const contact* con)
{
	assert(con);
	if (0 == con->count)
	{
		printf("ͨѶ¼Ϊ��\n");

		system("pause");
		system("cls");
		return;
	}
	printf("��������Ҫ���ҵ���ϵ��������\n");
	char find_name[20]={0};
	scanf("%s", find_name);

	int pos = find_by_name(con, find_name);
	if (pos == -1)
	{
		printf("δ�ҵ���ϵ��\n");
	}
	else
	{
		printf("���ҵ���ϵ�ˣ�\n");
		printf("%-8s\t%-5d\t%-5s\t%-15s\t%-20s\t\n",
			con->data[pos].name,
			con->data[pos].age,
			con->data[pos].sex,
			con->data[pos].tele,
			con->data[pos].address);
	}

	//for (int i = 0; i < con->count; i++)
	//{
	//	if (strcmp(find_name, con->data[i].name) == 0)
	//	{
	//		printf("���ҵ���ϵ�ˣ�\n");
	//		printf("%-8s\t%-5d\t%-5s\t%-15s\t%-20s\t\n",
	//			con->data[i].name,
	//			con->data[i].age,
	//			con->data[i].sex,
	//			con->data[i].tele,
	//			con->data[i].address);

	//		system("pause");
	//		system("cls");
	//		return i;
	//	}
	//}
	//printf("δ�ҵ���ϵ��");
	

	system("pause");
	system("cls");

	//return -1;
}


void delContact(contact* con)
{
	assert(con);
	char del_name[20]={0};
	if (0 == con->count)
	{
		printf("ͨѶ¼Ϊ��\n");

		system("pause");
		system("cls");
		return;
	}
	printf("��������Ҫɾ������ϵ��������\n");
	scanf("%s", del_name);
	int pos = find_by_name(con, del_name);
	if (-1 == pos)
	{
		printf("Ҫɾ������ϵ�˲�����\n");
		return;
	}

	for (int i = pos; i < con->count-1; i++)
	{
		con->data[i] = con->data[i + 1];
	}
	con->count--;

	printf("ɾ���ɹ���\n");

	system("pause");
	system("cls");
}

void modifyContact(contact* con)
{
	assert(con);
	char modify_name[20] = { 0 };
	if (0 == con->count)
	{
		printf("ͨѶ¼Ϊ��\n");

		system("pause");
		system("cls");
		return;
	}
	printf("��������Ҫ�޸ĵ���ϵ��������\n");
	scanf("%s", modify_name);

	int pos = find_by_name(con, modify_name);
	if (-1 == pos)
	{
		printf("Ҫ�޸ĵ���ϵ�˲�����\n");
		return;
	}

	printf("������Ҫ�޸ĵ���ϵ��������\n");
	scanf("%s", con->data[pos].name);
	printf("������Ҫ�޸ĵ���ϵ�����䣺\n");
	scanf("%d", &con->data[pos].age);
	printf("������Ҫ�޸ĵ���ϵ���Ա�\n");
	scanf("%s", con->data[pos].sex);
	printf("������Ҫ�޸ĵ���ϵ�˵绰��\n");
	scanf("%s", con->data[pos].tele);
	printf("������Ҫ�޸ĵ���ϵ�˵�ַ��\n");
	scanf("%s", con->data[pos].address);

	printf("�޸ĳɹ���\n");

	system("pause");
	system("cls");
}

int cmp_by_name(const void* str1, const void* str2)
{
	return strcmp(((peopleInfo*)str1)->name, ((peopleInfo*)str2)->name);
}

void sortContact(contact* con)
{
	assert(con);
	if (0 == con->count)
	{
		printf("ͨѶ¼Ϊ��\n");

		system("pause");
		system("cls");
		return;
	}

	qsort(con->data, con->count, sizeof(peopleInfo), cmp_by_name);
	printf("����ɹ�\n");

	system("pause");
	system("cls");

}