#define _CRT_SECURE_NO_WARNINGS
#include"clearFile.h"

char clearstr[5];/*�Ի���*/
extern FILE *fp;

/*��������clearFile*/
/*���ܣ�����ļ��д��������*/
void clearFile() {
	while (TRUE) {
		inputbox_getline("����ļ�", "�Ƿ�Ҫ����ļ����ݣ�\n������Y���ǣ���N���񣩣�\n���س�ȷ�ϣ�", clearstr, 5);
		if (strcmp(clearstr, "Y") == 0) {
			fopen("shape.txt", "wb");
			fclose(fp);
			break;
		}
		else if (strcmp(clearstr, "N") == 0) break;
	}
}