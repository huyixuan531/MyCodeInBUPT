#include"head.h"

//��������rule
//���ܣ�ÿ��ǰ��ʾ���ع������
void rule() {
	setbkcolor(RGB(251, 248, 241));//������ɫ���ף�
	settextcolor(RGB(150, 126, 104));//������ɫ���أ�
	cleardevice();//����
	RECT C1 = { 60,60,540,440 };
	switch (level) {//���ݲ�ͬ�ؿ���ʾ��ͬ����
	case 1:drawtext("�ؿ�1��\n\n�밴����С�����˳�����ε��ͼ�е�����\n", &C1, DT_WORDBREAK);
		break;
	case 2:drawtext("�ؿ�2��\n\n���ҳ������ͼ�����е�6\n", &C1, DT_WORDBREAK);
		break;
	case 3:drawtext("�ؿ�3��\n\n�ҳ������ͼ�����У�\n����7ǰһλ�ģ�����3�ı��������֡�\n������ 6 7 �е�6��\n", &C1, DT_WORDBREAK);
		break;
	case 4:drawtext("�ؿ�4��\n\n�ҳ������ͼ�����У�\n����һλ����3����7\n������ 7 8 �е�7��\n", &C1, DT_WORDBREAK);
		break;
	case 5:drawtext("�ؿ�5��\n\n�ҳ������ͼ�����У�\n����3��С��7��ż��\n", &C1, DT_WORDBREAK);
		break;
	case 6:drawtext("�ؿ�6��\n\n�밴����С�����˳�����ε��ͼ�е�����\n", &C1, DT_WORDBREAK);
		break;
	}
	//���ؼ�
	setfillcolor(RGB(244, 164, 96));//���õ�ǰ�������ɫ���⣩
	solidroundrect(0, 30, 60, 0, 5, 5);//
	setbkcolor(RGB(244, 164, 96));//������ɫ���⣩
	RECT r6 = { 0, 0 ,60,30 };
	setfont(30, 0, "Microsoft Yahei UI Bold");
	settextcolor(RGB(79, 79, 79));//������ɫ���ڣ�
	drawtext("����", &r6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	//��ʼ��Ϸ��
	setfillcolor(RGB(250, 128, 114));//���õ�ǰ�������ɫ���⣩
	solidroundrect(200, HEIGHT - 150, WIDTH - 200, HEIGHT - 50, 50, 50);//
	setbkcolor(RGB(250, 128, 114));//������ɫ���⣩
	RECT R1 = { 2,HEIGHT - 200,WIDTH - 2,HEIGHT - 2 };
	setfont(40, 0, "Microsoft Yahei UI Bold");
	settextcolor(RGB(79, 79, 79));//������ɫ���ڣ�
	drawtext("��ʼ������Ϸ", &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	//��ȡ�����Ϣ
	MOUSEMSG m;
	while (1)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			if (m.x > 0 && m.x < 60 && m.y>0 && m.y < 30) {
				level=0;
				return ;//����ѡ�ؽ���
			}
			if (m.x > 2 && m.x < WIDTH - 2 && m.y > HEIGHT - 200 && m.y < HEIGHT - 2) {
				step1 = 0;
				step2 = 0;
				start(level);//�����level��
				return;
			}
		}
	}
}