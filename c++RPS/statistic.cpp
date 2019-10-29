#include<iomanip>
#include<string>
#include"strategy.h"
#include"game.h"
#include"translate.h"
//函数名：Game::statistics
//功能：统计并打印本局的游戏结果
void Game::statistics(Game& game_v) {
	int countA=0, countB=0;//两个变量分别用来记数A,B策略赢的次数
	cout << "----------------------------------\n结果统计：\n----------------------------------\n";
	cout <<"A策略(或玩家):" << setw(15) << "B策略(或电脑):" << setw(1) << "结果:" << endl;
	for (int j = 0; game_v.player[j][0] != 0; j++) {//打印本局所有出拳及结果
		cout << translate(game_v.player[j][0]) << setw(15) << translate(game_v.player[j][1]) << setw(15);//打印统计表格
		switch (isAwin(game_v.player[j][0], game_v.player[j][1])) {
		case 1: 
			countA++;
			break;
		case -1: 
			countB++;
			break;
		case 0:
			break;
		}
	}
	if(countA>countB)//比较A,B双方策略优劣
		cout << "----------------------------------\nA策略较优\n----------------------------------\n" << endl;
	else if(countA<countB)
		cout << "----------------------------------\nB策略较优\n----------------------------------\n" << endl;
	else if (countA == countB)
		cout << "----------------------------------\n两个策略优劣性相近\n----------------------------------\n" << endl;
	return;
}