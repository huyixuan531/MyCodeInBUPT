#include"head.h"

int main(void) {
	int px,py,d,flag;
	char name[20];
	printf("欢迎使用城市链表！\n");
	Linklist p = (Linklist)malloc(LEN);
	Linklist L = (Linklist)malloc(LEN);
	while (1) {
		int op1 = 0, op2 = 0;
		printf("----------------------------\n");
		printf("1.创建城市链表\n");
		printf("2.增加新的城市节点\n");
		printf("3.删除城市节点\n");
		printf("4.改动城市节点信息\n");
		printf("5.查找城市节点\n");
		printf("6.查看城市坐标\n");
		printf("7.查找附近城市\n");
		printf("8.退出\n");
		printf("----------------------------\n");
		cin >> op1;
		switch (op1){
		case 1://创建链表
			createLink(L);
			printf("创建成功！\n");
			break;
		case 2://增
			printf("请输入城市名：\n");
			cin >> name;
			printf("请输入横坐标：\n");
			cin >> px;
			printf("请输入纵坐标：\n");
			cin >> py;
			strcpy_s(p->name, name);
			p->x = px;
			p->y = py;
			insertNode(L, p);
			printf("添加成功！\n");
			break;
		case 3://删
			while (1) {
				printf("请选择删除方式：\n1.根据城市名||2.根据坐标\n");
				scanf_s("%d", &op2);
				if (op2 == 1) {
					printf("请输入城市名：\n");
					cin >> name;
					flag = delName(L, name);
					if (flag) printf("城市%s已删除！\n", name);
					else printf("没有该城市，删除失败\n");
					break;
				}
				else if (op2 == 2) {
					printf("请输入横坐标：\n");
					cin >> px;
					printf("请输入纵坐标：\n");
					cin >> py;
					flag = delPos(L, px, py);
					if (flag) printf("城市(%d,%d)已删除！\n", px, py);
					else printf("没有该城市，删除失败\n");
					break;
				}
				else printf("输入不合法！请重新输入\n");
			}
			break;
		case 4://改
			while (1) {
				printf("请选择更新方式：\n1.根据城市名改坐标||2.根据坐标改城市名\n");
				cin >> op2;
				if (op2 == 1) {
					printf("请输入城市名：\n");
					cin >> name;
					flag = updatebyName(L, name);
					if (flag) printf("信息更新成功！\n");
					else printf("没有该城市，更新失败\n");
					break;
				}
				else if (op2 == 2) {
					printf("请输入横坐标：\n");
					cin >> px;
					printf("请输入纵坐标：\n");
					cin >> py;
					flag = updatebyPos(L, px, py);
					if (flag) printf("信息更新成功！\n");
					else printf("没有该城市，更新失败\n");
					break;
				}
				else printf("输入不合法！请重新输入\n");
			}
			break;
		case 5://查
			while (1) {
				printf("请选择查找方式：\n1.查找城市名||2.查找城市坐标\n");
				cin >> op2;
				if (op2 == 1) {
					printf("请输入城市名：\n");
					cin >> name;
					flag = searchName(L, name);
					if (flag==0) printf("没有该城市，查找失败\n");
					break;
				}
				else if (op2 == 2) {
					printf("请输入横坐标：\n");
					cin >> px;
					printf("请输入纵坐标：\n");
					cin >> py;
					flag = searchPos(L, px, py);
					if (flag==0)printf("没有该城市，查找失败\n");
					break;
				}
				else printf("输入不合法！请重新输入\n");
			}
			break;
		case 6://查看坐标
			printf("请输入需要返回坐标的城市名称：\n");
			cin >> name;
			printf("\n");
			flag = nameToPos(L,name);
			if (flag == 0)printf("没有该城市，查找失败\n");
			break;
		case 7://查找附近
			printf("请输入某地横坐标：\n");
			cin >> px;
			printf("请输入某地纵坐标：\n");
			cin >> py;
			printf("请输入距离半径：\n");
			cin >> d;
			flag = getNearCity(L, px,py,d);
			if (flag == 0)printf("不存在满足条件的城市！\n");
			break;
		case 8:
			exit(0);
			break; 
		default:
			printf("输入不合法！请重新输入\n");
			break;
		}
	}
	return 0;
}