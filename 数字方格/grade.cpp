#include<stdio.h>
#include<stdlib.h>

//��������grade
//���ܣ�����level��time��fault���д��
int grade(int level, long time, int fault) {
	int score, tscore, fscore;//�ܷ֡�ʱ��÷֡���������۷�
	switch (level) {//��ͬ�ؿ����ֱ�׼��ͬ
	case 1:
		fscore = 15;
		if (time > 0 && time <= 10)tscore = 30;
		else if (time > 10 && time <= 20)tscore = 25;
		else if (time > 20 && time <= 30)tscore = 20;
		else tscore = 10;
		break;
	case 2:
		fscore = 12;
		if (time > 0 && time <= 20)tscore = 30;
		else if (time > 20 && time <= 40)tscore = 25;
		else if (time > 40 && time <= 60)tscore = 20;
		else tscore = 10;
		break;
	case 3:
		fscore = 10;
		if (time > 0 && time <= 30)tscore = 30;
		else if (time > 30 && time <= 60)tscore = 25;
		else if (time > 60 && time <= 90)tscore = 20;
		else tscore = 10;
		break;
	case 4:
		fscore = 7;
		if (time > 0 && time <= 20)tscore = 30;
		else if (time > 20 && time <= 40)tscore = 25;
		else if (time > 40 && time <= 60)tscore = 20;
		else tscore = 10;
		break;
	case 5:
		fscore = 5;
		if (time > 0 && time <= 20)tscore = 30;
		else if (time > 20 && time <= 40)tscore = 25;
		else if (time > 40 && time <= 60)tscore = 20;
		else tscore = 10;
		break;
	case 6:
		fscore = 2;
		if (time > 0 && time <= 60)tscore = 30;
		else if (time > 60 && time <= 120)tscore = 25;
		else if (time > 120 && time <= 180)tscore = 20;
		else tscore = 10;
		break;
	}
	score = tscore + 70 - fault * fscore;//����÷�
	if (score < 0)score = 0;//�������ڵ���0
	return score;
}
