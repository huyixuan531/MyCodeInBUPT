#include"readFile.h"
#include"readFromFile.h"

/*������:readFile*/
/*����:ѯ���û��Ƿ��ȡ�ļ������в���*/

extern int *preadresult;

int readFile(void) {
	int readresult = 0;/*readresult��ʼ��Ϊ0*/
	char op1;/*op1��¼�û��Ƿ��ȡ�ļ�����*/
	while (TRUE) {
		xyprintf(0, 20, "�Ƿ��ȡ�ϴα�����ļ���");
		xyprintf(0, 40, "������Y��N:");
		op1 = getch();
		if (op1 == 'Y') {
			FILE * fp = fopen("shape.txt", "r");
			if (fp!=NULL) {/*����ȡ�ļ��ɹ�����readresultΪ1*/
				xyprintf(0, 60, "��ȡ�ļ��ɹ���");
				*preadresult = 1;
				readFromFile();/*��ȡ�ļ���Ϣ���ػ��ļ�������ͼ��*/
				fclose(fp);
				break;
			}
			else {/*����ȡ�ļ�ʧ�ܻ򲻶�ȡ�ļ�����readresultΪ0*/
				xyprintf(0, 60, "�ļ�������");
				*preadresult = 0;
				fclose(fp);
				break;
			}
		}
		if (op1 == 'N') {
			xyprintf(0, 60, "δ��ȡ");
			*preadresult = 0;
			break;
		}
	}
	return readresult;/*���ض�ȡ���*/
}
