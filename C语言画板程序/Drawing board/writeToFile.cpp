#define _CRT_SECURE_NO_WARNINGS
#include"writeToFile.h"

extern FILE *fp;
extern int e, circleNo, lineNo, barNo, fillpolyNo;  /*e为存入文件的图形计数变量*/
extern int *pe;

/*函数名：writeToFile*/
/*功能：将当前图形的信息(每种最多存3个)存储到文件shape.txt中*/
void writeToFile(char op4) {
	int store[12][103] = {};/*数组可存12个图形信息(int)，每个图形信息中依次为[0]shape,[1]fill,[2]side,[3],[4],[5]......coords*/
	char color_store[12] = {};/*用来存图形颜色信息(char)*/
	fp = fopen("shape.txt", "a");
	/*将结构体中的图形信息暂时存入store数组和color_store数组*/
	switch (op4) {
	case'1':/*圆*/
		store[e][0]=circle_v[circleNo].shape;
		store[e][1] = circle_v[circleNo].fill;
		store[e][2] = circle_v[circleNo].fill;
		store[e][3] = circle_v[circleNo].coor[0];
		store[e][4] = circle_v[circleNo].coor[1];
		store[e][5] = circle_v[circleNo].coor[2];
		color_store[e] = circle_v[circleNo].color;
		break;
	case'2':/*线段*/
		store[e][0] = line_v[lineNo].shape;
		store[e][3] = line_v[lineNo].coor[0];
		store[e][4] = line_v[lineNo].coor[1];
		store[e][5] = line_v[lineNo].coor[2];
		store[e][6] = line_v[lineNo].coor[3];
		color_store[e] = line_v[lineNo].color;
		break;
	case'3':/*填充矩形*/
		store[e][0] = bar_v[barNo].shape;
		store[e][3] = bar_v[barNo].coor[0];
		store[e][4] = bar_v[barNo].coor[1];
		store[e][5] = bar_v[barNo].coor[2];
		store[e][6] = bar_v[barNo].coor[3];
		color_store[e] = bar_v[barNo].color;
		break;
	case'4':/*填充多边形*/
		store[e][0] = fillpoly_v[fillpolyNo].shape;
		store[e][2] = fillpoly_v[fillpolyNo].side;
		for (int z = 0; z <= 99; z++) {
			store[e][z+3]=fillpoly_v[fillpolyNo].coor[z];
		}
		color_store[e]=fillpoly_v[fillpolyNo].color;
		break;
	}
	/*将store数组和color_store数组中的数存入文件shape.txt*/
	fwrite(&store[e], sizeof(store[e]), 1, fp);
	fwrite(&color_store[e], sizeof(color_store[e]), 1, fp);
	fclose(fp);
	*pe = *pe + 1;/*计数变量加一*/
}