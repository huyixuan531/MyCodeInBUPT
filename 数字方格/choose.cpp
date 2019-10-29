#include"head.h"
using namespace std;

//函数名：lead
//功能：显示选关界面
void lead(int* a) {
	setbkcolor(RGB(251, 248, 241));//设置背景色
	cleardevice();
	setfillcolor(RGB(244, 186, 1));//关卡底色
	solidroundrect(66, 25, 266, 225, 50, 50);
	setfillcolor(RGB(216, 191, 216));//关卡底色
	solidroundrect(332, 25, 532, 225, 50, 50);
	solidroundrect(66, 250, 266, 450, 50, 50);
	solidroundrect(332, 250, 532, 450, 50, 50);
	solidroundrect(66, 475, 266, 675, 50, 50);
	solidroundrect(332, 475, 532, 675, 50, 50);
	settextcolor(RGB(79, 79, 79));//设置字体颜色样式
	settextstyle(50, 0, "Microsoft Yahei UI Bold");
	setbkcolor(RGB(216, 191, 216));
	outtextxy(110, 105, "第一关");
	outtextxy(376, 105, "第二关");
	outtextxy(110, 330, "第三关");
	outtextxy(376, 330, "第四关");
	outtextxy(110, 555, "第五关");
	outtextxy(376, 555, "第六关");
	//返回键
	setfillcolor(RGB(244, 164, 96));//设置当前的填充颜色（肉）
	solidroundrect(0, 30, 60, 0, 5, 5);//
	setbkcolor(RGB(244, 164, 96));//背景颜色（肉）
	RECT r6 = { 0, 0 ,60,30 };
	setfont(30, 0, "Microsoft Yahei UI Bold");
	settextcolor(RGB(79, 79, 79));//字体颜色（黑）
	drawtext("返回", &r6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	searchif(a);//检测本关是否解锁
}

//函数名：searchif
//功能：检测关卡是否解锁
int* searchif(int *a) {
	int line[100];
	settextstyle(50, 0, "Microsoft Yahei UI Bold");
	ifstream fr("ifcomp.txt");
	for (int i = 0; i < 100; i++)//读文件，检测每关是否解锁
	{
		if (!fr) {
			line[i] = 0;
		}
		fr >> line[i];
	}
	fr.close();
	//关卡按键
	setfillcolor(RGB(244, 186, 1));
	solidroundrect(66, 25, 266, 225, 50, 50);
	setbkcolor(RGB(244, 186, 1));
	outtextxy(110, 105, "第一关");
	for (int i = 0; i < 100; i++) {
		if (line[i] == 2) {
			setfillcolor(RGB(244, 186, 1));
			solidroundrect(332, 25, 532, 225, 50, 50);
			setbkcolor(RGB(244, 186, 1));
			outtextxy(376, 105, "第二关");
			a[2] = 1;//若解锁，则将a[x]改为1
		}
		else if (line[i] == 3) {
			setfillcolor(RGB(244, 186, 1));
			solidroundrect(66, 250, 266, 450, 50, 50);
			setbkcolor(RGB(244, 186, 1));
			outtextxy(110, 330, "第三关");
			a[3] = 1;
		}
		else if (line[i] == 4) {
			setfillcolor(RGB(244, 186, 1));
			solidroundrect(332, 250, 532, 450, 50, 50);
			setbkcolor(RGB(244, 186, 1));
			outtextxy(376, 330, "第四关");
			a[4] = 1;
		}
		else if (line[i] == 5) {
			setfillcolor(RGB(244, 186, 1));
			solidroundrect(66, 475, 266, 675, 50, 50);
			setbkcolor(RGB(244, 186, 1));
			outtextxy(110, 555, "第五关");
			a[5] = 1;
		}
		else if (line[i] == 6) {
			setfillcolor(RGB(244, 186, 1));
			solidroundrect(332, 475, 532, 675, 50, 50);
			setbkcolor(RGB(244, 186, 1));
			outtextxy(376, 555, "第六关");
			a[6] = 1;
		}
	}
	return a;
}

//函数名：Gotoplay
//功能：进入关卡
void Gotoplay(int* a,int& level)
{
	MOUSEMSG m;
	while (1)
	{
		BeginBatchDraw();
		EndBatchDraw();
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN && m.x > 66 && m.x < 266 && m.y>25 && m.y < 225)//按钮变色
		{
			setfillcolor(RGB(202, 151, 18));
			settextstyle(50, 0, "Microsoft Yahei UI Bold");
			setbkcolor(RGB(202, 151, 18));
			solidroundrect(66, 25, 266, 225, 50, 50);
			outtextxy(110, 105, "第一关");
		}
		if (m.uMsg == WM_LBUTTONUP && m.x > 66 && m.x < 266 && m.y>25 && m.y < 225)//进入游戏
		{//进入第一关
			level = 1;
			break;
		}
		if (a[2] == 1 && m.uMsg == WM_LBUTTONDOWN && m.x > 332 && m.x < 532 && m.y>25 && m.y < 225)
		{
			setfillcolor(RGB(202, 151, 18));
			settextstyle(50, 0, "Microsoft Yahei UI Bold");
			setbkcolor(RGB(202, 151, 18));
			solidroundrect(332, 25, 532, 225, 50, 50);
			outtextxy(376, 105, "第二关");
		}
		if (a[2] == 1 && m.uMsg == WM_LBUTTONUP && m.x > 332 && m.x < 532 && m.y>25 && m.y < 225)
		{//如果解锁标志a[2]=1，进入第二关
			level = 2;
			break;
		}
		if (a[3] == 1 && m.uMsg == WM_LBUTTONDOWN && m.x > 66 && m.x < 266 && m.y>250 && m.y < 450)
		{
			setfillcolor(RGB(202, 151, 18));
			settextstyle(50, 0, "Microsoft Yahei UI Bold");
			setbkcolor(RGB(202, 151, 18));
			solidroundrect(66, 250, 266, 450, 50, 50);
			outtextxy(110, 330, "第三关");
		}
		if (a[3] == 1 && m.uMsg == WM_LBUTTONUP && m.x > 66 && m.x < 266 && m.y>250 && m.y < 450)
		{//进入第三关
			level = 3;
			break;
		}
		if (a[4] == 1 && m.uMsg == WM_LBUTTONDOWN && m.x > 332 && m.x < 532 && m.y>250 && m.y < 450)
		{
			setfillcolor(RGB(202, 151, 18));
			settextstyle(50, 0, "Microsoft Yahei UI Bold");
			setbkcolor(RGB(202, 151, 18));
			solidroundrect(332, 250, 532, 450, 50, 50);
			outtextxy(376, 330, "第四关");
		}
		if (a[4] == 1 && m.uMsg == WM_LBUTTONUP && m.x > 332 && m.x < 532 && m.y>250 && m.y < 450)
		{//进入第四关
			level = 4;
			break;
		}
		if (a[5] == 1 && m.uMsg == WM_LBUTTONDOWN && m.x > 66 && m.x < 266 && m.y>475 && m.y < 675)
		{
			setfillcolor(RGB(202, 151, 18));
			settextstyle(50, 0, "Microsoft Yahei UI Bold");
			setbkcolor(RGB(202, 151, 18));
			solidroundrect(66, 475, 266, 675, 50, 50);
			outtextxy(110, 555, "第五关");
		}
		if (a[5] == 1 && m.uMsg == WM_LBUTTONUP && m.x > 66 && m.x < 266 && m.y>475 && m.y < 675)
		{//进入第五关
			level = 5;
			break;
		}
		if (a[6] == 1 && m.uMsg == WM_LBUTTONDOWN && m.x > 332 && m.x < 532 && m.y>475 && m.y < 675)
		{
			setfillcolor(RGB(202, 151, 18));
			settextstyle(50, 0, "Microsoft Yahei UI Bold");
			setbkcolor(RGB(202, 151, 18));
			solidroundrect(332, 475, 532, 675, 50, 50);
			outtextxy(376, 555, "第六关");

		}
		if (a[6] == 1 && m.uMsg == WM_LBUTTONUP && m.x > 332 && m.x < 532 && m.y>475 && m.y < 675)
		{//进入第六关
			level = 6;
			break;
		}
		if (m.uMsg == WM_LBUTTONDOWN && m.x > 0 && m.x < 60 && m.y>0 && m.y < 30)
		{
			return ;//返回主界面
		}
	}
}

//函数名：choose
//功能：进入选关界面
void choose(int& level)
{
	int a[7];
	while (1) {
		level = 0;
		lead(a);//显示选关界面
		Gotoplay(a, level);//进入关卡
		if (!level)                                                   
			return;
		else
			rule();    //展示规则                                            
	}
}