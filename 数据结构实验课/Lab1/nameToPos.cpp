#include"head.h"

//通过给定的城市名返回其坐标
int nameToPos(Linklist L, char name[20]) {
	int flag = 0;
	Linklist p = L->next;
	if (p == NULL || L == NULL)
		printf("该链表中没有元素,操作失败\n");
	else {
		while (p != NULL) {
			if (!strcmp(p->name, name)) {//查找给定城市名
				flag = 1;
				printf("城市%s的坐标为：（%d,%d）\n", p->name,p->x,p->y);//返回坐标
			}
			p = p->next;
		}
	}
	return flag;
}