#include "head.h"

//函数名：numbutton
//功能：计算鼠标所点方格坐标
COOR& numbutton(MOUSEMSG m, COOR& coor,int level) {
	int order, interval;//order为矩阵阶数，interval为数字方格的边长
	switch(level){//不同关卡数字方格的显示布局不同
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
				return coor;//返回鼠标所点方格坐标，如（1，2），下标范围：0~(order-1)
			}
		}
	}
	return coor;
}