#include"head.h"
using namespace std;

//��������lead
//���ܣ���ʾѡ�ؽ���
void lead(int* a) {
	setbkcolor(RGB(251, 248, 241));//���ñ���ɫ
	cleardevice();
	setfillcolor(RGB(244, 186, 1));//�ؿ���ɫ
	solidroundrect(66, 25, 266, 225, 50, 50);
	setfillcolor(RGB(216, 191, 216));//�ؿ���ɫ
	solidroundrect(332, 25, 532, 225, 50, 50);
	solidroundrect(66, 250, 266, 450, 50, 50);
	solidroundrect(332, 250, 532, 450, 50, 50);
	solidroundrect(66, 475, 266, 675, 50, 50);
	solidroundrect(332, 475, 532, 675, 50, 50);
	settextcolor(RGB(79, 79, 79));//����������ɫ��ʽ
	settextstyle(50, 0, "Microsoft Yahei UI Bold");
	setbkcolor(RGB(216, 191, 216));
	outtextxy(110, 105, "��һ��");
	outtextxy(376, 105, "�ڶ���");
	outtextxy(110, 330, "������");
	outtextxy(376, 330, "���Ĺ�");
	outtextxy(110, 555, "�����");
	outtextxy(376, 555, "������");
	//���ؼ�
	setfillcolor(RGB(244, 164, 96));//���õ�ǰ�������ɫ���⣩
	solidroundrect(0, 30, 60, 0, 5, 5);//
	setbkcolor(RGB(244, 164, 96));//������ɫ���⣩
	RECT r6 = { 0, 0 ,60,30 };
	setfont(30, 0, "Microsoft Yahei UI Bold");
	settextcolor(RGB(79, 79, 79));//������ɫ���ڣ�
	drawtext("����", &r6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	searchif(a);//��Ȿ���Ƿ����
}

//��������searchif
//���ܣ����ؿ��Ƿ����
int* searchif(int *a) {
	int line[100];
	settextstyle(50, 0, "Microsoft Yahei UI Bold");
	ifstream fr("ifcomp.txt");
	for (int i = 0; i < 100; i++)//���ļ������ÿ���Ƿ����
	{
		if (!fr) {
			line[i] = 0;
		}
		fr >> line[i];
	}
	fr.close();
	//�ؿ�����
	setfillcolor(RGB(244, 186, 1));
	solidroundrect(66, 25, 266, 225, 50, 50);
	setbkcolor(RGB(244, 186, 1));
	outtextxy(110, 105, "��һ��");
	for (int i = 0; i < 100; i++) {
		if (line[i] == 2) {
			setfillcolor(RGB(244, 186, 1));
			solidroundrect(332, 25, 532, 225, 50, 50);
			setbkcolor(RGB(244, 186, 1));
			outtextxy(376, 105, "�ڶ���");
			a[2] = 1;//����������a[x]��Ϊ1
		}
		else if (line[i] == 3) {
			setfillcolor(RGB(244, 186, 1));
			solidroundrect(66, 250, 266, 450, 50, 50);
			setbkcolor(RGB(244, 186, 1));
			outtextxy(110, 330, "������");
			a[3] = 1;
		}
		else if (line[i] == 4) {
			setfillcolor(RGB(244, 186, 1));
			solidroundrect(332, 250, 532, 450, 50, 50);
			setbkcolor(RGB(244, 186, 1));
			outtextxy(376, 330, "���Ĺ�");
			a[4] = 1;
		}
		else if (line[i] == 5) {
			setfillcolor(RGB(244, 186, 1));
			solidroundrect(66, 475, 266, 675, 50, 50);
			setbkcolor(RGB(244, 186, 1));
			outtextxy(110, 555, "�����");
			a[5] = 1;
		}
		else if (line[i] == 6) {
			setfillcolor(RGB(244, 186, 1));
			solidroundrect(332, 475, 532, 675, 50, 50);
			setbkcolor(RGB(244, 186, 1));
			outtextxy(376, 555, "������");
			a[6] = 1;
		}
	}
	return a;
}

//��������Gotoplay
//���ܣ�����ؿ�
void Gotoplay(int* a,int& level)
{
	MOUSEMSG m;
	while (1)
	{
		BeginBatchDraw();
		EndBatchDraw();
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN && m.x > 66 && m.x < 266 && m.y>25 && m.y < 225)//��ť��ɫ
		{
			setfillcolor(RGB(202, 151, 18));
			settextstyle(50, 0, "Microsoft Yahei UI Bold");
			setbkcolor(RGB(202, 151, 18));
			solidroundrect(66, 25, 266, 225, 50, 50);
			outtextxy(110, 105, "��һ��");
		}
		if (m.uMsg == WM_LBUTTONUP && m.x > 66 && m.x < 266 && m.y>25 && m.y < 225)//������Ϸ
		{//�����һ��
			level = 1;
			break;
		}
		if (a[2] == 1 && m.uMsg == WM_LBUTTONDOWN && m.x > 332 && m.x < 532 && m.y>25 && m.y < 225)
		{
			setfillcolor(RGB(202, 151, 18));
			settextstyle(50, 0, "Microsoft Yahei UI Bold");
			setbkcolor(RGB(202, 151, 18));
			solidroundrect(332, 25, 532, 225, 50, 50);
			outtextxy(376, 105, "�ڶ���");
		}
		if (a[2] == 1 && m.uMsg == WM_LBUTTONUP && m.x > 332 && m.x < 532 && m.y>25 && m.y < 225)
		{//���������־a[2]=1������ڶ���
			level = 2;
			break;
		}
		if (a[3] == 1 && m.uMsg == WM_LBUTTONDOWN && m.x > 66 && m.x < 266 && m.y>250 && m.y < 450)
		{
			setfillcolor(RGB(202, 151, 18));
			settextstyle(50, 0, "Microsoft Yahei UI Bold");
			setbkcolor(RGB(202, 151, 18));
			solidroundrect(66, 250, 266, 450, 50, 50);
			outtextxy(110, 330, "������");
		}
		if (a[3] == 1 && m.uMsg == WM_LBUTTONUP && m.x > 66 && m.x < 266 && m.y>250 && m.y < 450)
		{//���������
			level = 3;
			break;
		}
		if (a[4] == 1 && m.uMsg == WM_LBUTTONDOWN && m.x > 332 && m.x < 532 && m.y>250 && m.y < 450)
		{
			setfillcolor(RGB(202, 151, 18));
			settextstyle(50, 0, "Microsoft Yahei UI Bold");
			setbkcolor(RGB(202, 151, 18));
			solidroundrect(332, 250, 532, 450, 50, 50);
			outtextxy(376, 330, "���Ĺ�");
		}
		if (a[4] == 1 && m.uMsg == WM_LBUTTONUP && m.x > 332 && m.x < 532 && m.y>250 && m.y < 450)
		{//������Ĺ�
			level = 4;
			break;
		}
		if (a[5] == 1 && m.uMsg == WM_LBUTTONDOWN && m.x > 66 && m.x < 266 && m.y>475 && m.y < 675)
		{
			setfillcolor(RGB(202, 151, 18));
			settextstyle(50, 0, "Microsoft Yahei UI Bold");
			setbkcolor(RGB(202, 151, 18));
			solidroundrect(66, 475, 266, 675, 50, 50);
			outtextxy(110, 555, "�����");
		}
		if (a[5] == 1 && m.uMsg == WM_LBUTTONUP && m.x > 66 && m.x < 266 && m.y>475 && m.y < 675)
		{//��������
			level = 5;
			break;
		}
		if (a[6] == 1 && m.uMsg == WM_LBUTTONDOWN && m.x > 332 && m.x < 532 && m.y>475 && m.y < 675)
		{
			setfillcolor(RGB(202, 151, 18));
			settextstyle(50, 0, "Microsoft Yahei UI Bold");
			setbkcolor(RGB(202, 151, 18));
			solidroundrect(332, 475, 532, 675, 50, 50);
			outtextxy(376, 555, "������");

		}
		if (a[6] == 1 && m.uMsg == WM_LBUTTONUP && m.x > 332 && m.x < 532 && m.y>475 && m.y < 675)
		{//���������
			level = 6;
			break;
		}
		if (m.uMsg == WM_LBUTTONDOWN && m.x > 0 && m.x < 60 && m.y>0 && m.y < 30)
		{
			return ;//����������
		}
	}
}

//��������choose
//���ܣ�����ѡ�ؽ���
void choose(int& level)
{
	int a[7];
	while (1) {
		level = 0;
		lead(a);//��ʾѡ�ؽ���
		Gotoplay(a, level);//����ؿ�
		if (!level)                                                   
			return;
		else
			rule();    //չʾ����                                            
	}
}