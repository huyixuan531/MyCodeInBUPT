#include<iostream>
#include<cstdlib>
#include<ctime>
#include"strategy.h"
#define random(a,b) (rand()%(b-a+1)+a) //random(a,b)����[a,b]��ȡ�������
using namespace std;
//��������Random::strategy
//���ܣ��Բ���������ķ�ʽ�����ȭ
int Random::strategy() {
	srand((unsigned int)time(NULL));//��ʱ�����������
	return random(1,3);//���������ȭ���
}