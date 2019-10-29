#include<iostream>
#include"strategy.h"
using namespace std;
//函数名：translate
//功能：将代表“石头”，“剪刀”，“布”的1，2，3翻译成中文以便显示
string translate(int i) {
	if (i == 1)
		return "石头";//1——石头
	else if (i == 2)
		return "剪刀";//2——剪刀
	else if (i == 3)
		return "布  ";//3——布
	else return "ERROR!";//其他——错误
}