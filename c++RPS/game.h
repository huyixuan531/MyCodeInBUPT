#pragma once
//#include"strategy.h"
class Random;
class Game {
public:
	int player[50][2] = { {0,0} };//{A,B}�������洢˫����ȭ�����AΪ����1���ˣ�BΪ����2�����
	int *p = *player;
	//op1:ѡ����Ϸģʽ;
	//op2:ѡ��˫������;
	//op3:�Ƿ������һս;
	//op4:�����˳���ȭ;
	//op5:��ʼ��һ�ֻ��˳�;
	int op1, op2, op5;
	char op3, op4;
	void attack(int,int,Random&,Game&);//��ȭ
	int isAwin(int,int);//�ж�ʤ��
	void statistics(Game&);//���ͳ�ƣ��Ƚ�����
};