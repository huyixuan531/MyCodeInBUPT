/*�ó���Ϊһ���򵥵Ļ��壬�û����Ը�����ʾ���м򵥵���ɫѡ����ͼ������*/
#include"readFile.h"
#include"menu.h"
#include"draw.h"
#include"chooseColor.h"
#include"getcoord.h"
#include"redraw.h"
#include"storeshape.h"
#include"checkshape.h"
#include"clearFile.h"

/*�����б�
	op2:��¼�û��˵�ѡ��
	op3:��¼�û���ɫѡ��
	checkshape_s:Ϊ�ػ�ȷ�Ϲ���ͼ������
	readresult:��ȡ�ļ����
	circleNo,lineNo,barNo,fillpolyNo:�ṹ���д���ͼ�εļ�������
*/
char op2, op3;
char*pop3 = &op3;
int checkshape_s, readresult = 0, circleNo=0, lineNo=0, barNo=0, fillpolyNo=0, e=0;
int*pcheckshape_s=&checkshape_s, *preadresult = &readresult, *pe=&e;
FILE *fp;

/*main����*/
int main() {
	initgraph(1300, 600);/*�½����崰��*/
	readresult=readFile();
	while (TRUE) {
		menu(readresult);/*�����ļ���ȡ�����ʾ�˵�*/
		op2 = getch();
		/*�����û�ѡ��ֱ�������ֲ���*/
		switch (op2) {
		case '1':cleardevice();/*�����Ļ*/
			break;
		case '2':chooseColor(op3,pop3);/*ѡ����ɫ*/
			draw();/*��ͼ*/
			*preadresult = 1;/*����һ��ͼ����readresultΪ1*/
			break;
		case '3':clearFile();/*�˳�����֮ǰѯ���û��Ƿ�����ļ��б����ͼ��*/
			closegraph();/*�˳�����*/
			break;
		case '4':checkshape(pcheckshape_s);/*�ػ�ǰ����ͼ�εĺϷ���*/
			redraw(checkshape_s);/*�ػ�*/
			break;
		}
		if (op2 == '3')
			break;
	}
	return 0;
}