#pragma once
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDRESS 30
#define ADD_SZ 2
#define DEFAULT_SZ 3



//联系人信息结构
typedef struct PeoInfo {
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char address[MAX_ADDRESS];
}PeoInfo;

//静态
//通讯录结构
//typedef struct Contact {
//	struct PeoInfo data[100];//100个联系人的信息
//	int count;//当前通讯录里联系人的个数
//}Contact;

//动态
//通讯录结构
typedef struct Contact {
	struct PeoInfo* data;
	int count;//当前通讯录里联系人的个数
	int capacity;//当前容量
}Contact;

//初始化通讯录
int InitContact(Contact*);

//打印通讯录
void ShowContact(const Contact*);

//增加联系人
void AddContact(Contact*);

//删除联系人
void DelContact(Contact*);

//更改联系人信息
void EditContact(Contact*);

//查找联系人
void SearchContact(Contact*);

//排序
void SortContact(Contact*);

//释放空间
void DestoryContact(Contact*);

//保存到文件
void SaveContact(const Contact*);