#include"head.h"

//函数名：o3
//功能：显示开发人员界面
void o3()
{
	setbkcolor(RGB(251, 248, 241));//背景颜色（米）
	settextcolor(RGB(150, 126, 104));//字体颜色（棕）
	cleardevice();//清屏
	RECT C2 = { 60,60,640,790 };
	drawtext("\n\n\n\n开发人员：\n\n谢彤\n邱雅颖\n胡亦璇\n", &C2, DT_WORDBREAK);
	//返回键
	setfillcolor(RGB(244, 164, 96));//设置当前的填充颜色（肉）
	solidroundrect(0, 30, 60, 0, 5, 5);//
	setbkcolor(RGB(244, 164, 96));//背景颜色（肉）
	RECT r6 = { 0, 0 ,60,30 };
	setfont(30, 0, "Microsoft Yahei UI Bold");
	settextcolor(RGB(79, 79, 79));
	drawtext("返回", &r6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	//获取鼠标信息
	MOUSEMSG m;
	while (1)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			if (m.x > 0 && m.x < 60 && m.y>0 && m.y < 60)
				return;//返回主界面
		}
	}
}