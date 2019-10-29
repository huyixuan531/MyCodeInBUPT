#include<iostream>
#include<cstdlib>
#include<ctime>
#include"strategy.h"
#define random(a,b) (rand()%(b-a+1)+a) //random(a,b)：在[a,b]中取随机整数
using namespace std;
//函数名：Random::strategy
//功能：以产生随机数的方式随机出拳
int Random::strategy() {
	srand((unsigned int)time(NULL));//用时钟做随机种子
	return random(1,3);//返回随机出拳结果
}