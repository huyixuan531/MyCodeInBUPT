#include"head.h"

//ͨ�������ĳ���������������
int nameToPos(Linklist L, char name[20]) {
	int flag = 0;
	Linklist p = L->next;
	if (p == NULL || L == NULL)
		printf("��������û��Ԫ��,����ʧ��\n");
	else {
		while (p != NULL) {
			if (!strcmp(p->name, name)) {//���Ҹ���������
				flag = 1;
				printf("����%s������Ϊ����%d,%d��\n", p->name,p->x,p->y);//��������
			}
			p = p->next;
		}
	}
	return flag;
}