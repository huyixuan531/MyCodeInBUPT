#include<string>
#include"strategy.h"
#include"game.h"
#include"translate.h"
//��������Game::attack
//���ܣ�ѡ���ս�����Լ���ȭ
void Game::attack(int op,int i,Random& random_v,Game& game_v) {
	WinLast winlast_v;
	UseLeast useleast_v;
	if (op == 1) {
		//�˻���սʱ�������������ȭ����
			cout << "������ȭ��\nR��ʯͷ\nS������\nP����" << endl;
		while (1) {//ѭ���������벻�Ϸ�
			cin >> game_v.op4;//op4Ϊ�˳���ȭ
			if ((game_v.op4 != 'R' )&&( game_v.op4 != 'S' )&& (game_v.op4 != 'P'))
					cout << "���벻�Ϸ������������룡" << endl;
			else break;
		}
		*(game_v.p + (2 * i+1)) = random_v.strategy();//��������ԵĽ���浽player[i][1]
		switch (game_v.op4) {
		case 'R':
			*(game_v.p + 2 * i) = 1;//����ʯͷ�浽player[i][0]
			break;
		case 'P':
			*(game_v.p + 2 * i) = 3;//�������浽player[i][0]
			break;
		case 'S':
			*(game_v.p + 2 * i) = 2;//���������浽player[i][0]
			break;
		}
		cout << "��(A):" << translate(game_v.player[i][0]) << endl;//��ӡ˫����ȭ
		cout << "����(B):" << translate(game_v.player[i][1]) << endl;
	}
	if (op == 2) {//�����ڲ���ս
		if (i == 0) {//ÿ�ֵĵ�һս��ӡ����ѡ��˵�
			cout << "��ѡ���ս˫��ʹ�õĲ��ԣ�" << endl;
			cout << "1.�����ȭ����(A)vsӮ����һ�ֲ���(B)" << endl;
			cout << "2.Ӯ����һ�ֲ���(A)vsʹ��������������(B)" << endl;
			cout << "3.�����ȭ����(A)vsʹ��������������(B)" << endl;
			while (1) {//ѭ���������벻�Ϸ�
				cin >> game_v.op2;//op2Ϊ��ս���Ե�ѡ��
				if ((game_v.op2 == 1) ||( game_v.op2 == 2 )||( game_v.op2 == 3))
					break;
				else cout << "���벻�Ϸ������������룺" << endl;
			}
		}
		switch (game_v.op2){
		case 1:
				*(game_v.p+2*i) = random_v.strategy();//��������ԵĽ���浽player[i][0]
				*(game_v.p + (2 * i+1)) = winlast_v.strategy(i, game_v.op2, random_v, game_v);//��Ӯ��һ�ֲ��ԵĽ���浽player[i][1]
				cout << "A:" << translate(game_v.player[i][0]) << endl;//��ӡ˫����ȭ
				cout << "B:" << translate(game_v.player[i][1]) << endl;
			break;
		case 2:
			*(game_v.p + 2 * i) = winlast_v.strategy(i, game_v.op2, random_v,  game_v);//��Ӯ��һ�ֲ��ԵĽ���浽player[i][0]
			*(game_v.p + (2 * i + 1)) = useleast_v.strategy( game_v);//��ʹ�����ٲ��ԵĽ���浽player[i][1]
			cout << "A:" << translate(game_v.player[i][0]) << endl;//��ӡ˫����ȭ
			cout << "B:" << translate(game_v.player[i][1]) << endl;
			break;
		case 3:
			*(game_v.p + 2 * i) = random_v.strategy();//��������ԵĽ���浽player[i][0]
			*(game_v.p + (2 * i + 1)) = useleast_v.strategy( game_v);//��ʹ�����ٲ��ԵĽ���浽player[i][1]
			cout << "A:" << translate(game_v.player[i][0]) << endl;//��ӡ˫����ȭ
			cout << "B:" << translate(game_v.player[i][1]) << endl;
			break;
		}
	}
}