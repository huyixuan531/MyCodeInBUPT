#include"head.h"

//函数名：start
//功能：显示游戏界面
void start(int level)
{//分配空间给matrix1,matrix6,playnum1
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
	//开始计时
	long start_time;
	bool is_stop = true;//是否处于停止状态 
	long t = 0;           //计算总时间
	Start(is_stop, start_time);
	//绘制游戏背景
	setbkcolor(RGB(251, 248, 241));//背景颜色（米）
	settextcolor(RGB(79, 79, 79));//字体颜色（黑）
	cleardevice();//清屏
	setfillcolor(RGB(0, 0, 0));//设置当前的填充颜色（纯黑）
	solidrectangle(30, 30, 570, 570);
	setfillcolor(RGB(244, 164, 96));//设置当前的填充颜色（肉）
	solidroundrect(0, 30, 60, 0, 5, 5);
	setbkcolor(RGB(244, 164, 96));//背景颜色（肉）
	RECT r6 = { 0, 0 ,60,30 };
	setfont(30, 0, "Microsoft Yahei UI Bold");
	drawtext("返回", &r6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	setfillcolor(RGB(255, 255, 0));//设置当前的填充颜色（淡黄）
	solidroundrect(150, 600, 250, 650, 10, 10);
	setbkcolor(RGB(255, 255, 0));//背景颜色（淡黄）
	RECT r8 = { 150, 600, 250, 650 };
	drawtext("重置", &r8, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	setfillcolor(RGB(255, 255, 0));//设置当前的填充颜色（淡黄）
	solidroundrect(350, 600, 450, 650, 10, 10);
	setbkcolor(RGB(255, 255, 0));//背景颜色（淡黄）
	RECT r7 = { 350, 600, 450, 650 };
	drawtext("确认完成", &r7, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	map(level);//显示数字方格
	COOR	 coor;
	int flag[10][10] = { 0 };//每个方格是否被按下，白色为0，黑色为1
	//获取鼠标信息
	MOUSEMSG m;
	while (1)
	{
		if (MouseHit())
		{
			m = GetMouseMsg();
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				if (m.x > 0 && m.x < 60 && m.y>0 && m.y < 30)
					return;//返回选关界面
				if (m.x > 350 && m.x < 450 && m.y > 600 && m.y < 650) {
					Stop(is_stop);//确认本关完成，停止计时
					evaluate(grade(level, t, judge(level, playnum1)), level); //进入评价界面
					return;
				}
				if (m.x > 30 && m.x < 570 && m.y>30 && m.y < 570) {
					numbutton(m, coor, level);//记录玩家按键顺序
					if (flag[coor.a][coor.b] == 0) {
						store(coor, playnum1, level);//存储玩家按键顺序
						flag[coor.a][coor.b] = 1;//改变方格flag
						changecolor(level, coor.a, coor.b);//改变方格颜色
					}
				}
				//如果点重置，则flag全变0，重画全部白色方格
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
		else {//如果不点完成按钮，则一直记录并显示时间
			if (!isStop(is_stop))
			{
				show(start_time, t, is_stop);
			}
		}
	}
}
