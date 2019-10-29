#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <conio.h>
#include <iomanip>
#include <windows.h>
#include <mmsystem.h>
#include <easyx.h>
#include <stdio.h>
#include <graphics.h>
#include <iostream>
#include<fstream>

#pragma comment(lib,"winmm.lib")

#define WIDTH 600
#define HEIGHT 700
#define setfont settextstyle


extern int level, step1, step2;
extern int** playnum1;
extern int** anum6;
extern int** matrix1;
extern int** matrix6;

typedef struct {
	int a=0;
	int b=0;
}COOR;//玩家所点方格坐标(a,b)

void o1();//显示主界面
void o2();//显示操作方法
void o3();//显示开发人员
void start(int level);//显示游戏界面，参数为关卡数
void rule();//每关前显示本关规则界面
void map(int);//显示不同关卡的地图，参数为关卡数
COOR& numbutton(MOUSEMSG, COOR&, int);//计算鼠标所点方格坐标，参数为鼠标对象、坐标结构体、关卡数
void changecolor(int, int, int);//将被按下的按键底色改成灰色，参数为所点方格坐标
int judge(int level, int** playnum);//将玩家点击顺序和答案进行比对，参数为关卡数、玩家点击顺序数组
int** store(COOR& coor,int**, int level);//按顺序存储用户所按数字，参数为坐标、玩家点击顺序数组、关卡数
void evaluate(int score, int level);//显示评价界面，参数为得分、关卡数
bool isStop(bool& is_stop);//判断时间状态
void Start(bool& is_stop, long& start_time); //开始计时
void Stop(bool& is_stop);  //停止计时
void show(long& start_time, long& t, bool& is_stop);  //展示时间
int grade(int level, long time, int fault);//打分，参数为关卡数、所用时间、错误个数
int* searchif(int*);//检测关卡是否解锁，参数为关卡是否解锁的标志
void Gotoplay(int* a,int& level);//进入关卡，参数为关卡是否解锁的标志，关卡数
void lead(int* a);//显示选关界面，参数为关卡是否解锁的标志
void choose(int& level);//进入选关，参数为关卡数
void fopen(int level);//读取历史成绩文件，参数为关卡数
int random1(int** matrix1);//生成第一关随机矩阵
int random6(int** ranmatrix, int** anum6);//生成第六关随机矩阵

//每关显示矩阵预先设好
const int matrix2[10][10] = { 1,2,6,6,5,9,3,5,8,4,
							  6,6,4,5,8,2,5,3,1,9,
							  3,2,5,6,6,9,8,1,3,4,
							  5,3,9,2,4,8,9,6,1,2,
							  5,2,3,1,8,6,9,4,7,7,
							  6,6,4,5,8,2,5,3,1,9,
							  5,3,9,2,8,7,7,6,9,1,
							  1,2,6,6,5,9,3,5,8,4,
							  3,2,5,6,6,9,8,1,3,4,
							  8,8,4,5,6,5,1,3,9,6 };
const int matrix3[10][10] = { 3,7,1,3,9,8,6,7,7,9,
							2,5,6,3,7,1,5,7,3,7,
							4,2,9,8,7,3,2,3,7,5,
							1,2,7,3,5,6,2,8,9,3,
							7,9,7,4,5,8,2,6,7,8,
							1,9,8,7,7,4,5,6,3,7,
							2,5,6,8,3,7,5,8,7,6,
							7,3,1,2,8,6,6,7,8,1,
							5,8,7,3,6,2,4,9,7,9,
							3,7,6,5,3,2,9,6,7,8 };
const int matrix4[10][10] = { 7,3,5,6,9,3,7,6,7,5,
							  7,4,6,6,7,9,5,2,3,1,
							  4,6,8,6,4,2,3,1,5,7,
							  3,3,2,8,7,7,3,3,5,6,
							  7,3,7,4,5,6,9,7,6,3,
							  1,9,3,5,4,9,6,7,3,1,
							  4,5,7,9,8,9,7,2,3,7,
							  1,5,4,9,7,3,4,4,6,8,
							  4,6,1,7,9,5,2,1,3,6,
							  8,9,7,3,2,6,7,3,8,2 };
const int matrix5[10][10] = { 4,5,8,4,7,7,6,1,9,3,
							  4,2,5,7,3,6,1,9,6,4,
							  7,1,2,5,6,4,3,4,8,9,
							  8,5,6,2,7,3,1,4,8,5,
							  4,5,8,6,7,7,4,3,9,4,
							  7,6,5,8,2,2,1,3,9,2,
							  7,8,9,5,1,8,5,9,3,9,
							  6,5,3,7,9,4,6,1,3,2,
							  7,9,5,3,1,4,9,6,5,1,
							  4,5,8,7,6,3,1,5,6,3 };


