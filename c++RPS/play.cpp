#include"play.h"
#include "strategy.h"
void play(int op1,Game& game_v) {//����op1Ϊѡ����Ϸģʽ
	
	Random random_v;
	while (1) {
		for (int a = 0; a < 50;a++) {
			for (int b = 0; b < 2;b++) {
				game_v.player[a][b] = 0;
			}
		}//��ʼ��һ��ǰ����player[][]
		for (int i = 0; i < 50; i++) {//ÿ��������50ս
			game_v.attack(op1,i,random_v, game_v);//˫����ȭ
			game_v.isAwin(game_v.player[i][0],game_v.player[i][1]);//�ж���Ӯ
			cout << "�Ƿ������ÿ�����50ս��������Q����������Ϸ����������+�س�������" << endl;
			cin >> game_v.op3;
			if (game_v.op3=='Q')//����û�����Q
				break;//���˳�������Ϸ
		}
		game_v.statistics(game_v);//ͳ�Ʊ��ֽ��
		cout << "1.���¿�ʼһ����Ϸ\n2.�˳�\n" << endl;//�Ƿ�ʼ��һ����Ϸ��
			cin >> game_v.op5;
			if (game_v.op5 == 2) break;//�˳�����
	}
	cout << "��л��Ϸ��" << endl;
}