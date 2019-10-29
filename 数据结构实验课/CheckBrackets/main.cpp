#include"h2.h"

int main() {
	printf("此程序检验括号是否匹配\n");
	printf("--------------------------------\n");
	int op;
	char input[20];//输入的字符串
	char e1,e2;
	SqStack S;
	while(1){
		InitStack(S);
		printf("请输入要检验的括号序列（只能有[]和()）\n");
		scanf("%s", input);
		for (int i = 0; i < strlen(input); i++) {
			e1 = input[i];
			if ((e1 == '(') || (e1 == '['))
				Push(S, e1);
			else if ((e1 == ')') || (e1 == ']'))
				if ((Pop(S, e2) == ERROR) || (e1 == ')' && e2 != '(') || (e1 == ']' && e2 != '[')) {
					printf("此串括号匹配不合法\n");
					goto mark;
				}
			else if ((e1 != '[') && (e1 != '(') && (e1 != ']') && (e1 != ')')) {
				printf("请输入纯括号序列！\n");
				break;
			}
		}
		if (StackEmpty(S)) printf("匹配\n");
		else  printf("此串括号匹配不合法\n");	// 左括号多于右括号
		mark:while (1) {
			printf("1.继续检验下一串括号||2.退出程序\n");
			scanf("%s", input);
			if (isInt(input) == -1) { printf("输入不合法！\n"); }
			else {
				op = isInt(input);
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