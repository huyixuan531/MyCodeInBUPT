#include"chooseColor.h"

/*函数名：chooseColor*/
/*功能：颜色选择*/
void chooseColor(char op3, char*pop3) {
	char COLOR[100];/*对话框*/
	xyprintf(0, 220, "请输入您选择的颜色：");
	while (TRUE) {
		inputbox_getline("请输入您选择的颜色：", "只能输入“RED”(红)或“YELLOW”(黄)或“GREEN”(绿)或“BLUE”(蓝)。(回车确认)", COLOR, 100);
		/*当输入与颜色关键字完全一致时，设置颜色*/
		if (strcmp(COLOR,"RED")==0) {                                                /*1--红色*/
			setcolor(RED);
			*pop3 = '1';
			break;
		}
		else if (strcmp(COLOR,"YELLOW")==0) {                               /*2--黄色*/
			setcolor(YELLOW);
			*pop3 = '2';
			break;
		}
		else if (strcmp(COLOR,"GREEN")==0) {                                 /*3--绿色*/
			setcolor(GREEN);
			*pop3 = '3';
			break;
		}
		else if (strcmp(COLOR,"BLUE")==0) {                                    /*4--蓝色*/
			setcolor(BLUE);
			*pop3 = '4';
			break;
		}
		else {                                                                                               /*输入错误反馈*/
			xyprintf(0, 240, "对不起，无此颜色。请重新输入");
			*pop3 = '5';
		}
	}
}