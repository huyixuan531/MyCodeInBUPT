#include"draw.h"
#include"getcoord.h"
#include"storeshape.h"

extern int circleNo, lineNo, barNo, fillpolyNo;/*结构体中存入图形的计数变量*/
extern char op3;
char op4, str[100], c[100];/*op4记录用户所选图形；str为储存对话框输入变量；c储存用户输入的一串坐标*/
int side, coord[100];/*多边形参数*/
int*pcircle=&circleNo, *pline=&lineNo, *pbar=&barNo, *pfillpoly=&fillpolyNo;

/*函数名：draw*/
/*功能：根据用户选择的图案画图*/
void draw(void) {
	xyprintf(0, 260, "请选择所绘图案：");/*图案选择*/
	xyprintf(0, 280, "1.圆||2.线段||3.填充矩形||4.填充多边形");
	xyprintf(0, 300, "(绘图成功后按任意键返回菜单，用户可继续进行下一步操作)");
	op4 = getch();
	switch (op4) {
	case '1':xyprintf(0, 320, "请输入圆心坐标(a,b)和半径r:");/*画圆*/
		getcoord(c);
		circle(coord[0],coord[1],coord[2]);
		storeshape(op4);
		(*pcircle)++;/*画完一个圆，用指针让circleNo加一*/
		getch();
		break;
	case'2':xyprintf(0, 320, "请输入线段起点坐标(x1,y1)和终点坐标(x2,y2)");/*画线段*/
		getcoord(c);
		line(coord[0],coord[1],coord[2],coord[3]);
		storeshape(op4);
		(*pline)++;
		getch();
		break;
	case'3':xyprintf(0, 320, "请输入矩形左上角坐标(x1,y1)和右下角坐标(x2,y2)");/*画填充矩形*/
		getcoord(c);
		if (op3 == '1')
			setfillcolor(RED);
		else if (op3 == '2')
			setfillcolor(YELLOW);
		else if (op3 == '3')
			setfillcolor(GREEN);
		else setfillcolor(BLUE);
		bar(coord[0],coord[1],coord[2],coord[3]);
		storeshape(op4);
		(*pbar)++;
		getch();
		break;
	case'4':/*画填充多边形*/
		while (TRUE) {     /*询问用户多边形边数并检查数据合法性*/
			xyprintf(0, 320, "请输入多边形边数和各点坐标");
			inputbox_getline("绘制几边形？", "请输入多边形边数(回车确认)", str, 100);
			side = atoi(str);
			if (side >= 3 &&side<=50&& atoi(str))/*如果输入边数为数字且>=3,<=50则为合法数据，执行下一步*/
				break;
			else xyprintf(0,340,"边数须>=3(<=50)，请重新输入");/*否则重新输入*/
		}
		getcoord(c);
		/*设置填充颜色*/
		if (op3 == '1')
			setfillcolor(RED);
		else if (op3 == '2')
			setfillcolor(YELLOW);
		else if (op3 == '3')
			setfillcolor(GREEN);
		else setfillcolor(BLUE);
		fillpoly(side, coord);
		storeshape(op4);
		(*pfillpoly)++;
		getch();
		break;
	}
}