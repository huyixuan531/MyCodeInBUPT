#include"play.h"
#include "strategy.h"
void play(int op1,Game& game_v) {//参数op1为选择游戏模式
	
	Random random_v;
	while (1) {
		for (int a = 0; a < 50;a++) {
			for (int b = 0; b < 2;b++) {
				game_v.player[a][b] = 0;
			}
		}//开始新一局前重置player[][]
		for (int i = 0; i < 50; i++) {//每局最多进行50战
			game_v.attack(op1,i,random_v, game_v);//双方出拳
			game_v.isAwin(game_v.player[i][0],game_v.player[i][1]);//判断输赢
			cout << "是否继续（每局最多50战）？（按Q结束本局游戏，按其他键+回车继续）" << endl;
			cin >> game_v.op3;
			if (game_v.op3=='Q')//如果用户输入Q
				break;//则退出本局游戏
		}
		game_v.statistics(game_v);//统计本局结果
		cout << "1.重新开始一局游戏\n2.退出\n" << endl;//是否开始下一局游戏？
			cin >> game_v.op5;
			if (game_v.op5 == 2) break;//退出程序
	}
	cout << "感谢游戏！" << endl;
}