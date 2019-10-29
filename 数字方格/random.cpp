#include"head.h"
using namespace std;

//函数名：random1
//功能：将1~16随机打乱重排（不重复出现）
int random1(int** matrix1) {
	int i, j, n = 16, t, isCount = 0;//1~16
	int a[100], b[100] = { 0 };
	srand((unsigned int)time(NULL));//用时钟做随机种子
	for (i = 0; i < n; i++)
	{
		a[i] = i + 1;
	}
	i = 0, j = 0;
	while (isCount < n)
	{
		t = rand() % n;
		if (b[t] != 1)
		{
			matrix1[i][j] = a[t];//排列结果存入matrix1[][]
			j++;
			if (j > 3) {
				i++;
				j = 0;
			}
			b[t] = 1;
			isCount++;
		}
	}
	return 0;
}

//函数名：random6
//功能：生成1~60中的36个随机数（不重复出现），并将其从小到大冒泡排序
int random6(int** ranmatrix, int** anum6) {
	int temp = 0;
	int D[36], i, j;//整型数组和变量声明
	int step1 = 0, step2 = 0;
	srand((unsigned int)time(NULL));//用时钟做随机种子
	for (i = 0; i < 36; i++)//产生36个随机数
	{
		D[i] = 1 + rand() % 60;//随机数范围1~60
		for (j = 0; j < i; j++)//判断和前面的数是否重复
			if (D[i] == D[j]) { i--; break; }//如果重复,重新产生随机数
	}
	for (i = 0; i < 36; i++) {
		ranmatrix[step1][step2] = D[i];//排列结果存入ranmatrix[][]
		step2++;
		if (step2 > 5) {
			step1++;
			step2 = 0;
		}
	}
	for (int i = 0; i < 36; i++)
	{
		for (int j = 0; j < 36 - i - 1; j++)
		{
			if (D[j] > D[j + 1])
			{
				temp = D[j];
				D[j] = D[j + 1];
				D[j + 1] = temp;//将数组从小到大进行冒泡排序 
			}
		}
	}
	step1 = 0, step2 = 0;
	for (i = 0; i < 36; i++) {
		anum6[step1][step2] = D[i];//排列结果存入anum[][]
		step2++;
		if (step2 > 5) {
			step1++;
			step2 = 0;
		}
	}
	return 0;
}