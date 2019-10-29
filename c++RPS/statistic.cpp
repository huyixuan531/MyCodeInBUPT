#include<iomanip>
#include<string>
#include"strategy.h"
#include"game.h"
#include"translate.h"
//��������Game::statistics
//���ܣ�ͳ�Ʋ���ӡ���ֵ���Ϸ���
void Game::statistics(Game& game_v) {
	int countA=0, countB=0;//���������ֱ���������A,B����Ӯ�Ĵ���
	cout << "----------------------------------\n���ͳ�ƣ�\n----------------------------------\n";
	cout <<"A����(�����):" << setw(15) << "B����(�����):" << setw(1) << "���:" << endl;
	for (int j = 0; game_v.player[j][0] != 0; j++) {//��ӡ�������г�ȭ�����
		cout << translate(game_v.player[j][0]) << setw(15) << translate(game_v.player[j][1]) << setw(15);//��ӡͳ�Ʊ��
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
	if(countA>countB)//�Ƚ�A,B˫����������
		cout << "----------------------------------\nA���Խ���\n----------------------------------\n" << endl;
	else if(countA<countB)
		cout << "----------------------------------\nB���Խ���\n----------------------------------\n" << endl;
	else if (countA == countB)
		cout << "----------------------------------\n�����������������\n----------------------------------\n" << endl;
	return;
}