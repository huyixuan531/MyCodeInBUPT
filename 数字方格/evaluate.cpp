#include "head.h"
using namespace std;

//��������evaluate
//���ܣ���ʾ���۽���
void evaluate(int score,int level) {
	char b[10];
	if (score >= 60) {
		ofstream  fwlevel("ifcomp.txt",ios::app);//ͨ�أ�����60�֣������ļ�д�룬�Խ�����һ��
		switch (level) {
		case 1:fwlevel << 2 << endl; break;
		case 2:fwlevel << 3 << endl; break;
		case 3:fwlevel << 4 << endl; break;
		case 4:fwlevel << 5 << endl; break;
		case 5:fwlevel << 6 << endl; break;
		}
	}
	ofstream  fwscore;//���ļ�д�����
	switch (level) {
	case 1:fwscore.open("score1.txt", ios::app); break;
	case 2:fwscore.open("score2.txt",ios::app); break;
	case 3:fwscore.open("score3.txt", ios::app); break;
	case 4:fwscore.open("score4.txt", ios::app); break;
	case 5:fwscore.open("score5.txt", ios::app); break;
	case 6:fwscore.open("score6.txt", ios::app); break;
	}
	if (fwscore.fail()) {
		outtextxy(300, 400, "�޷����ļ�");
	}
	fwscore << score <<endl;
	fwscore.close();

	setbkcolor(RGB(251, 248, 241));
	settextcolor(RGB(251, 248, 241));
	cleardevice();
	settextstyle(70, 0, "Microsoft Yahei UI Bold");//��������
	settextcolor(RGB(245, 222, 179));
	setbkcolor(RGB(251, 248, 241));  //�������屳��
	outtextxy(170, 25, "�÷֣�");//����ַ����÷�
	if (1) {
		_itoa(score, b, 10);
		outtextxy(325, 25, b);//����ַ����÷�
	}
	//�������
	settextstyle(40, 0, "Microsoft Yahei UI Bold");//��������
	if (score >= 90&&score<=100)
		outtextxy(240, 115, "�������");
	else if (score>70)
		outtextxy(180, 115, "��������Ŭ����");
	else if(score>60)
		outtextxy(190, 115, "��Ҫ�ټ���Ŷ��");
	else
		outtextxy(105, 115, "�ﵽ60�ֲ��ܽ�����һ��Ŷ");

	setfillcolor(RGB(253, 245, 230));
	solidroundrect(100, 200, 500, 575, 5, 5);//��ʷ��¼������
	settextstyle(20, 0, "Microsoft Yahei UI Bold");//��������
	settextcolor(RGB(79, 79, 79));
	setbkcolor(RGB(253, 245, 230));
	outtextxy(WIDTH / 2 - 55, 210, "< ��ʷ��¼ >");
	outtextxy(120, 250, "��¼");
	outtextxy(444, 250, "�÷�");
	fopen(level); //���ļ���ȡ��¼
	//��ɼ�
	settextstyle(30, 0, "Microsoft Yahei UI Bold");//��������
	setfillcolor(RGB(255, 222, 173));
	solidroundrect(250, 600, 350, 650, 5, 5);
	settextcolor(RGB(79, 79, 79));
	setbkcolor(RGB(255, 222, 173));
	outtextxy(278, 610, "���");
	//��ȡ�����Ϣ
	MOUSEMSG m;
	while (1)
	{
		BeginBatchDraw();//������ͼ
		EndBatchDraw();//����������ͼ
		if (MouseHit()) {
			m = GetMouseMsg();//��ȡ�����Ϣ
			if (m.uMsg == WM_LBUTTONUP && m.x > 250 && m.y > 600 && m.x < 350 && m.y < 650) {                 //���
				//if (m.uMsg == WM_LBUTTONUP && m.x > 250 && m.y > 600 && m.x < 350 && m.y < 650) {
					return;
			}
		}
	}
}

//��������fopen
//���ܣ���ȡ��ʷ�ɼ��ļ�
void fopen(int level) {
	int a[100];
	for(int i=0;i<100;i++){
		a[i] = -1;
	}
	char b[100];
	char c[3];
	ifstream fscore;
	switch (level) {//�򿪶�Ӧ�ؿ��ļ�
	case 1:fscore.open("score1.txt"); break;
	case 2:fscore.open("score2.txt"); break;
	case 3:fscore.open("score3.txt"); break;
	case 4:fscore.open("score4.txt"); break;
	case 5:fscore.open("score5.txt"); break;
	case 6:fscore.open("score6.txt"); break;
	}
	int i = 0;
	if (fscore.fail()) {
		outtextxy(300, 400, "�޷����ļ�");
	}
	for (int i = 0; i < 100; i++)
		fscore >> a[i];//���ļ�
	int sum1 = 0,sum2=0;
	int max = 0;
	int at[10];
	for (int i = 100; i >= 0; i--) {//��ʷ��߷�
		if (a[i] >= 0 && a[i] <= 100) {
			if (a[i] > max)max = a[i];
			sum1++;
		}
	}
	for (int i = 0; i <10; i++) {
		if (a[sum1 - 1]>=0) {
			at[i] = a[sum1 - 1];
			sum1--;
			sum2++;
		}
	}
	for (int i = 0; i < sum2; i++) {//����ļ�����
		_itoa(i + 1, c, 10);
		outtextxy(130, 280 + 25 * i, c);
		outtextxy(150, 280 + 25 * i, "������������������������������������");
		_itoa(at[i], b, 10);
		outtextxy(450, 280 + 25 * i, b);
	}
	settextstyle(25, 0, "Microsoft Yahei UI Bold");
	outtextxy(130, 535, "��ʷ��߷֣�");
	_itoa(max, b, 10);
	outtextxy(240, 535, b);
	fscore.close();
}
