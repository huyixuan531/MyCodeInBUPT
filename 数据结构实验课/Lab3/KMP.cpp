#include"head.h"

//计算next[j]的值
void get_next(SString T, int next[]) {
	int i = 1; 
	int j = 0;
	next[1] = 0;
	while (i < T[0]) {
		if (j == 0 || T[i] == T[j]) {
			++i;
			++j;
			next[i] = j;
		}
		else j = next[j];
	}
	for (int i = 1; i < 16;i++) {
		cout<<next[i]<<",";
	}
}

//计算nextval[j]的值
void get_nextval(SString T, int nextval[]) {
	int i = 1;
	int j = 0;
	nextval[1] = 0;
	while (i < T[0]) {
		if (j == 0 || T[i] == T[j]) {
			++i;
			++j;
			if (T[i] != T[j])nextval[i] = j;
			else nextval[i] = nextval[j];
		}
		else j = nextval[j];
	}
}

//用KMP算法进行字符串匹配
int Index_KMP(SString S,SString T,int pos,int next[]) {
	mycount = 0;
	int i = pos;
	int j = 1;
	while (i <= S[0] && j <= T[0]) {
		if (j == 0 || S[i] == T[j]) {
			++i;
			++j;
		}
		else j = next[j];
		++mycount;//比较次数加1
	}
	printf("字符比较次数为：%d\n", mycount);
	if (j > T[0])return i - T[0];
	else return -1;
}