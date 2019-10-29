#include"head.h"

// 生成一个其值等于chars的串T
int strAssign(SString T, char* chars){ 
	int i;
	if (strlen(chars) > MAX_STR_LEN)//如果chars长度大于串T长度
		return -1;
	else{
		T[0] = strlen(chars);//串T的0号单元存放chars长度
		for (i = 1; i <= T[0]; i++)
			T[i] = *(chars + i - 1);//遍历赋值
		return 1;
	}
}
