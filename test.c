#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"



void menu() {
	printf("***************************************\n");
	printf("*****1.������ϵ��     2.ɾ����ϵ��*****\n");
	printf("*****3.������ϵ����Ϣ 4.������ϵ��*****\n");
	printf("*****5.չʾͨѶ¼     6.����      *****\n");
	printf("*****0.�˳�ͨѶ¼                 *****\n");
	printf("***************************************\n");
}
int main() {
	int input = 0; 
	Contact con;
	//��ʼ��ͨѶ¼
	InitContact(&con);
	do {
		//�˵�
		menu();
		printf("������ѡ��:>\n");
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
			printf("�������ѡ��\n");
			break;
		}

	} while (input);
	return 0;
}