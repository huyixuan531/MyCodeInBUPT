#include"storeshape.h"
#include"writeToFile.h"

char u[5];/*�Ի���*/
extern char op4, op3;
extern int circleNo, lineNo, barNo, fillpolyNo, coord[], side;
/*�����ĸ��ṹ����������ֱ����Դ�������ͼ�Σ�ÿ��ͼ�����ഢ������*/
CIRCLE circle_v[3] = {};
LINE line_v[3] = {};
BAR bar_v[3] = {};
FILLPOLY fillpoly_v[3] = {};

/*��������storeshape*/
/*���ܣ����û�������ͼ����Ϣ������ṹ������*/
void storeshape(char op4) {
	/*����ͼ��������ഢ��*/
	switch (op4) {
	case '1':/*Բ*/
		circle_v[circleNo].shape = 1;
		circle_v[circleNo].fill = 0;
	    circle_v[circleNo].color = op3;
		circle_v[circleNo].coor[0] = coord[0];
		circle_v[circleNo].coor[1] = coord[1];
		circle_v[circleNo].coor[2] = coord[2];
		break;
	case '2':/*�߶�*/
		line_v[lineNo].shape = 2;
		line_v[lineNo].color = op3;
		line_v[lineNo].coor[0] = coord[0];
		line_v[lineNo].coor[1] = coord[1];
		line_v[lineNo].coor[2] = coord[2];
		line_v[lineNo].coor[3] = coord[3];
		break;
	case'3':/*������*/
		bar_v[barNo].shape = 3;
		bar_v[barNo].fill = 1;
		bar_v[barNo].color = op3;
		bar_v[barNo].coor[0] = coord[0];
		bar_v[barNo].coor[1] = coord[1];
		bar_v[barNo].coor[2] = coord[2];
		bar_v[barNo].coor[3] = coord[3];
		break;
	case'4':/*�������*/
		fillpoly_v[fillpolyNo].shape = 4;
		fillpoly_v[fillpolyNo].fill = 1;
		fillpoly_v[fillpolyNo].color = op3;
		fillpoly_v[fillpolyNo].side = side;
		for (int z=0; z <= 99; z++) {
			fillpoly_v[fillpolyNo].coor[z] = coord[z];
		}
		break;
	}
	/*ѯ���û��Ƿ񴢴�ͼ�ε��ļ�*/
	while (TRUE) {
		inputbox_getline("�洢�ļ�", "�Ƿ񽫸�ͼ�δ洢���ļ����Ա��´δ򿪳���ʱ�ػ���ͼ�Σ�\n������Y���ǣ���N���񣩣�\n���س�ȷ�ϣ�", u, 5);
		if (strcmp(u, "Y") == 0){
			writeToFile(op4);
			break;
		}
		else if (strcmp(u, "N") == 0) {
			xyprintf(0, 380, "ͼ��δ����");
			break;
		}
	}
}