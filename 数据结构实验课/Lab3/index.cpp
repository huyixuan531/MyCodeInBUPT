#include"head.h"

//�ŵ��ַ�ƥ���㷨
int index(SString S,SString T,int pos) {//SΪ������TΪ�Ӵ���posΪ��ʼ�Ƚ��±�
	mycount = 0;//��������0
	int i = pos;
	int j = 1;
	while (i <=S[0] && j <= T[0]) {//����
		if (S[i] == T[j]) {//������ַ�ƥ��
			++i;//�����Ӵ�ָ�����ǰ��
			++j;
		}
		else {//������ַ���ƥ��
			i = i - j + 2;//����ָ��ص�i-j+2
			j = 1;//�Ӵ�ָ��ص�1������ƥ��
		}
		++mycount;//�Ƚϴ�����1
	}
	printf("�ַ��Ƚϴ���Ϊ��%d\n", mycount);
	if (j > T[0]) return i - T[0];//���ִ�ƥ��ɹ��������ִ��������е�һ��Ԫ�ص��±�
	else return -1;//ƥ��ʧ�ܷ���-1
}