#include"head.h"

int main(void) {
	int px,py,d,flag;
	char name[20];
	printf("��ӭʹ�ó�������\n");
	Linklist p = (Linklist)malloc(LEN);
	Linklist L = (Linklist)malloc(LEN);
	while (1) {
		int op1 = 0, op2 = 0;
		printf("----------------------------\n");
		printf("1.������������\n");
		printf("2.�����µĳ��нڵ�\n");
		printf("3.ɾ�����нڵ�\n");
		printf("4.�Ķ����нڵ���Ϣ\n");
		printf("5.���ҳ��нڵ�\n");
		printf("6.�鿴��������\n");
		printf("7.���Ҹ�������\n");
		printf("8.�˳�\n");
		printf("----------------------------\n");
		cin >> op1;
		switch (op1){
		case 1://��������
			createLink(L);
			printf("�����ɹ���\n");
			break;
		case 2://��
			printf("�������������\n");
			cin >> name;
			printf("����������꣺\n");
			cin >> px;
			printf("�����������꣺\n");
			cin >> py;
			strcpy_s(p->name, name);
			p->x = px;
			p->y = py;
			insertNode(L, p);
			printf("��ӳɹ���\n");
			break;
		case 3://ɾ
			while (1) {
				printf("��ѡ��ɾ����ʽ��\n1.���ݳ�����||2.��������\n");
				scanf_s("%d", &op2);
				if (op2 == 1) {
					printf("�������������\n");
					cin >> name;
					flag = delName(L, name);
					if (flag) printf("����%s��ɾ����\n", name);
					else printf("û�иó��У�ɾ��ʧ��\n");
					break;
				}
				else if (op2 == 2) {
					printf("����������꣺\n");
					cin >> px;
					printf("�����������꣺\n");
					cin >> py;
					flag = delPos(L, px, py);
					if (flag) printf("����(%d,%d)��ɾ����\n", px, py);
					else printf("û�иó��У�ɾ��ʧ��\n");
					break;
				}
				else printf("���벻�Ϸ�������������\n");
			}
			break;
		case 4://��
			while (1) {
				printf("��ѡ����·�ʽ��\n1.���ݳ�����������||2.��������ĳ�����\n");
				cin >> op2;
				if (op2 == 1) {
					printf("�������������\n");
					cin >> name;
					flag = updatebyName(L, name);
					if (flag) printf("��Ϣ���³ɹ���\n");
					else printf("û�иó��У�����ʧ��\n");
					break;
				}
				else if (op2 == 2) {
					printf("����������꣺\n");
					cin >> px;
					printf("�����������꣺\n");
					cin >> py;
					flag = updatebyPos(L, px, py);
					if (flag) printf("��Ϣ���³ɹ���\n");
					else printf("û�иó��У�����ʧ��\n");
					break;
				}
				else printf("���벻�Ϸ�������������\n");
			}
			break;
		case 5://��
			while (1) {
				printf("��ѡ����ҷ�ʽ��\n1.���ҳ�����||2.���ҳ�������\n");
				cin >> op2;
				if (op2 == 1) {
					printf("�������������\n");
					cin >> name;
					flag = searchName(L, name);
					if (flag==0) printf("û�иó��У�����ʧ��\n");
					break;
				}
				else if (op2 == 2) {
					printf("����������꣺\n");
					cin >> px;
					printf("�����������꣺\n");
					cin >> py;
					flag = searchPos(L, px, py);
					if (flag==0)printf("û�иó��У�����ʧ��\n");
					break;
				}
				else printf("���벻�Ϸ�������������\n");
			}
			break;
		case 6://�鿴����
			printf("��������Ҫ��������ĳ������ƣ�\n");
			cin >> name;
			printf("\n");
			flag = nameToPos(L,name);
			if (flag == 0)printf("û�иó��У�����ʧ��\n");
			break;
		case 7://���Ҹ���
			printf("������ĳ�غ����꣺\n");
			cin >> px;
			printf("������ĳ�������꣺\n");
			cin >> py;
			printf("���������뾶��\n");
			cin >> d;
			flag = getNearCity(L, px,py,d);
			if (flag == 0)printf("���������������ĳ��У�\n");
			break;
		case 8:
			exit(0);
			break; 
		default:
			printf("���벻�Ϸ�������������\n");
			break;
		}
	}
	return 0;
}