#include"head.h"

//��������o2
//���ܣ���ʾ����˵������
void o2()
{
	setbkcolor(RGB(251, 248, 241));//������ɫ���ף�
	settextcolor(RGB(150, 126, 104));//������ɫ���أ�
	cleardevice();//����
	RECT C1 = { 60,20,600,790 };
	drawtext("\n\n\n����˵����\n\n���ͨ����������в�����\n����ÿ��ǰ���ֵ���Ϸ����\n������Ӧ��Ѱ����Ϸ��\nÿ���ؿ������ʱ��\n��������á���ť�����ñ�����Ϸ��\n�������ɱ��������\n��ʱ�����ȷ����ɡ���ť�����ύ��\n", &C1, DT_WORDBREAK);
	//���ؼ�
	setfillcolor(RGB(244, 164, 96));//���õ�ǰ�������ɫ���⣩
	solidroundrect(0, 30, 60, 0, 5, 5);//
	setbkcolor(RGB(244, 164, 96));//������ɫ���⣩
	RECT r6 = { 0, 0 ,60,30 };
	setfont(30, 0, "Microsoft Yahei UI Bold");
	settextcolor(RGB(79, 79, 79));
	drawtext("����", &r6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	//��ȡ�����Ϣ
	MOUSEMSG m;
	while (1)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			if (m.x > 0 && m.x < 60 && m.y>0 && m.y < 30)
				return ;//����������
		}
	}
}