#include"redraw.h"
#include"storeshape.h"

/*��������redraw*/
/*���ܣ�������ǰ�û�������ͼ�Σ�ÿ���������������»���*/
void redraw(int checkshape_s) {
	/*���ݺ���checkshape����ѯ�ʵ��ػ�ͼ�����ͽ������ѭ���ػ������������ͼ��*/
	switch (checkshape_s) {
	case 1:/*Բ*/
		for (int w=0;w<=2;w++) {
			switch (circle_v[w].color) {
			case '1':setcolor(RED);
				break;
			case '2':setcolor(YELLOW);
				break;
			case '3':setcolor(GREEN);
				break;
			case '4':setcolor(BLUE);
				break;
			}
			circle(circle_v[w].coor[0], circle_v[w].coor[1], circle_v[w].coor[2]);
		}
		getch();
		break;
	case 2:/*�߶�*/
		for (int q = 0; q <= 2; q++) {
			switch (line_v[q].color) {
			case '1':setcolor(RED);
				break;
			case '2':setcolor(YELLOW);
				break;
			case '3':setcolor(GREEN);
				break;
			case '4':setcolor(BLUE);
				break;
			}
			line(line_v[q].coor[0], line_v[q].coor[1], line_v[q].coor[2], line_v[q].coor[3]);
		}
		getch();
		break;
	case 3:/*������*/
		for (int f = 0; f <= 2; f++) {
			switch (bar_v[f].color) {
			case '1':setfillcolor(RED);
				break;
			case '2':setfillcolor(YELLOW);
				break;
			case '3':setfillcolor(GREEN);
				break;
			case '4':setfillcolor(BLUE);
				break;
			}
			bar(bar_v[f].coor[0], bar_v[f].coor[1], bar_v[f].coor[2], bar_v[f].coor[3]);
		}
		getch();
		break;
	case 4:/*�������*/
		for (int t = 0; t <= 2; t++) {
			switch (fillpoly_v[t].color) {
			case '1':setfillcolor(RED);
				break;
			case '2':setfillcolor(YELLOW);
				break;
			case '3':setfillcolor(GREEN);
				break;
			case '4':setfillcolor(BLUE);
				break;
			}
			fillpoly(fillpoly_v[t].side, fillpoly_v[t].coor);
		}
		getch();
		break;
	}
}