#include"chooseColor.h"

/*��������chooseColor*/
/*���ܣ���ɫѡ��*/
void chooseColor(char op3, char*pop3) {
	char COLOR[100];/*�Ի���*/
	xyprintf(0, 220, "��������ѡ�����ɫ��");
	while (TRUE) {
		inputbox_getline("��������ѡ�����ɫ��", "ֻ�����롰RED��(��)��YELLOW��(��)��GREEN��(��)��BLUE��(��)��(�س�ȷ��)", COLOR, 100);
		/*����������ɫ�ؼ�����ȫһ��ʱ��������ɫ*/
		if (strcmp(COLOR,"RED")==0) {                                                /*1--��ɫ*/
			setcolor(RED);
			*pop3 = '1';
			break;
		}
		else if (strcmp(COLOR,"YELLOW")==0) {                               /*2--��ɫ*/
			setcolor(YELLOW);
			*pop3 = '2';
			break;
		}
		else if (strcmp(COLOR,"GREEN")==0) {                                 /*3--��ɫ*/
			setcolor(GREEN);
			*pop3 = '3';
			break;
		}
		else if (strcmp(COLOR,"BLUE")==0) {                                    /*4--��ɫ*/
			setcolor(BLUE);
			*pop3 = '4';
			break;
		}
		else {                                                                                               /*���������*/
			xyprintf(0, 240, "�Բ����޴���ɫ������������");
			*pop3 = '5';
		}
	}
}