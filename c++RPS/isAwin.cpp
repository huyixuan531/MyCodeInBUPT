#include<iostream>
#include"strategy.h"
#include"game.h"
using namespace std;
//��������isAwin
//���ܣ��жϳ�ȭ˫����Ӯ
int Game::isAwin(int result1, int result2) {
	if (result1 == 1 && result2 == 1 || result1 == 2 && result2 == 2 || result1 == 3 && result2 == 3) {
		cout << "ƽ�֣�" << endl;
		return 0;
	}
	else if (result1 == 1 && result2 == 2 || result1 == 2 && result2 == 3 || result1 == 3 && result2 == 1) {
		cout << "AӮ��" << endl;
		return 1;
	}
	else if (result1 == 1 && result2 == 3 || result1 == 2 && result2 == 1 || result1 == 3 && result2 == 2) {
		cout << "BӮ��" << endl;
		return -1;
	}
	else return 0;
}