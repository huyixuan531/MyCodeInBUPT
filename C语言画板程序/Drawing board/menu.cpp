#include"menu.h"

/*������:menu*/
/*����:��ʾ�˵���ѯ���û�ѡ��*/
void menu(int readresult) {
	xyprintf(0, 80, "��ӭ��������Ļ���!");
	xyprintf(0, 100, "����ݲ˵�ѡ��������еĲ�����");
	xyprintf(0, 120, "1.�����Ļ");
	xyprintf(0, 140, "2.����");
	xyprintf(0, 160, "3.�˳�");
	if (readresult == 1) {/*��ȡ�ļ��ɹ��򻭹�һ��ͼ�󣬲˵�����ػ�����*/
		xyprintf(0, 180, "4.�ػ�");
	}
	xyprintf(0, 200, "����������ѡ��");
}