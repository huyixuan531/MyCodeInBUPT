#include<string>
#include"strategy.h"
#include"game.h"
#include"translate.h"
//函数名：Game::attack
//功能：选择对战策略以及出拳
void Game::attack(int op,int i,Random& random_v,Game& game_v) {
	WinLast winlast_v;
	UseLeast useleast_v;
	if (op == 1) {
		//人机对战时机器采用随机出拳策略
			cout << "请您出拳：\nR：石头\nS：剪刀\nP：布" << endl;
		while (1) {//循环限制输入不合法
			cin >> game_v.op4;//op4为人出的拳
			if ((game_v.op4 != 'R' )&&( game_v.op4 != 'S' )&& (game_v.op4 != 'P'))
					cout << "输入不合法，请重新输入！" << endl;
			else break;
		}
		*(game_v.p + (2 * i+1)) = random_v.strategy();//将随机策略的结果存到player[i][1]
		switch (game_v.op4) {
		case 'R':
			*(game_v.p + 2 * i) = 1;//将出石头存到player[i][0]
			break;
		case 'P':
			*(game_v.p + 2 * i) = 3;//将出布存到player[i][0]
			break;
		case 'S':
			*(game_v.p + 2 * i) = 2;//将出剪刀存到player[i][0]
			break;
		}
		cout << "您(A):" << translate(game_v.player[i][0]) << endl;//打印双方出拳
		cout << "电脑(B):" << translate(game_v.player[i][1]) << endl;
	}
	if (op == 2) {//机器内部对战
		if (i == 0) {//每局的第一战打印策略选择菜单
			cout << "请选择对战双方使用的策略：" << endl;
			cout << "1.随机出拳策略(A)vs赢得上一局策略(B)" << endl;
			cout << "2.赢得上一局策略(A)vs使用最少招数策略(B)" << endl;
			cout << "3.随机出拳策略(A)vs使用最少招数策略(B)" << endl;
			while (1) {//循环限制输入不合法
				cin >> game_v.op2;//op2为对战策略的选择
				if ((game_v.op2 == 1) ||( game_v.op2 == 2 )||( game_v.op2 == 3))
					break;
				else cout << "输入不合法！请重新输入：" << endl;
			}
		}
		switch (game_v.op2){
		case 1:
				*(game_v.p+2*i) = random_v.strategy();//将随机策略的结果存到player[i][0]
				*(game_v.p + (2 * i+1)) = winlast_v.strategy(i, game_v.op2, random_v, game_v);//将赢上一局策略的结果存到player[i][1]
				cout << "A:" << translate(game_v.player[i][0]) << endl;//打印双方出拳
				cout << "B:" << translate(game_v.player[i][1]) << endl;
			break;
		case 2:
			*(game_v.p + 2 * i) = winlast_v.strategy(i, game_v.op2, random_v,  game_v);//将赢上一局策略的结果存到player[i][0]
			*(game_v.p + (2 * i + 1)) = useleast_v.strategy( game_v);//将使用最少策略的结果存到player[i][1]
			cout << "A:" << translate(game_v.player[i][0]) << endl;//打印双方出拳
			cout << "B:" << translate(game_v.player[i][1]) << endl;
			break;
		case 3:
			*(game_v.p + 2 * i) = random_v.strategy();//将随机策略的结果存到player[i][0]
			*(game_v.p + (2 * i + 1)) = useleast_v.strategy( game_v);//将使用最少策略的结果存到player[i][1]
			cout << "A:" << translate(game_v.player[i][0]) << endl;//打印双方出拳
			cout << "B:" << translate(game_v.player[i][1]) << endl;
			break;
		}
	}
}