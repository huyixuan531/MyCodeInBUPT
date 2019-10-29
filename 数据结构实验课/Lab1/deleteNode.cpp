#include"head.h"

//从链表中删除城市节点
int delName(Linklist L, char name[20]) {//利用城市名称删除  
	int flag = 0;
	int seat = 1;
	Linklist p = (Linklist)malloc(LEN);
	p = L;
	if (p->next == NULL)//若是空表
		printf("该链表中没有元素,删除失败\n");
	else {
		while (p->next != NULL) {
			if (!strcmp(p->next->name, name)) {
				flag = 1;
				printf("城市%s已删除\n", name);
				Linklist q = p->next;//将被删节点前后链接起来
				p->next = q->next;
				free(q);//释放内存
			}
			else p = p->next;
		}
	}
	return flag;
}
int delPos(Linklist L, int px, int py) {//利用城市坐标删除
	int flag = 0;
	Linklist p = L;
	if (p->next == NULL)
		printf("该链表中没有元素,删除失败\n");
	else {
		while (p->next != NULL) {
			if (p->next->x == px && p->next->y == py) {
				Linklist q = p->next;
				p->next = q->next;
				free(q);
				flag = 1;
				printf("坐标为%d,%d的城市已删除\n", px, py);
			}
			else p = p->next;
		}
	}
	return flag;
}