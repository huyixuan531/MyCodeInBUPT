#define _CRT_SECURE_NO_WARNINGS
#include"clearFile.h"

char clearstr[5];/*对话框*/
extern FILE *fp;

/*函数名：clearFile*/
/*功能：清空文件中储存的内容*/
void clearFile() {
	while (TRUE) {
		inputbox_getline("清空文件", "是否要清空文件内容？\n请输入Y（是）或N（否）：\n（回车确认）", clearstr, 5);
		if (strcmp(clearstr, "Y") == 0) {
			fopen("shape.txt", "wb");
			fclose(fp);
			break;
		}
		else if (strcmp(clearstr, "N") == 0) break;
	}
}