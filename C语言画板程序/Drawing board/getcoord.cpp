#include"getcoord.h"

extern int coord[100];/*将char类型坐标数据转换成int后存入coord*/

/*函数名：getcoord*/
/*功能：获得并处理用户输入的一串点的坐标*/
int getcoord(char c[]) {
	while (TRUE) {     /*询问用户各顶点坐标并检查数据合法性*/
		inputbox_getline("坐标输入框", "请输入图形各点坐标(不超过50个点),并以逗号分隔:\n例如:x1,y1,x2,y2,......,xn,yn(回车确认)\n", c, 100);
		char *tokenPtr = strtok(c, ",");/*分割得到用户输入的第一段字符串，即是第一个点的x坐标，分隔符为逗号*/
		int i = 0; /*定义一个计数变量*/
		while (tokenPtr != '\0') {
			coord[i++] = atoi(tokenPtr);/*若分割得到的子字符串不为结束符'\0'(即NULL),则将其转换为对应的数字*/
			tokenPtr = strtok('\0', ",");
		}
		if (atoi(c))/*如果输入的各点坐标为数字，执行下一步*/
			break;
		else xyprintf(0, 360, "输入不合法，请重新输入");/*否则重新输入*/
	}
	return 0;
}