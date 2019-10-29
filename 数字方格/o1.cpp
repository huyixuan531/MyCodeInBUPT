#include"head.h"

//函数名：o1
//功能：显示主界面
void o1()
{//背景&标题
	initgraph(WIDTH, HEIGHT);//长宽
	while (1) {
		setbkcolor(RGB(251, 248, 241));//背景颜色（米）
		settextcolor(RGB(150, 126, 104));//字体颜色（棕）
		cleardevice();//清屏
		setfont(60, 0, "Microsoft Yahei UI Bold");//字体设置
		RECT r1 = { 0,0,WIDTH,HEIGHT / 3 };
		drawtext("数字方格", &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		//开始游戏键
		setfont(40, 0, "Microsoft Yahei UI Bold");
		settextcolor(RGB(79, 79, 79));//字体颜色（黑）
		setfillcolor(RGB(250, 128, 114));//设置当前的填充颜色（粉）
		solidroundrect(230, 305, 370, 240, 50, 50);//
		setbkcolor(RGB(250, 128, 114));//背景颜色（粉）
		RECT r2 = { WIDTH / 2 - 65,HEIGHT / 2 - 90,WIDTH / 2 + 65,HEIGHT / 2 - 60 };
		drawtext("开始游戏", &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		//操作说明键
		setfillcolor(RGB(244, 164, 96));//设置当前的填充颜色（肉）
		solidroundrect(230, 400, 370, 335, 50, 50);//
		setbkcolor(RGB(244, 164, 96));//背景颜色（肉）
		RECT r4 = { WIDTH / 2 - 65,HEIGHT / 2 + 65 ,WIDTH / 2 + 65,HEIGHT / 3 + 85 };
		drawtext("操作说明", &r4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		//开发人员键
		setfillcolor(RGB(244, 186, 1));//设置当前的填充颜色（黄）
		solidroundrect(230, 495, 370, 430, 50, 50);//
		setbkcolor(RGB(244, 186, 1));//背景颜色（黄）
		RECT r5 = { WIDTH / 2 - 65,HEIGHT / 2 + 100,WIDTH / 2 + 65,HEIGHT / 2 + 130 };
		drawtext("开发人员", &r5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		//退出键
		setfillcolor(RGB(255, 255, 0));//设置当前的填充颜色（淡黄）
		solidroundrect(230, 590, 370, 525, 50, 50);//
		setbkcolor(RGB(255, 255, 0));//背景颜色（淡黄）
		RECT r6 = { WIDTH / 2 - 65,HEIGHT / 2 + 190,WIDTH / 2 + 65,HEIGHT / 2 + 220 };
		drawtext("退出", &r6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		//音乐
		setfillcolor(RGB(244, 164, 96));
		settextstyle(30, 0, "Microsoft Yahei UI Bold");
		solidroundrect(540, 0, 600, 30, 5, 5);
		setbkcolor(RGB(244, 164, 96));
		outtextxy(545, 0, "音乐");
		bool is_music = true;//判断音乐是否正在播放
		//获取鼠标信息
		MOUSEMSG m;
		while (1)
		{
			BeginBatchDraw();//批量绘图
			EndBatchDraw();//结束批量绘图
			m = GetMouseMsg();//获取鼠标信息
			if (m.uMsg == WM_LBUTTONUP)
			{
				if (m.x > 230 && m.x<370 && m.y>240 && m.y < 305) {
					choose(level);//进入选关界面
					cleardevice();                                 
					break;
				}
				else if (m.x > 230 && m.x<370 && m.y>335 && m.y <400){
					o2();//进入操作说明界面
					cleardevice();                                 
					break;
				}
				else if (m.x > 230 && m.x<370 && m.y>430 && m.y <495) {
					o3();//进入开发人员界面
					cleardevice();
					break;
				}
				else if (m.x >230 && m.x<370&& m.y>525 && m.y < 590)
					exit(0);//退出程序
				else if (m.x > 540 && m.x < 600 && m.y>0 && m.y < 30)//音乐暂停或开始
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