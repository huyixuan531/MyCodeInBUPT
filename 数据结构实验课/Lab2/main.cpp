#include"head.h"

int main() {
	printf("�˳������ʮ���������˽�������ת��\n");
	printf("-------------------------------------------------\n");
	SqStack S;
	int op;
	char str[10];//������ַ���
	int N;//NΪ��Ҫת������
	int num;//ת�����ÿλ���ݴ���num
	while (1) {
		InitStack(S);//��ʼ��ջ
		printf("������Ҫת����ʮ������N��\n");
		while (1) {  //����Ϸ��Լ���
			scanf("%s",str);
			if (isInt(str)==-1) { printf("����������һ���Ǹ�������\n"); }
			else {
				N = isInt(str);
				break;
			}
		}
		if (N == 0) Push(S, 0);
		while (N) {//��N��Ϊ0ʱ
			Push(S, N % 8);//������ѹ��ջ
			N = N / 8;//N��С
		}
		printf("����ת���ɰ˽���Ϊ��");
		while (!StackEmpty(S)) {//��ջ�ǿ�
			Pop(S, num);//��������Ԫ���ݴ浽num
			printf("%d", num);//��ӡ��ת�������������
		}
		printf("\n");
		while (1) {
				printf("1.����ת����һ����||2.�˳�����\n");
				scanf("%s", str);
				if (isInt(str) == -1) { printf("���벻�Ϸ���\n"); }
				else {
					op = isInt(str);
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