#include"head.h"

// ����һ����ֵ����chars�Ĵ�T
int strAssign(SString T, char* chars){ 
	int i;
	if (strlen(chars) > MAX_STR_LEN)//���chars���ȴ��ڴ�T����
		return -1;
	else{
		T[0] = strlen(chars);//��T��0�ŵ�Ԫ���chars����
		for (i = 1; i <= T[0]; i++)
			T[i] = *(chars + i - 1);//������ֵ
		return 1;
	}
}
