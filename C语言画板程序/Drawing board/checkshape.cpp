#include"checkshape.h"
#include"storeshape.h"

char strshape[100];/*�Ի���*/

/*��������checkshape*/
/*���ܣ�ѯ�ʲ������û���Ҫ�ػ���ͼ������*/
int checkshape(int*pcheckshape_s) {
	while (TRUE) {
		inputbox_getline("�ػ���ʷͼ��", "��������Ҫ�ػ���ͼ������:\n����:\nCIRCLE(Բ),LINE(��),BAR(������),FILLPOLY(�������)(�س�ȷ��)", strshape, 100);
		/*�����û�������ػ�ͼ�������Ƿ�Ϸ�*/
		if (strcmp(strshape, "CIRCLE") ==0|| strcmp(strshape, "LINE") ==0|| strcmp(strshape, "BAR")==0|| strcmp(strshape, "FILLPOLY") == 0)
			break;/*������ΪCIRCLE,LINE,BAR,FILLPOLY����֮һ��Ϊ�Ϸ�*/
		else xyprintf(0, 360, "��ʷ���Ҳ�����ͼ�Σ�����������");/*������ʾ�û���������*/
	}
	/*�����û������룬ȷ���ػ���ͼ�����ͣ���������ָ�봫��checkshape_s����*/
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