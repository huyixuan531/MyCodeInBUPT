#include "head.h"

//��������numbutton
//���ܣ�����������㷽������
COOR& numbutton(MOUSEMSG m, COOR& coor,int level) {
	int order, interval;//orderΪ���������intervalΪ���ַ���ı߳�
	switch(level){//��ͬ�ؿ����ַ������ʾ���ֲ�ͬ
	case 1:order = 4; interval = 135; break;
	case 2:
	case 3:
	case 4:
	case 5:order = 10; interval = 54; break;
	case 6:order = 6; interval = 90; break;
	}
	for (int i = 0; i < order; i++) {
		for (int j = 0; j < order; j++) {
			if (m.x > (j * interval + j + 30) && m.x<(j * interval + j + 30 + interval) && m.y>(i * interval + i + 30) && m.y < (i * interval + i + 30 + interval)) {
				coor.a = i;
				coor.b = j;
				return coor;//����������㷽�����꣬�磨1��2�����±귶Χ��0~(order-1)
			}
		}
	}
	return coor;
}