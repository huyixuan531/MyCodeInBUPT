#include"play.h"
int main() {
	Game game_v;
	cout << "��ӭ����ʯͷ��������Ϸ��"<<endl;
	cout << "��ѡ����Ϸģʽ��" << endl;//op1ѡ���սģʽ
	cout << "1.�˻���ս��2.�����ڲ���ս" << endl;
	while (1) {//ѭ���������벻�Ϸ�
		cin >> game_v.op1;
		if ((game_v.op1 == 1) || (game_v.op1 == 2))
			break;
		else cout << "���벻�Ϸ������������룺" << endl;
	}
	play(game_v.op1, game_v);//��ʼ��Ϸ
	return 0;
}