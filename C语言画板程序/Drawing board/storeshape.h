#pragma once
#include"graphics.h"
#include<stdio.h>

/*定义四种结构体，分别用以储存画过的四种图形信息*/
	typedef struct {
		int shape;
		char color;
		int fill;
		int coor[3];
	}CIRCLE;

	typedef struct {
		int shape;
		char color;
		int coor[4];
	}LINE;

	typedef struct {
		int shape;
		char color;
		int fill;
		int coor[4];
	}BAR;

	typedef struct {
		int shape;
		char color;
		int fill;
		int side;
		int coor[100];
	}FILLPOLY;

/*函数storeshape的原型声明*/
void storeshape(char op4);