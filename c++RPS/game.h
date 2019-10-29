#pragma once
//#include"strategy.h"
class Random;
class Game {
public:
	int player[50][2] = { {0,0} };//{A,B}；用来存储双方出拳结果。A为策略1或人，B为策略2或电脑
	int *p = *player;
	//op1:选择游戏模式;
	//op2:选择双方策略;
	//op3:是否继续下一战;
	//op4:输入人出的拳;
	//op5:开始下一局或退出;
	int op1, op2, op5;
	char op3, op4;
	void attack(int,int,Random&,Game&);//出拳
	int isAwin(int,int);//判断胜负
	void statistics(Game&);//结果统计，比较优劣
};