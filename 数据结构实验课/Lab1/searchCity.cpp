#include"head.h"

//���ҳ������ƻ�����
int searchName(Linklist L, char name[20]) {//���ó������Ʋ���
	int flag = 0;
	Linklist p = (Linklist)malloc(LEN);
	p = L->next;
	if (p == NULL)//��Ϊ�ձ�
		printf("��������û��Ԫ��,����ʧ��\n");
	else {
		while (p != NULL) {
			if (!strcmp(p->name, name)) {
				flag = 1;
				printf("����%s������Ϊ:��%d,%d��\n", p->name, p->x, p->y);
			}
			p = p->next;
		}
	}
	return flag;
}
int searchPos(Linklist L, int px,int py) {//���ó����������
	int flag = 0;
	Linklist p = L->next;
	if (p == NULL)
		printf("��������û��Ԫ��,����ʧ��\n");
	else {
		while (p != NULL) {
			if(p->x==px&&p->y==py){
				flag = 1;
				printf("����Ϊ:(%d,%d���ĳ�����Ϊ��%s", p->x, p->y,p->name);
			}
			p = p->next;
		}
	}
	return flag;
}