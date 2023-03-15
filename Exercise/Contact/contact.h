#pragma once
#include <string.h>
#include <stdio.h>
#include <assert.h>
#define MAX 100
#define NAME_MAX 20
#define SEX_MAX 6
#define ADDR_MAX 30
#define TELE_MAX 12
#define DEAFAULT_SZ 3
#define INC_SZ 2
typedef struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char addr[ADDR_MAX];
	char tele[TELE_MAX];
}PeoInfo;
typedef struct Contact
{
	PeoInfo* data;
	int sz;
	int capacity;
}Contact;
void InitContact(Contact* pc);
void AddContact(Contact* pc);
void ShowContact(const Contact* pc);
void DelContact(Contact* pc);
int FindByName(const Contact* pc, char* name);
void SearchContact(const Contact* pc);
void ModifyContact(Contact* pc);
void DestroyContact(Contact* pc);
void SaveContact(Contact* pc);
void LoadContact(Contact* pc);