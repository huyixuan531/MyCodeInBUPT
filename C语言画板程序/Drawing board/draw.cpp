#include"draw.h"
#include"getcoord.h"
#include"storeshape.h"

extern int circleNo, lineNo, barNo, fillpolyNo;/*�ṹ���д���ͼ�εļ�������*/
extern char op3;
char op4, str[100], c[100];/*op4��¼�û���ѡͼ�Σ�strΪ����Ի������������c�����û������һ������*/
int side, coord[100];/*����β���*/
int*pcircle=&circleNo, *pline=&lineNo, *pbar=&barNo, *pfillpoly=&fillpolyNo;

/*��������draw*/
/*���ܣ������û�ѡ���ͼ����ͼ*/
void draw(void) {
	xyprintf(0, 260, "��ѡ������ͼ����");/*ͼ��ѡ��*/
	xyprintf(0, 280, "1.Բ||2.�߶�||3.������||4.�������");
	xyprintf(0, 300, "(��ͼ�ɹ�����������ز˵����û��ɼ���������һ������)");
	op4 = getch();
	switch (op4) {
	case '1':xyprintf(0, 320, "������Բ������(a,b)�Ͱ뾶r:");/*��Բ*/
		getcoord(c);
		circle(coord[0],coord[1],coord[2]);
		storeshape(op4);
		(*pcircle)++;/*����һ��Բ����ָ����circleNo��һ*/
		getch();
		break;
	case'2':xyprintf(0, 320, "�������߶��������(x1,y1)���յ�����(x2,y2)");/*���߶�*/
		getcoord(c);
		line(coord[0],coord[1],coord[2],coord[3]);
		storeshape(op4);
		(*pline)++;
		getch();
		break;
	case'3':xyprintf(0, 320, "������������Ͻ�����(x1,y1)�����½�����(x2,y2)");/*��������*/
		getcoord(c);
		if (op3 == '1')
			setfillcolor(RED);
		else if (op3 == '2')
			setfillcolor(YELLOW);
		else if (op3 == '3')
			setfillcolor(GREEN);
		else setfillcolor(BLUE);
		bar(coord[0],coord[1],coord[2],coord[3]);
		storeshape(op4);
		(*pbar)++;
		getch();
		break;
	case'4':/*���������*/
		while (TRUE) {     /*ѯ���û�����α�����������ݺϷ���*/
			xyprintf(0, 320, "���������α����͸�������");
			inputbox_getline("���Ƽ����Σ�", "���������α���(�س�ȷ��)", str, 100);
			side = atoi(str);
			if (side >= 3 &&side<=50&& atoi(str))/*����������Ϊ������>=3,<=50��Ϊ�Ϸ����ݣ�ִ����һ��*/
				break;
			else xyprintf(0,340,"������>=3(<=50)������������");/*������������*/
		}
		getcoord(c);
		/*���������ɫ*/
		if (op3 == '1')
			setfillcolor(RED);
		else if (op3 == '2')
			setfillcolor(YELLOW);
		else if (op3 == '3')
			setfillcolor(GREEN);
		else setfillcolor(BLUE);
		fillpoly(side, coord);
		storeshape(op4);
		(*pfillpoly)++;
		getch();
		break;
	}
}