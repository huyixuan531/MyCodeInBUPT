#define _CRT_SECURE_NO_WARNINGS
#include"head.h"

//��ʱ������show��Stop��isStop��Start
bool isStop(bool& is_stop)//�жϼ�ʱ״̬
{
	if (is_stop)
		return true;
	return false;
}

void Start(bool& is_stop,long& start_time) //��ʼ��ʱ
{
	if (is_stop)
	{
		start_time = time(0);
		is_stop = false;
	}
}

void Stop(bool& is_stop)  //ֹͣ��ʱ
{
	if (is_stop) //���������ֹͣ״̬�������κδ��� 
		return;
	else if (!is_stop)
	{
		is_stop = true;
	}
}

void show(long& start_time,long& t,bool& is_stop)//��ʾ��ʱʱ��
{
	if (!is_stop) {
		t = time(0) - start_time;
		char ms[5];
		int minu = t / 60;
		sprintf_s(ms,"%3d", minu);
		settextstyle(30, 0, _T("Microsoft Yahei UI Bold"));
		setbkcolor(RGB(251, 248, 241));//������ɫ���ף�
		settextcolor(RGB(250, 128, 114));
		outtextxy(250, 0, ms);
		outtextxy(278, 0, _T("'"));
		char ss[5];
		int sec = t % 60;
		sprintf_s(ss, "%-3d", sec);
		outtextxy(284, 0, ss);
	}
}