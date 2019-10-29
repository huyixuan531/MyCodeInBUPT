/*该程序为一个简单的画板，用户可以根据提示进行简单的颜色选择与图案绘制*/
#include"readFile.h"
#include"menu.h"
#include"draw.h"
#include"chooseColor.h"
#include"getcoord.h"
#include"redraw.h"
#include"storeshape.h"
#include"checkshape.h"
#include"clearFile.h"

/*变量列表：
	op2:记录用户菜单选择
	op3:记录用户颜色选择
	checkshape_s:为重画确认过的图形类型
	readresult:读取文件结果
	circleNo,lineNo,barNo,fillpolyNo:结构体中存入图形的计数变量
*/
char op2, op3;
char*pop3 = &op3;
int checkshape_s, readresult = 0, circleNo=0, lineNo=0, barNo=0, fillpolyNo=0, e=0;
int*pcheckshape_s=&checkshape_s, *preadresult = &readresult, *pe=&e;
FILE *fp;

/*main函数*/
int main() {
	initgraph(1300, 600);/*新建画板窗口*/
	readresult=readFile();
	while (TRUE) {
		menu(readresult);/*根据文件读取结果显示菜单*/
		op2 = getch();
		/*根据用户选择分别进行三种操作*/
		switch (op2) {
		case '1':cleardevice();/*清除屏幕*/
			break;
		case '2':chooseColor(op3,pop3);/*选择颜色*/
			draw();/*画图*/
			*preadresult = 1;/*画过一次图后，让readresult为1*/
			break;
		case '3':clearFile();/*退出程序之前询问用户是否清除文件中保存的图形*/
			closegraph();/*退出程序*/
			break;
		case '4':checkshape(pcheckshape_s);/*重画前检验图形的合法性*/
			redraw(checkshape_s);/*重画*/
			break;
		}
		if (op2 == '3')
			break;
	}
	return 0;
}