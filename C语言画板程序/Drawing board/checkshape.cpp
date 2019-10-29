#include"checkshape.h"
#include"storeshape.h"

char strshape[100];/*对话框*/

/*函数名：checkshape*/
/*功能：询问并检验用户需要重画的图形类型*/
int checkshape(int*pcheckshape_s) {
	while (TRUE) {
		inputbox_getline("重画历史图形", "请输入您要重画的图形类型:\n例如:\nCIRCLE(圆),LINE(线),BAR(填充矩形),FILLPOLY(填充多边形)(回车确认)", strshape, 100);
		/*检验用户输入的重画图形类型是否合法*/
		if (strcmp(strshape, "CIRCLE") ==0|| strcmp(strshape, "LINE") ==0|| strcmp(strshape, "BAR")==0|| strcmp(strshape, "FILLPOLY") == 0)
			break;/*若输入为CIRCLE,LINE,BAR,FILLPOLY四种之一即为合法*/
		else xyprintf(0, 360, "历史中找不到该图形！请重新输入");/*否则提示用户重新输入*/
	}
	/*根据用户的输入，确定重画的图形类型，并将其用指针传给checkshape_s变量*/
	if (strcmp(strshape, "CIRCLE") == 0 && circle_v[0].color != 0)
		*pcheckshape_s=1;
	else if (strcmp(strshape, "LINE")==0 && line_v[0].color != 0)
		*pcheckshape_s = 2;
	else if (strcmp(strshape, "BAR")==0 && bar_v[0].color != 0)
		*pcheckshape_s = 3;
	else if (strcmp(strshape, "FILLPOLY")==0 && fillpoly_v[0].color != 0)
		*pcheckshape_s = 4;
	return 0;
}