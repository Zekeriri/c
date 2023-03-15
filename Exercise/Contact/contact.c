#define _CRT_SECURE_NO_WARNINGS
#include "contact.h";

void InitContact(Contact* pc)
{
	assert(pc);
	pc->sz = 0;
	//calloc 可以初始化
	PeoInfo*ptr= (PeoInfo*)calloc(DEAFAULT_SZ,sizeof(PeoInfo) );
	if (ptr == NULL)
	{
		perror("InitContact::calloc");
		return;
	}
	pc->data = ptr;
	pc->capacity = DEAFAULT_SZ;

	LoadContact(&con);
	
}
void DestroyContact(Contact* pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->sz = 0;
	pc = NULL;
}
void check_capacity(Contact* pc)
{
	if (pc->sz == pc->capacity)
	{
		//增加容量
		PeoInfo*ptr= (PeoInfo*)relloc(pc->data, (pc->capacity + 2) * sizeof(PeoInfo));
		if (ptr == NULL)
		{
			perror("check_capacity::realloc");
			return;
		}
		pc->data = ptr;
		pc->capacity += INC_SZ;
		printf("increase successfully");
	}
}
void AddContact(Contact* pc)
{
	assert(pc);
	check_capacity(pc);
	
	//add one person
	printf("Please input name:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("Please input age:>");
	scanf("%d", &(pc->data[pc->sz].age));
	printf("Please input sex:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("Please input address:>");
	scanf("%s", pc->data[pc->sz].addr);
	printf("Please input telephone:>");
	scanf("%s", pc->data[pc->sz].tele);


	pc->sz++;
}
void ShowContact(const Contact* pc)
{
	assert(pc);
	printf("%-10s\t%-5s\t%-10s\t%-10s\t%-10s\n", "name", "age", "sex", "address", "telephone");
	for (int i = 0; i < pc->sz; i++)
	{
		printf("%-10s\t%-5d\t%-10s\t%-10s\t%-10s\n",
			pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].addr,
			pc->data[i].tele);
	}
}
void DelContact(Contact* pc)
{
	assert(pc);
	char name[NAME_MAX] = { 0 };
	if (pc->sz == 0)
	{
		printf("is NUll\n");
		return;
	}


	printf("please enter the name you want to delete:>");
	scanf("%s", name);


	int ret = FindByName(&pc, name);
	if (-1 == ret)
	{
		printf("is not exist");
		return;
	}
	int del = ret;


	//delete
	for (int i = del; i < pc->sz - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("delete successful\n");
}
int FindByName(const Contact* pc, char* name)
{
	assert(pc);
	for (int i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}
void SearchContact(const Contact* pc)
{
	assert(pc);
	char name[NAME_MAX] = { 0 };
	printf("please input the name you want to search:>");
	scanf("%s", name);
	int ret = FindByName(pc, name);
	if (-1 == ret)
	{
		printf("is not exist");
		return;
	}
	printf("%-10s\t%-5s\t%-10s\t%-10s\t%-10s\n", "name", "age", "sex", "address", "telephone");
	printf("%-10s\t%-5d\t%-10s\t%-10s\t%-10s\n",
		pc->data[ret].name,
		pc->data[ret].age,
		pc->data[ret].sex,
		pc->data[ret].addr,
		pc->data[ret].tele);
}
void ModifyContact(Contact* pc)
{
	assert(pc);
	char name[NAME_MAX] = { 0 };
	printf("please input the name you want to modify:>");
	scanf("%s", name);
	int ret = FindByName(pc, name);
	if (-1 == ret)
	{
		printf("is not exist");
		return;
	}


	printf("Please input name:>");
	scanf("%s", pc->data[ret].name);
	printf("Please input age:>");
	scanf("%d", &(pc->data[ret].age));
	printf("Please input sex:>");
	scanf("%s", pc->data[ret].sex);
	printf("Please input address:>");
	scanf("%s", pc->data[ret].addr);
	printf("Please input telephone:>");
	scanf("%s", pc->data[ret].tele);
	printf("Modify successfully!\n");
}
void SaveContact(Contact* pc)
{
	FILE*pf=fopen("contact.txt", "wb");
	if (NULL == pf)
	{
		perror("SaveContact");
	}
	else
	{
		fclose(pf);
		pf = NULL;
	}
	printf("save file successfully\n");
}
void LoadContact(Contact* pc)
{
	FILE* pf = fopen("contact.txt", "rb");
	if (pf == NULL)
	{
		perror("LoadContact");
	}
	else
	{
		PeoInfo tmp={0};
		int i = 0;
		while (fread(&tmp, sizeof(PeoInfo), 1, pf))
		{
			check_capacity(pc);
			pc->data[i] = tmp;
			pc->sz++;
			i++;
		}
		fclose(pf);
		pf = NULL;
	}
}