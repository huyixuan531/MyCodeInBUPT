#include"head.h"

//���½ڵ������Ϣ
int updatebyName(Linklist L, char name[20]) {//���ó������Ƹ�������
	int flag = 0;
	Linklist p = L->next;
	if (p == NULL||L==NULL)//�ձ�
	printf("��������û��Ԫ��,����ʧ��\n");
	else {
		while (p != NULL) {
			if (!strcmp(p->name, name)) {
				flag = 1;
				printf("���������%s���º����꣺\n", p->name);
				cin >> (p->x);
				printf("���������%s���������꣺\n", p->name);
				cin >> (p->y);
			}
			p = p->next;
		}
	}
	return flag;
}
int updatebyPos(Linklist L, int px, int py) {//����������³�������
	int flag = 0;
	Linklist p = L->next;
	if (p == NULL||L==NULL)
		printf("��������û��Ԫ��,����ʧ��\n");
	else {
		while (p != NULL) {
			if (p->x == px && p->y == py) {
				flag = 1;
				printf("����������Ϊ:(%d,%d���ĳ��е������ƣ�", p->x, p->y);
				cin >>(p->name);
			}
			p = p->next;
		}
	}
	return flag;
}