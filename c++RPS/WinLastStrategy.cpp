#include<iostream>
#include"strategy.h"
#include"game.h"
using namespace std;
//��������WinLast::strategy
//���ܣ���Ӯ����һս�ķ�ʽ��ȭ
int WinLast::strategy(int i, int op2, Random& random_v, Game& game_v) {
	if (op2 == 1) {//�����һսΪ��ս�������
		if (game_v.player[i - 1][0] == 1)
			return 3;//�����һս�Է���ʯͷ����ս����
		if (game_v.player[i - 1][0] == 2)
			return 1;//�����һս�Է�����������ս��ʯͷ
		if (game_v.player[i - 1][0] == 3)
			return 2;//�����һս�Է���������ս������
		if (game_v.player[0][1] == 0)//������ǵ�һ����Ϸ��û����һ�֣��������ȭһ��
			return random_v.strategy();
		else return 0;
	}
	else if (op2 = 2) {//�����һսΪ��ս��ȭ���ٲ���
		if (game_v.player[i - 1][1] == 1)
			return 3;//�����һս�Է���ʯͷ����ս����
		if (game_v.player[i - 1][1] == 2)
			return 1;//�����һս�Է�����������ս��ʯͷ
		if (game_v.player[i - 1][1] == 3)
			return 2;//�����һս�Է���������ս������
		if (game_v.player[0][1] == 0)//������ǵ�һ����Ϸ��û����һ�֣��������ȭһ��
			return random_v.strategy();
		else return 0;
	}
	else return 0;
}