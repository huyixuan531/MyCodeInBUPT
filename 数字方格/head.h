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
}COOR;//������㷽������(a,b)

void o1();//��ʾ������
void o2();//��ʾ��������
void o3();//��ʾ������Ա
void start(int level);//��ʾ��Ϸ���棬����Ϊ�ؿ���
void rule();//ÿ��ǰ��ʾ���ع������
void map(int);//��ʾ��ͬ�ؿ��ĵ�ͼ������Ϊ�ؿ���
COOR& numbutton(MOUSEMSG, COOR&, int);//����������㷽�����꣬����Ϊ����������ṹ�塢�ؿ���
void changecolor(int, int, int);//�������µİ�����ɫ�ĳɻ�ɫ������Ϊ���㷽������
int judge(int level, int** playnum);//����ҵ��˳��ʹ𰸽��бȶԣ�����Ϊ�ؿ�������ҵ��˳������
int** store(COOR& coor,int**, int level);//��˳��洢�û��������֣�����Ϊ���ꡢ��ҵ��˳�����顢�ؿ���
void evaluate(int score, int level);//��ʾ���۽��棬����Ϊ�÷֡��ؿ���
bool isStop(bool& is_stop);//�ж�ʱ��״̬
void Start(bool& is_stop, long& start_time); //��ʼ��ʱ
void Stop(bool& is_stop);  //ֹͣ��ʱ
void show(long& start_time, long& t, bool& is_stop);  //չʾʱ��
int grade(int level, long time, int fault);//��֣�����Ϊ�ؿ���������ʱ�䡢�������
int* searchif(int*);//���ؿ��Ƿ����������Ϊ�ؿ��Ƿ�����ı�־
void Gotoplay(int* a,int& level);//����ؿ�������Ϊ�ؿ��Ƿ�����ı�־���ؿ���
void lead(int* a);//��ʾѡ�ؽ��棬����Ϊ�ؿ��Ƿ�����ı�־
void choose(int& level);//����ѡ�أ�����Ϊ�ؿ���
void fopen(int level);//��ȡ��ʷ�ɼ��ļ�������Ϊ�ؿ���
int random1(int** matrix1);//���ɵ�һ���������
int random6(int** ranmatrix, int** anum6);//���ɵ������������

//ÿ����ʾ����Ԥ�����
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


