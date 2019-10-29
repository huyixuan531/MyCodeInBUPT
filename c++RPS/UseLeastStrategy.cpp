#include<iostream>
#include"strategy.h"
#include"game.h"
using namespace std;
//函数名：UseLeast::strategy
//功能：统计到目前为止哪种拳出的最少，并以该种方式出拳
int UseLeast::strategy(Game& game_v) {
	int countR=0, countP=0, countS=0;//三个变量分别记录石头，布，剪刀的出现次数
	for (int k = 0; game_v.player[k][0] != 0; k++) {
		if (game_v.player[k][0] == 1)
			countR++;
		if (game_v.player[k][1] == 1)
			countR++;
		if (game_v.player[k][0] == 2)
			countS++;
		if (game_v.player[k][1] == 2)
			countS++;
		if (game_v.player[k][0] == 3)
			countP++;
		if (game_v.player[k][1] == 3)
			countP++;
	}
	if ((countR<=countP)&&(countR<=countS)) return 1;      //石头、剪刀一样少，优先出石头
	if ((countS <= countP) && (countS <= countR)) return 2;//剪刀、布一样少，优先出剪刀
	if ((countP <= countR) && (countP <= countS)) return 3;//石头、布一样少，优先出石头
	else return 0;                                                                                 //三个一样少，优先出石头
}