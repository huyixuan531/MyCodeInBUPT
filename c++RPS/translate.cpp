#include<iostream>
#include"strategy.h"
using namespace std;
//��������translate
//���ܣ�������ʯͷ����������������������1��2��3����������Ա���ʾ
string translate(int i) {
	if (i == 1)
		return "ʯͷ";//1����ʯͷ
	else if (i == 2)
		return "����";//2��������
	else if (i == 3)
		return "��  ";//3������
	else return "ERROR!";//������������
}