#include"play.h"
int main() {
	Game game_v;
	cout << "欢迎来到石头剪刀布游戏！"<<endl;
	cout << "请选择游戏模式：" << endl;//op1选择对战模式
	cout << "1.人机对战；2.电脑内部对战" << endl;
	while (1) {//循环限制输入不合法
		cin >> game_v.op1;
		if ((game_v.op1 == 1) || (game_v.op1 == 2))
			break;
		else cout << "输入不合法！请重新输入：" << endl;
	}
	play(game_v.op1, game_v);//开始游戏
	return 0;
}