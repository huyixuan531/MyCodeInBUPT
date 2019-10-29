#include"head.h"

//函数名：rule
//功能：每关前显示本关规则界面
void rule() {
	setbkcolor(RGB(251, 248, 241));//背景颜色（米）
	settextcolor(RGB(150, 126, 104));//字体颜色（棕）
	cleardevice();//清屏
	RECT C1 = { 60,60,540,440 };
	switch (level) {//根据不同关卡显示不同规则
	case 1:drawtext("关卡1：\n\n请按照由小到大的顺序依次点击图中的数字\n", &C1, DT_WORDBREAK);
		break;
	case 2:drawtext("关卡2：\n\n请找出并点击图中所有的6\n", &C1, DT_WORDBREAK);
		break;
	case 3:drawtext("关卡3：\n\n找出并点击图中所有：\n“在7前一位的，且是3的倍数的数字”\n（例如 6 7 中的6）\n", &C1, DT_WORDBREAK);
		break;
	case 4:drawtext("关卡4：\n\n找出并点击图中所有：\n“后一位不是3”的7\n（例如 7 8 中的7）\n", &C1, DT_WORDBREAK);
		break;
	case 5:drawtext("关卡5：\n\n找出并点击图中所有：\n大于3且小于7的偶数\n", &C1, DT_WORDBREAK);
		break;
	case 6:drawtext("关卡6：\n\n请按照由小到大的顺序依次点击图中的数字\n", &C1, DT_WORDBREAK);
		break;
	}
	//返回键
	setfillcolor(RGB(244, 164, 96));//设置当前的填充颜色（肉）
	solidroundrect(0, 30, 60, 0, 5, 5);//
	setbkcolor(RGB(244, 164, 96));//背景颜色（肉）
	RECT r6 = { 0, 0 ,60,30 };
	setfont(30, 0, "Microsoft Yahei UI Bold");
	settextcolor(RGB(79, 79, 79));//字体颜色（黑）
	drawtext("返回", &r6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	//开始游戏键
	setfillcolor(RGB(250, 128, 114));//设置当前的填充颜色（肉）
	solidroundrect(200, HEIGHT - 150, WIDTH - 200, HEIGHT - 50, 50, 50);//
	setbkcolor(RGB(250, 128, 114));//背景颜色（肉）
	RECT R1 = { 2,HEIGHT - 200,WIDTH - 2,HEIGHT - 2 };
	setfont(40, 0, "Microsoft Yahei UI Bold");
	settextcolor(RGB(79, 79, 79));//字体颜色（黑）
	drawtext("开始本关游戏", &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	//获取鼠标信息
	MOUSEMSG m;
	while (1)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			if (m.x > 0 && m.x < 60 && m.y>0 && m.y < 30) {
				level=0;
				return ;//返回选关界面
			}
			if (m.x > 2 && m.x < WIDTH - 2 && m.y > HEIGHT - 200 && m.y < HEIGHT - 2) {
				step1 = 0;
				step2 = 0;
				start(level);//进入第level关
				return;
			}
		}
	}
}