#include"head.h"
using namespace std;

//��������random1
//���ܣ���1~16����������ţ����ظ����֣�
int random1(int** matrix1) {
	int i, j, n = 16, t, isCount = 0;//1~16
	int a[100], b[100] = { 0 };
	srand((unsigned int)time(NULL));//��ʱ�����������
	for (i = 0; i < n; i++)
	{
		a[i] = i + 1;
	}
	i = 0, j = 0;
	while (isCount < n)
	{
		t = rand() % n;
		if (b[t] != 1)
		{
			matrix1[i][j] = a[t];//���н������matrix1[][]
			j++;
			if (j > 3) {
				i++;
				j = 0;
			}
			b[t] = 1;
			isCount++;
		}
	}
	return 0;
}

//��������random6
//���ܣ�����1~60�е�36������������ظ����֣����������С����ð������
int random6(int** ranmatrix, int** anum6) {
	int temp = 0;
	int D[36], i, j;//��������ͱ�������
	int step1 = 0, step2 = 0;
	srand((unsigned int)time(NULL));//��ʱ�����������
	for (i = 0; i < 36; i++)//����36�������
	{
		D[i] = 1 + rand() % 60;//�������Χ1~60
		for (j = 0; j < i; j++)//�жϺ�ǰ������Ƿ��ظ�
			if (D[i] == D[j]) { i--; break; }//����ظ�,���²��������
	}
	for (i = 0; i < 36; i++) {
		ranmatrix[step1][step2] = D[i];//���н������ranmatrix[][]
		step2++;
		if (step2 > 5) {
			step1++;
			step2 = 0;
		}
	}
	for (int i = 0; i < 36; i++)
	{
		for (int j = 0; j < 36 - i - 1; j++)
		{
			if (D[j] > D[j + 1])
			{
				temp = D[j];
				D[j] = D[j + 1];
				D[j + 1] = temp;//�������С�������ð������ 
			}
		}
	}
	step1 = 0, step2 = 0;
	for (i = 0; i < 36; i++) {
		anum6[step1][step2] = D[i];//���н������anum[][]
		step2++;
		if (step2 > 5) {
			step1++;
			step2 = 0;
		}
	}
	return 0;
}