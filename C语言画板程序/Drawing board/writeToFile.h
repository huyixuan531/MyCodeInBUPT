#pragma once
#include<stdio.h>
#include"graphics.h"
#define _CRT_SECURE_NO_WARNINGS
#include"storeshape.h"

/*外部引用结构体变量*/
extern CIRCLE circle_v[];
extern LINE line_v[];
extern BAR bar_v[];
extern FILLPOLY fillpoly_v[];

/*函数writeToFile的原型声明*/
void writeToFile(char);