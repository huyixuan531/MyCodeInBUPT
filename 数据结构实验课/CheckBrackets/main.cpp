#include"h2.h"

int main() {
	printf("�˳�����������Ƿ�ƥ��\n");
	printf("--------------------------------\n");
	int op;
	char input[20];//������ַ���
	char e1,e2;
	SqStack S;
	while(1){
		InitStack(S);
		printf("������Ҫ������������У�ֻ����[]��()��\n");
		scanf("%s", input);
		for (int i = 0; i < strlen(input); i++) {
			e1 = input[i];
			if ((e1 == '(') || (e1 == '['))
				Push(S, e1);
			else if ((e1 == ')') || (e1 == ']'))
				if ((Pop(S, e2) == ERROR) || (e1 == ')' && e2 != '(') || (e1 == ']' && e2 != '[')) {
					printf("�˴�����ƥ�䲻�Ϸ�\n");
					goto mark;
				}
			else if ((e1 != '[') && (e1 != '(') && (e1 != ']') && (e1 != ')')) {
				printf("�����봿�������У�\n");
				break;
			}
		}
		if (StackEmpty(S)) printf("ƥ��\n");
		else  printf("�˴�����ƥ�䲻�Ϸ�\n");	// �����Ŷ���������
		mark:while (1) {
			printf("1.����������һ������||2.�˳�����\n");
			scanf("%s", input);
			if (isInt(input) == -1) { printf("���벻�Ϸ���\n"); }
			else {
				op = isInt(input);
				if (op == 1) {
					DestroyStack(S);
					break;
				}
				else if (op == 2) exit(0);
				else printf("���벻�Ϸ���\n");
			}
		}
	}
	return 0;
}