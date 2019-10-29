#define _CRT_SECURE_NO_WARNINGS
#include"readFromFile.h"
#include"storeshape.h"

/*�ⲿ���ýṹ�����*/
extern CIRCLE circle_v[];
extern LINE line_v[];
extern BAR bar_v[];
extern FILLPOLY fillpoly_v[];

extern FILE*fp;

/*��������readFromFile*/
/*���ܣ���ȡ�ļ�shape.txt�д����ͼ����Ϣ����ʾȫ��ͼ��*/
void readFromFile(void) {
	/*����temp�ɴ�12��ͼ����Ϣ(int)��ÿ��ͼ����Ϣ������Ϊ[0]shape,[1]fill,[2]side,[3],[4],[5]......coords*/
	/*tempcoor����洢����εĸ�������*/
	int temp[12][103] = {}, tempcoor[100] = {};
	char color_temp[12] = {};/*������ͼ����ɫ��Ϣ(char)*/
	int h = 0, x, y, r, x1, y1, x2, y2;/*hΪ�����ļ���ͼ�μ���������(x,y)ΪԲ�����꣬rΪԲ�İ뾶��(x1,y1),(x2,y2)Ϊ�߶λ���ζ�������*/
	fp = fopen("shape.txt", "r");
	while (h < 12) {
		/*���ļ�shape.txt�е�ͼ����Ϣ��ʱ����temp�����color_temp����*/
		fread(&temp[h], sizeof(temp[h]), 1, fp);
		fread(&color_temp[h], sizeof(color_temp[h]), 1, fp);
		/*����ļ����Ƿ�����ʷͼ��*/
		if (temp[0][0]== 0) {
			xyprintf(0, 60, "�ļ���û����ʷͼ��!");
			break;
		}
		/*��ȡ����ͼ�β�����*/
		switch (temp[h][0]) {
		case 1:/*Բ*/
			x = temp[h][3];
			y = temp[h][4];
			r = temp[h][5];
			switch (color_temp[h]) {
			case '1':setcolor(RED);
				break;
			case '2':setcolor(YELLOW);
				break;
			case '3':setcolor(GREEN);
				break;
			case '4':setcolor(BLUE);
				break;
			}
			circle(x, y, r);
			break;
		case 2:/*�߶�*/
			x1 = temp[h][3];
			y1 = temp[h][4];
			x2 = temp[h][5];
			y2 = temp[h][6];
			switch (color_temp[h]) {
			case '1':setcolor(RED);
				break;
			case '2':setcolor(YELLOW);
				break;
			case '3':setcolor(GREEN);
				break;
			case '4':setcolor(BLUE);
				break;
			}
			line(x1, y1, x2, y2);
			break;
		case 3:/*������*/
			x1 = temp[h][3];
			y1 = temp[h][4];
			x2 = temp[h][5];
			y2 = temp[h][6];
			switch (color_temp[h]) {
			case '1':setfillcolor(RED);
				break;
			case '2':setfillcolor(YELLOW);
				break;
			case '3':setfillcolor(GREEN);
				break;
			case '4':setfillcolor(BLUE);
				break;
			}
			bar(x1, y1, x2, y2);
			break;
		case 4:/*�������*/
			for (int i = 0; i < 100; i++) {
				tempcoor[i] = temp[h][i + 3];
			}
			switch (color_temp[h]) {
			case '1':setfillcolor(RED);
				break;
			case '2':setfillcolor(YELLOW);
				break;
			case '3':setfillcolor(GREEN);
				break;
			case '4':setfillcolor(BLUE);
				break;
			}
			fillpoly(temp[h][2], tempcoor);
			break;
		}
		h++;/*����������һ*/
	}
}