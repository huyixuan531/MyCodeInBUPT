#include"head.h"

int mycount = 0;//计算每种算法的比较次数

int main() {
	SString S, T;//主串和子串
	char input1[MAX_STR_LEN + 1], input2[MAX_STR_LEN + 1];//获取键盘输入字符串
	char str[10];//退出选项输入
	int next[MAX_STR_LEN], nextval[MAX_STR_LEN];//辅助数组next,nextval
	int op = 0, mode = 0;
	int result = 0;
	printf("此程序用来在主串中查找给定子串\n");
	while(1){
		printf("-------------------------------------------\n");
		printf("请输入查找方式：1.古典模式匹配||2.KMP_next||3.KMP_nextval\n");
		while (1) {
			gets_s(str);//获取输入选择查找模式
			if (isInt(str) == -1) { printf("输入不合法！\n"); }//输入不为非负整数
			else {
				mode = isInt(str);
				if (mode == 1 || mode == 2||mode==3) break;
				else printf("输入不合法！\n");
			}
		}
		printf("请输入主串S：\n");
		gets_s(input1);
		strAssign(S, input1);//将输入字符串赋值给主串
		printf("请输入子串T：\n");
		gets_s(input2);
		strAssign(T, input2);//将输入字符串赋值给子串
		switch (mode) {
		case 1://古典模式匹配
			result = index(S, T, 1);
			break;
		case 2://KMP_next
			get_next(T, next);//计算next数组
			result = Index_KMP(S, T, 1, next);
			break;
		case 3://KMP_nextval
			get_nextval(T, nextval);//计算nextval数组
			result = Index_KMP(S, T, 1, nextval);
			break;
		}
		if (result == -1)//搜索失败返回-1
			printf("搜索失败！主串中不包含给定子串！\n");
		else
			printf("子串在主串中的起始下标为：%d\n", result);//搜索成功打印起始下标
		while (1) {//退出选项
			printf("1.继续查找下一个字串||2.退出程序\n");
			gets_s(str);
			if (isInt(str) == -1) { printf("输入不合法！\n"); }
			else {
				op = isInt(str);
				if (op == 1) {
					break;
				}
				else if (op == 2) exit(0);
				else printf("输入不合法！\n");
			}
		}
	}
	return 0;
}