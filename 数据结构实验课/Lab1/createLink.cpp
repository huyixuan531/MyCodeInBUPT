#include"head.h"

//创建一个城市链表，返回链表头节点
Linklist createLink(Linklist& L) {
	Linklist head = (Linklist)malloc(LEN);//指针分配内存
	Linklist p = (Linklist)malloc(LEN);
	head->next = NULL;//指针初始化
	( L->next)=head;
	char name[20];
	int px, py;
	printf("建立一个城市链表，请输入第一个城市名，城市坐标。\n");
	printf("请输入城市名：\n");
	cin >> name;
	printf("请输入横坐标：\n");
	cin >> px;
	printf("请输入纵坐标：\n");
	cin >> py;
	strcpy_s(p->name,name);//输入信息拷贝给节点
	p->x = px;
	p->y = py;
	insertNode(L, p);//加入第一个节点
	return L;
}