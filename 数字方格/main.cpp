#define _CRT_SECURE_NO_WARNINGS
#include"head.h"
#include <cstdlib>

int** playnum1;//������㷽��˳��
int** anum6;//�����ش�
int** matrix1;//��1��6��������ɾ���
int** matrix6;
int step1 = 0, step2 = 0;//����һ��numbutton��step1,step2�ı�һ��
int level = 0;

int main(void)
{
	mciSendString(TEXT("open bgm.mp3 alias music"), NULL, 0, NULL);//ѭ�����ű�������
	mciSendString(TEXT("play music repeat"), NULL, 0, NULL);
	o1();//��ʾ��Ϸ������
	return 0;
}





