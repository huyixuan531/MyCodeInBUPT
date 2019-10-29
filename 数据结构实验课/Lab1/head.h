#pragma once
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>
#include<iostream>
#define LEN sizeof(LNode)
#define _CRT_SECURE_NO_WARNINGS

using  namespace std;

typedef struct LNode {
	char name[20];//城市名
	int x;//横坐标
	int y;//纵坐标
	struct LNode* next;//指向下一节点指针
}LNode,*Linklist;

Linklist createLink(Linklist& L);
int insertNode(Linklist L, Linklist city);
int delName(Linklist L, char name[20]);
int delPos(Linklist L, int px, int py);
int searchName(Linklist L, char name[20]);
int searchPos(Linklist L, int px, int py);
int updatebyName(Linklist L, char name[20]);
int updatebyPos(Linklist L, int px, int py);
int nameToPos(Linklist L, char name[20]);
int getNearCity(Linklist L, int px, int py, int d);