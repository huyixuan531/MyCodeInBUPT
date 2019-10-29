#define _CRT_SECURE_NO_WARNINGS
#include"readFromFile.h"
#include"storeshape.h"

/*外部引用结构体变量*/
extern CIRCLE circle_v[];
extern LINE line_v[];
extern BAR bar_v[];
extern FILLPOLY fillpoly_v[];

extern FILE*fp;

/*函数名：readFromFile*/
/*功能：读取文件shape.txt中储存的图形信息并显示全部图形*/
void readFromFile(void) {
	/*数组temp可存12个图形信息(int)，每个图形信息中依次为[0]shape,[1]fill,[2]side,[3],[4],[5]......coords*/
	/*tempcoor数组存储多边形的各点坐标*/
	int temp[12][103] = {}, tempcoor[100] = {};
	char color_temp[12] = {};/*用来存图形颜色信息(char)*/
	int h = 0, x, y, r, x1, y1, x2, y2;/*h为存入文件的图形计数变量；(x,y)为圆心坐标，r为圆心半径；(x1,y1),(x2,y2)为线段或矩形顶点坐标*/
	fp = fopen("shape.txt", "r");
	while (h < 12) {
		/*将文件shape.txt中的图形信息暂时存入temp数组和color_temp数组*/
		fread(&temp[h], sizeof(temp[h]), 1, fp);
		fread(&color_temp[h], sizeof(color_temp[h]), 1, fp);
		/*检查文件中是否有历史图形*/
		if (temp[0][0]== 0) {
			xyprintf(0, 60, "文件中没有历史图形!");
			break;
		}
		/*读取各类图形并画出*/
		switch (temp[h][0]) {
		case 1:/*圆*/
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
		case 2:/*线段*/
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
		case 3:/*填充矩形*/
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
		case 4:/*填充多边形*/
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
		h++;/*计数变量加一*/
	}
}