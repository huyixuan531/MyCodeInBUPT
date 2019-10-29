#include"menu.h"

/*函数名:menu*/
/*功能:显示菜单并询问用户选择*/
void menu(int readresult) {
	xyprintf(0, 80, "欢迎您进入你的画板!");
	xyprintf(0, 100, "请根据菜单选择您想进行的操作：");
	xyprintf(0, 120, "1.清除屏幕");
	xyprintf(0, 140, "2.作画");
	xyprintf(0, 160, "3.退出");
	if (readresult == 1) {/*读取文件成功或画过一次图后，菜单添加重画功能*/
		xyprintf(0, 180, "4.重画");
	}
	xyprintf(0, 200, "请输入您的选择：");
}