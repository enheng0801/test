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
			printf("增容成功\n");
		}
	}
}


//查找联系人
//按名字查
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

////静态
////初始化通讯录
//void InitContact(Contact* pc) {
//	assert(pc);
//	pc->count =  0 ;
//	memset(pc->data, 0, sizeof(pc->data));
//}

//动态
//初始化通讯录
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



//静态
////增加联系人
//void AddContact(Contact* pc) {
//	assert(pc);
//	if (pc->count == 100) {
//		printf("通讯录已满\n");
//		return;
//	}
//	printf("请输入联系人姓名:>");
//	scanf("%s", pc->data[pc->count].name);
//	printf("请输入联系人年龄:>");
//	scanf("%d", &(pc->data[pc->count].age));
//	printf("请输入联系人性别:>");
//	scanf("%s", pc->data[pc->count].sex);
//	printf("请输入联系人电话:>");
//	scanf("%s", pc->data[pc->count].tele);
//	printf("请输入联系人地址:>");
//	scanf("%s", pc->data[pc->count].address);
//	(pc->count)++;
//	printf("增加成功\n");
//}

//动态
//增加联系人
void AddContact(Contact* pc) {
	assert(pc);
	CheckCapacity(pc);
	printf("请输入联系人姓名:>");
	scanf("%s", pc->data[pc->count].name);
	printf("请输入联系人年龄:>");
	scanf("%d", &(pc->data[pc->count].age));
	printf("请输入联系人性别:>");
	scanf("%s", pc->data[pc->count].sex);
	printf("请输入联系人电话:>");
	scanf("%s", pc->data[pc->count].tele);
	printf("请输入联系人地址:>");
	scanf("%s", pc->data[pc->count].address);
	(pc->count)++;
	printf("增加成功\n");
}

//展示通讯录
void ShowContact(const Contact* pc) {
	assert(pc);
	int i = 0;
	printf("%-20s\t%-5s\t%-10s\t%-12s\t%-30s\n","姓名","年龄","性别","电话","地址");
	for (i = 0;i < pc->count;i++) {
		printf("%-20s\t%-5d\t%-10s\t%-12s\t%-30s\n", pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tele, pc->data[i].address);
	}
}

//删除联系人
void DelContact(Contact* pc) {
	assert(pc);
	char delname[20] = { 0 };
	printf("请输入要删除的联系人名字:>");
	scanf("%s", delname);
	int findid = 0;
	if ((findid = FindContact(pc, delname)) == -1) {
		printf("要删除的联系人不存在\n");
		return;
	}
	int i = 0;
	for (i = findid;i < pc->count-1;i++) {
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
}

//更改联系人信息
void EditContact(Contact*pc) {
	assert(pc);
	char delname[20] = { 0 };
	printf("请输入要更改的联系人名字:>");
	scanf("%s", delname);
	int findid = 0;
	if ((findid = FindContact(pc, delname)) == -1) {
		printf("要更改的联系人不存在\n");
		return;
	}
	printf("请输入联系人姓名:>");
	scanf("%s", pc->data[findid].name);
	printf("请输入联系人年龄:>");
	scanf("%d", &(pc->data[findid].age));
	printf("请输入联系人性别:>");
	scanf("%s", pc->data[findid].sex);
	printf("请输入联系人电话:>");
	scanf("%s", pc->data[findid].tele);
	printf("请输入联系人地址:>");
	scanf("%s", pc->data[findid].address);
}

//查找联系人
void SearchContact(Contact*pc) {
	assert(pc);
	char name[20] = { 0 };
	printf("请输入要查找的联系人名字:>");
	scanf("%s", name);
	int i = 0;
	if (-1 == (i = FindContact(pc, name))){
		printf("未找到该联系人\n");
		return;
	}
	printf("%-20s\t%-5s\t%-10s\t%-12s\t%-30s\n", "姓名", "年龄", "性别", "电话", "地址");
	printf("%-20s\t%-5d\t%-10s\t%-12s\t%-30s\n", pc->data[i].name, pc->data[i].age, pc->data[i].sex, pc->data[i].tele, pc->data[i].address);
}



//按名字排序
int cmp_name(const void* e1, const void* e2) {
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}
//排序
void SortContact(Contact* pc){
	assert(pc);
	qsort(pc->data, pc->count, sizeof(PeoInfo), cmp_name);
	printf("排序成功\n");
}

//释放申请的空间
void DestoryContact(Contact* pc) {
	assert(pc);
	free(pc->data);
	pc->data = NULL;
}

//保存到文件
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
