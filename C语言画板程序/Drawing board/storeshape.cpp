#include"storeshape.h"
#include"writeToFile.h"

char u[5];/*对话框*/
extern char op4, op3;
extern int circleNo, lineNo, barNo, fillpolyNo, coord[], side;
/*声明四个结构体数组变量分别用以储存四种图形，每种图形至多储存三个*/
CIRCLE circle_v[3] = {};
LINE line_v[3] = {};
BAR bar_v[3] = {};
FILLPOLY fillpoly_v[3] = {};

/*函数名：storeshape*/
/*功能：将用户画过的图形信息储存进结构体数组*/
void storeshape(char op4) {
	/*根据图形种类分类储存*/
	switch (op4) {
	case '1':/*圆*/
		circle_v[circleNo].shape = 1;
		circle_v[circleNo].fill = 0;
	    circle_v[circleNo].color = op3;
		circle_v[circleNo].coor[0] = coord[0];
		circle_v[circleNo].coor[1] = coord[1];
		circle_v[circleNo].coor[2] = coord[2];
		break;
	case '2':/*线段*/
		line_v[lineNo].shape = 2;
		line_v[lineNo].color = op3;
		line_v[lineNo].coor[0] = coord[0];
		line_v[lineNo].coor[1] = coord[1];
		line_v[lineNo].coor[2] = coord[2];
		line_v[lineNo].coor[3] = coord[3];
		break;
	case'3':/*填充矩形*/
		bar_v[barNo].shape = 3;
		bar_v[barNo].fill = 1;
		bar_v[barNo].color = op3;
		bar_v[barNo].coor[0] = coord[0];
		bar_v[barNo].coor[1] = coord[1];
		bar_v[barNo].coor[2] = coord[2];
		bar_v[barNo].coor[3] = coord[3];
		break;
	case'4':/*填充多边形*/
		fillpoly_v[fillpolyNo].shape = 4;
		fillpoly_v[fillpolyNo].fill = 1;
		fillpoly_v[fillpolyNo].color = op3;
		fillpoly_v[fillpolyNo].side = side;
		for (int z=0; z <= 99; z++) {
			fillpoly_v[fillpolyNo].coor[z] = coord[z];
		}
		break;
	}
	/*询问用户是否储存图形到文件*/
	while (TRUE) {
		inputbox_getline("存储文件", "是否将该图形存储到文件，以便下次打开程序时重画该图形？\n请输入Y（是）或N（否）：\n（回车确认）", u, 5);
		if (strcmp(u, "Y") == 0){
			writeToFile(op4);
			break;
		}
		else if (strcmp(u, "N") == 0) {
			xyprintf(0, 380, "图形未储存");
			break;
		}
	}
}