#include"head.h"

//ͨ�������������ꡢ���룬���ظó��иþ����ڵ�����������
int getNearCity(Linklist L, int px,int py,int d) {
	int flag = 0;
	double distance;
	Linklist p = L->next;
	if (p == NULL || L == NULL)
		printf("��������û��Ԫ��,����ʧ��\n");
	else {
		printf("���뷶Χ�ڵĳ�����:\n");
		p = p->next;
		while (p != NULL) {
			distance = sqrt(((p->x) - px) ^ 2 + ((p->y) - py) ^ 2);//����=����(��x^2+��y^2)
			if (distance<=d) {//��ʵ�ʾ���С�ڸ�������
				flag = 1;
				cout << (p->name);
				cout << "��";
			}
			p = p->next;
		}
	}
	printf("\n");
	return flag;
}