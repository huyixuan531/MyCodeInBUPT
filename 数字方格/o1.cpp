#include"head.h"

//��������o1
//���ܣ���ʾ������
void o1()
{//����&����
	initgraph(WIDTH, HEIGHT);//����
	while (1) {
		setbkcolor(RGB(251, 248, 241));//������ɫ���ף�
		settextcolor(RGB(150, 126, 104));//������ɫ���أ�
		cleardevice();//����
		setfont(60, 0, "Microsoft Yahei UI Bold");//��������
		RECT r1 = { 0,0,WIDTH,HEIGHT / 3 };
		drawtext("���ַ���", &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		//��ʼ��Ϸ��
		setfont(40, 0, "Microsoft Yahei UI Bold");
		settextcolor(RGB(79, 79, 79));//������ɫ���ڣ�
		setfillcolor(RGB(250, 128, 114));//���õ�ǰ�������ɫ���ۣ�
		solidroundrect(230, 305, 370, 240, 50, 50);//
		setbkcolor(RGB(250, 128, 114));//������ɫ���ۣ�
		RECT r2 = { WIDTH / 2 - 65,HEIGHT / 2 - 90,WIDTH / 2 + 65,HEIGHT / 2 - 60 };
		drawtext("��ʼ��Ϸ", &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		//����˵����
		setfillcolor(RGB(244, 164, 96));//���õ�ǰ�������ɫ���⣩
		solidroundrect(230, 400, 370, 335, 50, 50);//
		setbkcolor(RGB(244, 164, 96));//������ɫ���⣩
		RECT r4 = { WIDTH / 2 - 65,HEIGHT / 2 + 65 ,WIDTH / 2 + 65,HEIGHT / 3 + 85 };
		drawtext("����˵��", &r4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		//������Ա��
		setfillcolor(RGB(244, 186, 1));//���õ�ǰ�������ɫ���ƣ�
		solidroundrect(230, 495, 370, 430, 50, 50);//
		setbkcolor(RGB(244, 186, 1));//������ɫ���ƣ�
		RECT r5 = { WIDTH / 2 - 65,HEIGHT / 2 + 100,WIDTH / 2 + 65,HEIGHT / 2 + 130 };
		drawtext("������Ա", &r5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		//�˳���
		setfillcolor(RGB(255, 255, 0));//���õ�ǰ�������ɫ�����ƣ�
		solidroundrect(230, 590, 370, 525, 50, 50);//
		setbkcolor(RGB(255, 255, 0));//������ɫ�����ƣ�
		RECT r6 = { WIDTH / 2 - 65,HEIGHT / 2 + 190,WIDTH / 2 + 65,HEIGHT / 2 + 220 };
		drawtext("�˳�", &r6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		//����
		setfillcolor(RGB(244, 164, 96));
		settextstyle(30, 0, "Microsoft Yahei UI Bold");
		solidroundrect(540, 0, 600, 30, 5, 5);
		setbkcolor(RGB(244, 164, 96));
		outtextxy(545, 0, "����");
		bool is_music = true;//�ж������Ƿ����ڲ���
		//��ȡ�����Ϣ
		MOUSEMSG m;
		while (1)
		{
			BeginBatchDraw();//������ͼ
			EndBatchDraw();//����������ͼ
			m = GetMouseMsg();//��ȡ�����Ϣ
			if (m.uMsg == WM_LBUTTONUP)
			{
				if (m.x > 230 && m.x<370 && m.y>240 && m.y < 305) {
					choose(level);//����ѡ�ؽ���
					cleardevice();                                 
					break;
				}
				else if (m.x > 230 && m.x<370 && m.y>335 && m.y <400){
					o2();//�������˵������
					cleardevice();                                 
					break;
				}
				else if (m.x > 230 && m.x<370 && m.y>430 && m.y <495) {
					o3();//���뿪����Ա����
					cleardevice();
					break;
				}
				else if (m.x >230 && m.x<370&& m.y>525 && m.y < 590)
					exit(0);//�˳�����
				else if (m.x > 540 && m.x < 600 && m.y>0 && m.y < 30)//������ͣ��ʼ
				{
					if (is_music) {
						mciSendString("pause music", NULL, 0, NULL);
						is_music = false;
					}
					else if (!is_music) {
						mciSendString("resume music", NULL, 0, NULL);
						is_music = true;
					}
				}
			}
		}
	}
}