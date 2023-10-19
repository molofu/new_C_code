#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include"contact.h"

void loadContact(contact* con)
{

	FILE* pfread = fopen("contact.txt", "rb");
	if (pfread == NULL)
	{
		perror("loadContact");
		return;
	}

	peopleInfo tmp = { 0 };
	while (fread(&tmp, sizeof(peopleInfo), 1, pfread))
	{
		checkCapacity(con);

		con->data[con->count] = tmp;
		con->count++;
	}

	fclose(pfread);
	pfread == NULL;
}

//静态版本
//void initContact(contact* con)
//{
//	assert(con);
//	con->count = 0;
//	memset(con, 0, sizeof(con->data));
//}

//动态版本
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

	//加载文件信息
	loadContact(con);

	return 0;
}

//void addContact(contact* con)
//{
//	assert(con);
//	if (con->count == 100)
//	{
//		printf("通讯录已满\n");
//		return;
//	}
//	printf("请输入要添加的联系人姓名：\n");
//	scanf("%s", con->data[con->count].name);
//	printf("请输入要添加的联系人年龄：\n");
//	scanf("%d", &con->data[con->count].age);
//	printf("请输入要添加的联系人性别：\n");
//	scanf("%s", con->data[con->count].sex);
//	printf("请输入要添加的联系人电话：\n");
//	scanf("%s", con->data[con->count].tele);
//	printf("请输入要添加的联系人地址：\n");
//	scanf("%s", con->data[con->count].address);
//
//	con->count++;
//	printf("添加成功！\n");
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
		//printf("扩容成功！\n");
	}
	
	return 0;
}

//动态版本
void addContact(contact* con)
{
	assert(con);
	
	checkCapacity(con);

	printf("请输入要添加的联系人姓名：\n");
	scanf("%s", con->data[con->count].name);
	printf("请输入要添加的联系人年龄：\n");
	scanf("%d", &con->data[con->count].age);
	printf("请输入要添加的联系人性别：\n");
	scanf("%s", con->data[con->count].sex);
	printf("请输入要添加的联系人电话：\n");
	scanf("%s", con->data[con->count].tele);
	printf("请输入要添加的联系人地址：\n");
	scanf("%s", con->data[con->count].address);

	con->count++;
	printf("添加成功！\n");


	system("pause");
	system("cls");
}

void showContact(const contact* con)
{
	assert(con);
	if (0 == con->count)
	{
		printf("通讯录为空\n");

		system("pause");
		system("cls");
		return;
	}
	//printf("姓名\t年龄\t性别\t电话\t地址\t\n");
	printf("%-10s\t%-5s\t%-5s\t%-12s\t%-20s\t\n", "姓名", "年龄", "性别", "电话", "地址");
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
		printf("通讯录为空\n");

		system("pause");
		system("cls");
		return;
	}
	printf("请输入想要查找的联系人姓名：\n");
	char find_name[20]={0};
	scanf("%s", find_name);

	int pos = find_by_name(con, find_name);
	if (pos == -1)
	{
		printf("未找到联系人\n");
	}
	else
	{
		printf("查找到联系人：\n");
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
	//		printf("查找到联系人：\n");
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
	//printf("未找到联系人");
	

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
		printf("通讯录为空\n");

		system("pause");
		system("cls");
		return;
	}
	printf("请输入想要删除的联系人姓名：\n");
	scanf("%s", del_name);
	int pos = find_by_name(con, del_name);
	if (-1 == pos)
	{
		printf("要删除的联系人不存在\n");
		return;
	}

	for (int i = pos; i < con->count-1; i++)
	{
		con->data[i] = con->data[i + 1];
	}
	con->count--;

	printf("删除成功！\n");

	system("pause");
	system("cls");
}

void modifyContact(contact* con)
{
	assert(con);
	char modify_name[20] = { 0 };
	if (0 == con->count)
	{
		printf("通讯录为空\n");

		system("pause");
		system("cls");
		return;
	}
	printf("请输入想要修改的联系人姓名：\n");
	scanf("%s", modify_name);

	int pos = find_by_name(con, modify_name);
	if (-1 == pos)
	{
		printf("要修改的联系人不存在\n");
		return;
	}

	printf("请输入要修改的联系人姓名：\n");
	scanf("%s", con->data[pos].name);
	printf("请输入要修改的联系人年龄：\n");
	scanf("%d", &con->data[pos].age);
	printf("请输入要修改的联系人性别：\n");
	scanf("%s", con->data[pos].sex);
	printf("请输入要修改的联系人电话：\n");
	scanf("%s", con->data[pos].tele);
	printf("请输入要修改的联系人地址：\n");
	scanf("%s", con->data[pos].address);

	printf("修改成功！\n");

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
		printf("通讯录为空\n");

		system("pause");
		system("cls");
		return;
	}

	qsort(con->data, con->count, sizeof(peopleInfo), cmp_by_name);
	printf("排序成功\n");

	system("pause");
	system("cls");

}

void saveContact(const contact* con)
{
	assert(con);
	if (0 == con->count)
	{
		//printf("通讯录为空\n");

		/*system("pause");
		system("cls");*/
		return;
	}
	FILE* pfwrite = fopen("contact.txt", "wb+");
	if (pfwrite == NULL)
	{
		perror("saveContact");
		return;
	}

	for (int i = 0; i < con->count; i++)
	{
		fwrite(con->data+i, sizeof(peopleInfo), 1,pfwrite);
	}

	fclose(pfwrite);
	pfwrite = NULL;
}