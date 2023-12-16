#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"



void menu() {
	printf("***************************************\n");
	printf("*****1.增加联系人     2.删除联系人*****\n");
	printf("*****3.更改联系人信息 4.查找联系人*****\n");
	printf("*****5.展示通讯录     6.排序      *****\n");
	printf("*****0.退出通讯录                 *****\n");
	printf("***************************************\n");
}
int main() {
	int input = 0; 
	Contact con;
	//初始化通讯录
	InitContact(&con);
	do {
		//菜单
		menu();
		printf("请输入选项:>\n");
		scanf("%d", &input);
		switch (input) {
		case 1:
			AddContact(&con);
			break;
		case 2:
			DelContact(&con);
			break;
		case 3:
			EditContact(&con);
			break;
		case 4:
			SearchContact(&con);
			break;
		case 5:
			ShowContact(&con);
			break;
		case 6:
			SortContact(&con);
			break;
		case 0:
			SaveContact(&con);
			DestoryContact(&con);
			break;
		default:
			printf("输入错误选项\n");
			break;
		}

	} while (input);
	return 0;
}