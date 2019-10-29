#define _CRT_SECURE_NO_WARNINGS
#include"head.h"

//计时函数：show，Stop，isStop，Start
bool isStop(bool& is_stop)//判断计时状态
{
	if (is_stop)
		return true;
	return false;
}

void Start(bool& is_stop,long& start_time) //开始计时
{
	if (is_stop)
	{
		start_time = time(0);
		is_stop = false;
	}
}

void Stop(bool& is_stop)  //停止计时
{
	if (is_stop) //如果正处于停止状态，不做任何处理 
		return;
	else if (!is_stop)
	{
		is_stop = true;
	}
}

void show(long& start_time,long& t,bool& is_stop)//显示计时时间
{
	if (!is_stop) {
		t = time(0) - start_time;
		char ms[5];
		int minu = t / 60;
		sprintf_s(ms,"%3d", minu);
		settextstyle(30, 0, _T("Microsoft Yahei UI Bold"));
		setbkcolor(RGB(251, 248, 241));//背景颜色（米）
		settextcolor(RGB(250, 128, 114));
		outtextxy(250, 0, ms);
		outtextxy(278, 0, _T("'"));
		char ss[5];
		int sec = t % 60;
		sprintf_s(ss, "%-3d", sec);
		outtextxy(284, 0, ss);
	}
}