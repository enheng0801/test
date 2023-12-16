#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

void CheckCapacity(Contact* pc) {
	if (pc->count == pc->capacity) {
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, (pc->capacity + ADD_SZ) * sizeof(PeoInfo));
		if (ptr == NULL) {
			perror("CheckCapacity");
			return;
		}
		else {
			pc->data = ptr;
			pc->capacity += ADD_SZ;
			printf("���ݳɹ�\n");
		}
	}
}


//������ϵ��
//�����ֲ�
int FindContact(Contact* pc, char name[]) {
	assert(pc);
	int i = 0;
	for (i = 0;i < pc->count;i++) {
		if (strcmp(name, pc->data[i].name) == 0) {
			return i;
		}
	}
	return -1;
}

void LoadContact(Contact* pc) {
	FILE* pfr = fopen("test.txt", "rb");
	if (pfr == NULL) {
		perror("InitContact");
		return;
	}
	PeoInfo tmp = { 0 };
	while ( fread(&tmp, sizeof(PeoInfo), 1, pfr) == 1 ) {
		CheckCapacity(pc);
		pc->data[pc->count] = tmp;
		pc->count++;
	}
	fclose(pfr);
	pfr = NULL;
}

////��̬
////��ʼ��ͨѶ¼
//void InitContact(Contact* pc) {
//	assert(pc);
//	pc->count =  0 ;
//	memset(pc->data, 0, sizeof(pc->data));
//}

//��̬
//��ʼ��ͨѶ¼
int InitContact(Contact* pc) {
	assert(pc);
	pc->count =  0 ;
	pc->data = (PeoInfo*)calloc(DEFAULT_SZ, sizeof(PeoInfo));
	if (pc->data == NULL) {
		perror("InitContact");
		return 1;
	}
	pc->capacity = DEFAULT_SZ;
	LoadContact(pc);
	return 0;
}



//��̬
////������ϵ��
//void AddContact(Contact* pc) {
//	assert(pc);
//	if (pc->count == 100) {
//		printf("ͨѶ¼����\n");
//		return;
//	}
//	printf("��������ϵ������:>");
//	scanf("%s", pc->data[pc->count].name);
//	printf("��������ϵ������:>");
//	scanf("%d", &(pc->data[pc->count].age));
//	printf("��������ϵ���Ա�:>");
//	scanf("%s", pc->data[pc->count].sex);
//	printf("��������ϵ�˵绰:>");
//	scanf("%s", pc->data[pc->count].tele);
//	printf("��������ϵ�˵�ַ:>");
//	scanf("%s", pc->data[pc->count].address);
//	(pc->count)++;
//	printf("���ӳɹ�\n");
//}

//��̬
//������ϵ��
void AddContact(Contact* pc) {
	assert(pc);
	CheckCapacity(pc);
	printf("��������ϵ������:>");
	scanf("%s", pc->data[pc->count].name);
	printf("��������ϵ������:>");
	scanf("%d", &(pc->data[pc->count].age));
	printf("��������ϵ���Ա�:>");
	scanf("%s", pc->data[pc->count].sex);
	printf("��������ϵ�˵绰:>");
	scanf("%s", pc->data[pc->count].tele);
	printf("��������ϵ�˵�ַ:>");
	scanf("%s", pc->data[pc->count].address);
	(pc->count)++;
	printf("���ӳɹ�\n");
}

//չʾͨѶ¼
void ShowContact(const Contact* pc) {
	assert(pc);
	int i = 0;
	printf("%-20s\t%-5s\t%-10s\t%-12s\t%-30s\n","����","����","�Ա�","�绰","��ַ");
	for (i = 0;i < pc->count;i++) {
		printf("%-20s\t%-5d\t%-10s\t%-12s\t%-30s\n", pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tele, pc->data[i].address);
	}
}

//ɾ����ϵ��
void DelContact(Contact* pc) {
	assert(pc);
	char delname[20] = { 0 };
	printf("������Ҫɾ������ϵ������:>");
	scanf("%s", delname);
	int findid = 0;
	if ((findid = FindContact(pc, delname)) == -1) {
		printf("Ҫɾ������ϵ�˲�����\n");
		return;
	}
	int i = 0;
	for (i = findid;i < pc->count-1;i++) {
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
}

//������ϵ����Ϣ
void EditContact(Contact*pc) {
	assert(pc);
	char delname[20] = { 0 };
	printf("������Ҫ���ĵ���ϵ������:>");
	scanf("%s", delname);
	int findid = 0;
	if ((findid = FindContact(pc, delname)) == -1) {
		printf("Ҫ���ĵ���ϵ�˲�����\n");
		return;
	}
	printf("��������ϵ������:>");
	scanf("%s", pc->data[findid].name);
	printf("��������ϵ������:>");
	scanf("%d", &(pc->data[findid].age));
	printf("��������ϵ���Ա�:>");
	scanf("%s", pc->data[findid].sex);
	printf("��������ϵ�˵绰:>");
	scanf("%s", pc->data[findid].tele);
	printf("��������ϵ�˵�ַ:>");
	scanf("%s", pc->data[findid].address);
}

//������ϵ��
void SearchContact(Contact*pc) {
	assert(pc);
	char name[20] = { 0 };
	printf("������Ҫ���ҵ���ϵ������:>");
	scanf("%s", name);
	int i = 0;
	if (-1 == (i = FindContact(pc, name))){
		printf("δ�ҵ�����ϵ��\n");
		return;
	}
	printf("%-20s\t%-5s\t%-10s\t%-12s\t%-30s\n", "����", "����", "�Ա�", "�绰", "��ַ");
	printf("%-20s\t%-5d\t%-10s\t%-12s\t%-30s\n", pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tele, pc->data[i].address);
}



//����������
int cmp_name(const void* e1, const void* e2) {
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}
//����
void SortContact(Contact* pc){
	assert(pc);
	qsort(pc->data, pc->count, sizeof(PeoInfo), cmp_name);
	printf("����ɹ�\n");
}

//�ͷ�����Ŀռ�
void DestoryContact(Contact* pc) {
	assert(pc);
	free(pc->data);
	pc->data = NULL;
}

//���浽�ļ�
void SaveContact(const Contact* pc) {
	FILE* pfw = fopen("test.txt", "wb");
	if (pfw == NULL) {
		perror("SaveContact");
		return;
	}
	fwrite(pc->data, sizeof(PeoInfo), pc->count, pfw);

	fclose(pfw);
	pfw = NULL;
}
