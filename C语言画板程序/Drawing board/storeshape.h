#pragma once
#include"graphics.h"
#include<stdio.h>

/*�������ֽṹ�壬�ֱ����Դ��滭��������ͼ����Ϣ*/
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

/*����storeshape��ԭ������*/
void storeshape(char op4);