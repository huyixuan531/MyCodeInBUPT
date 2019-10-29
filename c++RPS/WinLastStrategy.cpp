#include<iostream>
#include"strategy.h"
#include"game.h"
using namespace std;
//函数名：WinLast::strategy
//功能：以赢得上一战的方式出拳
int WinLast::strategy(int i, int op2, Random& random_v, Game& game_v) {
	if (op2 == 1) {//如果上一战为对战随机策略
		if (game_v.player[i - 1][0] == 1)
			return 3;//如果上一战对方出石头，则本战出布
		if (game_v.player[i - 1][0] == 2)
			return 1;//如果上一战对方出剪刀，则本战出石头
		if (game_v.player[i - 1][0] == 3)
			return 2;//如果上一战对方出布，则本战出剪刀
		if (game_v.player[0][1] == 0)//如果这是第一局游戏，没有上一局，则随机出拳一次
			return random_v.strategy();
		else return 0;
	}
	else if (op2 = 2) {//如果上一战为对战出拳最少策略
		if (game_v.player[i - 1][1] == 1)
			return 3;//如果上一战对方出石头，则本战出布
		if (game_v.player[i - 1][1] == 2)
			return 1;//如果上一战对方出剪刀，则本战出石头
		if (game_v.player[i - 1][1] == 3)
			return 2;//如果上一战对方出布，则本战出剪刀
		if (game_v.player[0][1] == 0)//如果这是第一局游戏，没有上一局，则随机出拳一次
			return random_v.strategy();
		else return 0;
	}
	else return 0;
}