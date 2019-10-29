#define _CRT_SECURE_NO_WARNINGS
#include"head.h"
#include <cstdlib>

int** playnum1;//玩家所点方格顺序
int** anum6;//第三关答案
int** matrix1;//第1，6关随机生成矩阵
int** matrix6;
int step1 = 0, step2 = 0;//调用一次numbutton，step1,step2改变一次
int level = 0;

int main(void)
{
	mciSendString(TEXT("open bgm.mp3 alias music"), NULL, 0, NULL);//循环播放背景音乐
	mciSendString(TEXT("play music repeat"), NULL, 0, NULL);
	o1();//显示游戏主界面
	return 0;
}





