#include"head.h"

//����һ������������������ͷ�ڵ�
Linklist createLink(Linklist& L) {
	Linklist head = (Linklist)malloc(LEN);//ָ������ڴ�
	Linklist p = (Linklist)malloc(LEN);
	head->next = NULL;//ָ���ʼ��
	( L->next)=head;
	char name[20];
	int px, py;
	printf("����һ�����������������һ�����������������ꡣ\n");
	printf("�������������\n");
	cin >> name;
	printf("����������꣺\n");
	cin >> px;
	printf("�����������꣺\n");
	cin >> py;
	strcpy_s(p->name,name);//������Ϣ�������ڵ�
	p->x = px;
	p->y = py;
	insertNode(L, p);//�����һ���ڵ�
	return L;
}