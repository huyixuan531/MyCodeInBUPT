#include"head.h"

int mycount = 0;//����ÿ���㷨�ıȽϴ���

int main() {
	SString S, T;//�������Ӵ�
	char input1[MAX_STR_LEN + 1], input2[MAX_STR_LEN + 1];//��ȡ���������ַ���
	char str[10];//�˳�ѡ������
	int next[MAX_STR_LEN], nextval[MAX_STR_LEN];//��������next,nextval
	int op = 0, mode = 0;
	int result = 0;
	printf("�˳��������������в��Ҹ����Ӵ�\n");
	while(1){
		printf("-------------------------------------------\n");
		printf("��������ҷ�ʽ��1.�ŵ�ģʽƥ��||2.KMP_next||3.KMP_nextval\n");
		while (1) {
			gets_s(str);//��ȡ����ѡ�����ģʽ
			if (isInt(str) == -1) { printf("���벻�Ϸ���\n"); }//���벻Ϊ�Ǹ�����
			else {
				mode = isInt(str);
				if (mode == 1 || mode == 2||mode==3) break;
				else printf("���벻�Ϸ���\n");
			}
		}
		printf("����������S��\n");
		gets_s(input1);
		strAssign(S, input1);//�������ַ�����ֵ������
		printf("�������Ӵ�T��\n");
		gets_s(input2);
		strAssign(T, input2);//�������ַ�����ֵ���Ӵ�
		switch (mode) {
		case 1://�ŵ�ģʽƥ��
			result = index(S, T, 1);
			break;
		case 2://KMP_next
			get_next(T, next);//����next����
			result = Index_KMP(S, T, 1, next);
			break;
		case 3://KMP_nextval
			get_nextval(T, nextval);//����nextval����
			result = Index_KMP(S, T, 1, nextval);
			break;
		}
		if (result == -1)//����ʧ�ܷ���-1
			printf("����ʧ�ܣ������в����������Ӵ���\n");
		else
			printf("�Ӵ��������е���ʼ�±�Ϊ��%d\n", result);//�����ɹ���ӡ��ʼ�±�
		while (1) {//�˳�ѡ��
			printf("1.����������һ���ִ�||2.�˳�����\n");
			gets_s(str);
			if (isInt(str) == -1) { printf("���벻�Ϸ���\n"); }
			else {
				op = isInt(str);
				if (op == 1) {
					break;
				}
				else if (op == 2) exit(0);
				else printf("���벻�Ϸ���\n");
			}
		}
	}
	return 0;
}