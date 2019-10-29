#include"readFile.h"
#include"readFromFile.h"

/*函数名:readFile*/
/*功能:询问用户是否读取文件并进行操作*/

extern int *preadresult;

int readFile(void) {
	int readresult = 0;/*readresult初始化为0*/
	char op1;/*op1记录用户是否读取文件操作*/
	while (TRUE) {
		xyprintf(0, 20, "是否读取上次保存的文件？");
		xyprintf(0, 40, "请输入Y或N:");
		op1 = getch();
		if (op1 == 'Y') {
			FILE * fp = fopen("shape.txt", "r");
			if (fp!=NULL) {/*若读取文件成功，则readresult为1*/
				xyprintf(0, 60, "读取文件成功！");
				*preadresult = 1;
				readFromFile();/*读取文件信息并重画文件中所有图形*/
				fclose(fp);
				break;
			}
			else {/*若读取文件失败或不读取文件，则readresult为0*/
				xyprintf(0, 60, "文件不存在");
				*preadresult = 0;
				fclose(fp);
				break;
			}
		}
		if (op1 == 'N') {
			xyprintf(0, 60, "未读取");
			*preadresult = 0;
			break;
		}
	}
	return readresult;/*返回读取结果*/
}
