#include"head.h"

//����ѭ������ʵ��Լɪ������
int main() {
	int peopleNumber, deleteNumber, overNumber;
	cout << "��ӭ����Լɪ�����⣡\n-----------------------------"<<endl;
	cout << "�����뱨������m��\n";
	cin >> overNumber;
	cout << "��������������\n";
	cin >> peopleNumber;
	cout << "�������һ����ɾ���ߵı�ţ�\n";
	cin >> deleteNumber;
	Joseph J1(peopleNumber, deleteNumber, overNumber);//����ѭ������
	J1.game();//��ʼ����ɾ��˳��
	return 0;
}