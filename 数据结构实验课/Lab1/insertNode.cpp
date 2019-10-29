#include"head.h"

//向链表中插入新节点
int insertNode(Linklist L, Linklist city) {
	Linklist p = L->next;
	Linklist p_prior = L;
	while (p != NULL && city->x >= p->x) {
		if (p->x == city->x && p->y == city->y) {//如果已存在此坐标
			printf("重复输入！\n");
			return 0;
		}
		p = p->next;//p指向新增节点的下一个节点
	}
	while (p_prior->next != p) { 
		p_prior = p_prior->next; 
	}
	if (p == NULL) { //若为空表，插到头结点之后  
		p = p_prior;
		city->next = NULL;
		p->next = city; 
	}
	else{//若不为空表，插入节点	
	p=p_prior;
	city->next=p->next;
	p->next=city;
	}
	return 1;
}