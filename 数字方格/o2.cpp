#include"head.h"

//函数名：o2
//功能：显示操作说明界面
void o2()
{
	setbkcolor(RGB(251, 248, 241));//背景颜色（米）
	settextcolor(RGB(150, 126, 104));//字体颜色（棕）
	cleardevice();//清屏
	RECT C1 = { 60,20,600,790 };
	drawtext("\n\n\n操作说明：\n\n玩家通过鼠标点击进行操作，\n根据每关前出现的游戏规则\n进行相应的寻数游戏。\n每个关卡将会计时，\n点击“重置”按钮可重置本关游戏。\n请玩家完成本关任务后\n及时点击“确定完成”按钮进行提交。\n", &C1, DT_WORDBREAK);
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
			if (m.x > 0 && m.x < 60 && m.y>0 && m.y < 30)
				return ;//返回主界面
		}
	}
}