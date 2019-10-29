#include<iostream>
#include"strategy.h"
#include"game.h"
using namespace std;
//函数名：isAwin
//功能：判断出拳双方输赢
int Game::isAwin(int result1, int result2) {
	if (result1 == 1 && result2 == 1 || result1 == 2 && result2 == 2 || result1 == 3 && result2 == 3) {
		cout << "平局！" << endl;
		return 0;
	}
	else if (result1 == 1 && result2 == 2 || result1 == 2 && result2 == 3 || result1 == 3 && result2 == 1) {
		cout << "A赢！" << endl;
		return 1;
	}
	else if (result1 == 1 && result2 == 3 || result1 == 2 && result2 == 1 || result1 == 3 && result2 == 2) {
		cout << "B赢！" << endl;
		return -1;
	}
	else return 0;
}