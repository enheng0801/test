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



//��ϵ����Ϣ�ṹ
typedef struct PeoInfo {
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char address[MAX_ADDRESS];
}PeoInfo;

//��̬
//ͨѶ¼�ṹ
//typedef struct Contact {
//	struct PeoInfo data[100];//100����ϵ�˵���Ϣ
//	int count;//��ǰͨѶ¼����ϵ�˵ĸ���
//}Contact;

//��̬
//ͨѶ¼�ṹ
typedef struct Contact {
	struct PeoInfo* data;
	int count;//��ǰͨѶ¼����ϵ�˵ĸ���
	int capacity;//��ǰ����
}Contact;

//��ʼ��ͨѶ¼
int InitContact(Contact*);

//��ӡͨѶ¼
void ShowContact(const Contact*);

//������ϵ��
void AddContact(Contact*);

//ɾ����ϵ��
void DelContact(Contact*);

//������ϵ����Ϣ
void EditContact(Contact*);

//������ϵ��
void SearchContact(Contact*);

//����
void SortContact(Contact*);

//�ͷſռ�
void DestoryContact(Contact*);

//���浽�ļ�
void SaveContact(const Contact*);