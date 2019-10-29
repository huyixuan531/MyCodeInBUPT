#include"head.h"

//通过给定城市坐标、距离，返回该城市该距离内的其他城市名
int getNearCity(Linklist L, int px,int py,int d) {
	int flag = 0;
	double distance;
	Linklist p = L->next;
	if (p == NULL || L == NULL)
		printf("该链表中没有元素,操作失败\n");
	else {
		printf("距离范围内的城市有:\n");
		p = p->next;
		while (p != NULL) {
			distance = sqrt(((p->x) - px) ^ 2 + ((p->y) - py) ^ 2);//距离=根号(▲x^2+▲y^2)
			if (distance<=d) {//若实际距离小于给定距离
				flag = 1;
				cout << (p->name);
				cout << "，";
			}
			p = p->next;
		}
	}
	printf("\n");
	return flag;
}