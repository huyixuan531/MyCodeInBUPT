#include"head.h"

//更新节点城市信息
int updatebyName(Linklist L, char name[20]) {//利用城市名称更新坐标
	int flag = 0;
	Linklist p = L->next;
	if (p == NULL||L==NULL)//空表
	printf("该链表中没有元素,更新失败\n");
	else {
		while (p != NULL) {
			if (!strcmp(p->name, name)) {
				flag = 1;
				printf("请输入城市%s的新横坐标：\n", p->name);
				cin >> (p->x);
				printf("请输入城市%s的新纵坐标：\n", p->name);
				cin >> (p->y);
			}
			p = p->next;
		}
	}
	return flag;
}
int updatebyPos(Linklist L, int px, int py) {//利用坐标更新城市名称
	int flag = 0;
	Linklist p = L->next;
	if (p == NULL||L==NULL)
		printf("该链表中没有元素,更新失败\n");
	else {
		while (p != NULL) {
			if (p->x == px && p->y == py) {
				flag = 1;
				printf("请输入坐标为:(%d,%d）的城市的新名称：", p->x, p->y);
				cin >>(p->name);
			}
			p = p->next;
		}
	}
	return flag;
}