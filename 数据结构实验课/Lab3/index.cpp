#include"head.h"

//古典字符匹配算法
int index(SString S,SString T,int pos) {//S为主串，T为子串，pos为起始比较下标
	mycount = 0;//次数重置0
	int i = pos;
	int j = 1;
	while (i <=S[0] && j <= T[0]) {//遍历
		if (S[i] == T[j]) {//如果该字符匹配
			++i;//主串子串指针均向前移
			++j;
		}
		else {//如果该字符不匹配
			i = i - j + 2;//主串指针回到i-j+2
			j = 1;//子串指针回到1，重新匹配
		}
		++mycount;//比较次数加1
	}
	printf("字符比较次数为：%d\n", mycount);
	if (j > T[0]) return i - T[0];//若字串匹配成功，返回字串在主串中第一个元素的下标
	else return -1;//匹配失败返回-1
}