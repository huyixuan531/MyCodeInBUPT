#include"head.h"

//查找城市名称或坐标
int searchName(Linklist L, char name[20]) {//利用城市名称查找
	int flag = 0;
	Linklist p = (Linklist)malloc(LEN);
	p = L->next;
	if (p == NULL)//若为空表
		printf("该链表中没有元素,查找失败\n");
	else {
		while (p != NULL) {
			if (!strcmp(p->name, name)) {
				flag = 1;
				printf("城市%s的坐标为:（%d,%d）\n", p->name, p->x, p->y);
			}
			p = p->next;
		}
	}
	return flag;
}
int searchPos(Linklist L, int px,int py) {//利用城市坐标查找
	int flag = 0;
	Linklist p = L->next;
	if (p == NULL)
		printf("该链表中没有元素,查找失败\n");
	else {
		while (p != NULL) {
			if(p->x==px&&p->y==py){
				flag = 1;
				printf("坐标为:(%d,%d）的城市名为：%s", p->x, p->y,p->name);
			}
			p = p->next;
		}
	}
	return flag;
}