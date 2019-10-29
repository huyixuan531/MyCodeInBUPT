#include"head.h"
//判断输入是否为int
int isInt(char str[]) {
	char a;
	for (int i = 0; i < strlen(str); i++) {//从输入字符串中依次取出单个字符
		a = str[i];//放入a中
		if (a >= '0' && a <= '9');//如果该字符为0~9，继续检查下一个
		else {//如果不为0~9
			printf("输入不为非负整数！\n");
			return -1;//返回结果（不是整数）
		}
	}
	return atoi(str);//如果所有字符都为0~9，则将整个输入字符串转换成int并返回
}