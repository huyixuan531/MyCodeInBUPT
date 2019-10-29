#include"head.h"

//��������start
//���ܣ���ʾ��Ϸ����
void start(int level)
{//����ռ��matrix1,matrix6,playnum1
	if (level == 1) {
		matrix1 = (int**)malloc(4 * sizeof(int*));
		for (int i = 0; i < 4; i++) {
			matrix1[i] = (int*)malloc(4 * sizeof(int));
		}
		random1(matrix1);
	}
	if (level == 6) {
		matrix6 = (int**)malloc(6 * sizeof(int*));
		for (int i = 0; i < 6; i++) {
			matrix6[i] = (int*)malloc(6 * sizeof(int));
		}
		anum6 = (int**)malloc(6 * sizeof(int*));
		for (int i = 0; i < 6; i++) {
			anum6[i] = (int*)malloc(6 * sizeof(int));
		};
		random6(matrix6, anum6);
	}
	playnum1 = (int**)malloc(10 * sizeof(int*));
	for (int i = 0; i < 10; ++i)
	{
		playnum1[i] = (int*)malloc(10 * sizeof(int));
		for (int j = 0; j < 10; j++) {
			playnum1[i][j] = 0;
		}
	}
	//��ʼ��ʱ
	long start_time;
	bool is_stop = true;//�Ƿ���ֹͣ״̬ 
	long t = 0;           //������ʱ��
	Start(is_stop, start_time);
	//������Ϸ����
	setbkcolor(RGB(251, 248, 241));//������ɫ���ף�
	settextcolor(RGB(79, 79, 79));//������ɫ���ڣ�
	cleardevice();//����
	setfillcolor(RGB(0, 0, 0));//���õ�ǰ�������ɫ�����ڣ�
	solidrectangle(30, 30, 570, 570);
	setfillcolor(RGB(244, 164, 96));//���õ�ǰ�������ɫ���⣩
	solidroundrect(0, 30, 60, 0, 5, 5);
	setbkcolor(RGB(244, 164, 96));//������ɫ���⣩
	RECT r6 = { 0, 0 ,60,30 };
	setfont(30, 0, "Microsoft Yahei UI Bold");
	drawtext("����", &r6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	setfillcolor(RGB(255, 255, 0));//���õ�ǰ�������ɫ�����ƣ�
	solidroundrect(150, 600, 250, 650, 10, 10);
	setbkcolor(RGB(255, 255, 0));//������ɫ�����ƣ�
	RECT r8 = { 150, 600, 250, 650 };
	drawtext("����", &r8, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	setfillcolor(RGB(255, 255, 0));//���õ�ǰ�������ɫ�����ƣ�
	solidroundrect(350, 600, 450, 650, 10, 10);
	setbkcolor(RGB(255, 255, 0));//������ɫ�����ƣ�
	RECT r7 = { 350, 600, 450, 650 };
	drawtext("ȷ�����", &r7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	map(level);//��ʾ���ַ���
	COOR	 coor;
	int flag[10][10] = { 0 };//ÿ�������Ƿ񱻰��£���ɫΪ0����ɫΪ1
	//��ȡ�����Ϣ
	MOUSEMSG m;
	while (1)
	{
		if (MouseHit())
		{
			m = GetMouseMsg();
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				if (m.x > 0 && m.x < 60 && m.y>0 && m.y < 30)
					return;//����ѡ�ؽ���
				if (m.x > 350 && m.x < 450 && m.y > 600 && m.y < 650) {
					Stop(is_stop);//ȷ�ϱ�����ɣ�ֹͣ��ʱ
					evaluate(grade(level, t, judge(level, playnum1)), level); //�������۽���
					return;
				}
				if (m.x > 30 && m.x < 570 && m.y>30 && m.y < 570) {
					numbutton(m, coor, level);//��¼��Ұ���˳��
					if (flag[coor.a][coor.b] == 0) {
						store(coor, playnum1, level);//�洢��Ұ���˳��
						flag[coor.a][coor.b] = 1;//�ı䷽��flag
						changecolor(level, coor.a, coor.b);//�ı䷽����ɫ
					}
				}
				//��������ã���flagȫ��0���ػ�ȫ����ɫ����
				if (m.x > 150 && m.x < 250 && m.y > 600 && m.y < 650) {
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < 10; j++) {
							flag[i][j] = 0;
							playnum1[i][j] = 0;
							step1 = 0; step2 = 0;
						}
					}
					map(level);
				}
			}
		}
		else {//���������ɰ�ť����һֱ��¼����ʾʱ��
			if (!isStop(is_stop))
			{
				show(start_time, t, is_stop);
			}
		}
	}
}
