#pragma once
#include<stdio.h>
#include"graphics.h"
#include"storeshape.h"

/*外部引用结构体变量*/
extern CIRCLE circle_v[];
extern LINE line_v[];
extern BAR bar_v[];
extern FILLPOLY fillpoly_v[];
extern int checkshape_s;

/*函数checkshape的原型声明*/
int checkshape(int*);