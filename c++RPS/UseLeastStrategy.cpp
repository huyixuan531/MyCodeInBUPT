#include<iostream>
#include"strategy.h"
#include"game.h"
using namespace std;
//��������UseLeast::strategy
//���ܣ�ͳ�Ƶ�ĿǰΪֹ����ȭ�������٣����Ը��ַ�ʽ��ȭ
int UseLeast::strategy(Game& game_v) {
	int countR=0, countP=0, countS=0;//���������ֱ��¼ʯͷ�����������ĳ��ִ���
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
	if ((countR<=countP)&&(countR<=countS)) return 1;      //ʯͷ������һ���٣����ȳ�ʯͷ
	if ((countS <= countP) && (countS <= countR)) return 2;//��������һ���٣����ȳ�����
	if ((countP <= countR) && (countP <= countS)) return 3;//ʯͷ����һ���٣����ȳ�ʯͷ
	else return 0;                                                                                 //����һ���٣����ȳ�ʯͷ
}