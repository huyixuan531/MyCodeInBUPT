#include"head.h"

int main() {
	printf("此程序完成十进制数到八进制数的转换\n");
	printf("-------------------------------------------------\n");
	SqStack S;
	int op;
	char str[10];//输入的字符串
	int N;//N为需要转换的数
	int num;//转换后的每位数暂存在num
	while (1) {
		InitStack(S);//初始化栈
		printf("请输入要转换的十进制数N：\n");
		while (1) {  //输入合法性检验
			scanf("%s",str);
			if (isInt(str)==-1) { printf("请重新输入一个非负整数！\n"); }
			else {
				N = isInt(str);
				break;
			}
		}
		if (N == 0) Push(S, 0);
		while (N) {//当N不为0时
			Push(S, N % 8);//将余数压入栈
			N = N / 8;//N减小
		}
		printf("该数转换成八进制为：");
		while (!StackEmpty(S)) {//当栈非空
			Pop(S, num);//将弹出的元素暂存到num
			printf("%d", num);//打印出转换后的数（逆序）
		}
		printf("\n");
		while (1) {
				printf("1.继续转换下一个数||2.退出程序\n");
				scanf("%s", str);
				if (isInt(str) == -1) { printf("输入不合法！\n"); }
				else {
					op = isInt(str);
					if (op == 1) {
						DestroyStack(S);
						break;
					}
					else if (op == 2) exit(0);
					else printf("输入不合法！\n");
				}
		}
	}
	return 0;
}