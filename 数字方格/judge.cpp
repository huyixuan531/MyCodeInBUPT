#include"head.h"

//函数名：judge
//功能：将玩家点击顺序和答案进行比对
int judge(int level,int** playnum) {
	int fault=0;//错误变量初始化
	//每关答案
	int anum1[10][10] = { {1,2,3,4 },
								{5, 6, 7, 8},
								{ 9, 10, 11, 12},
								{13, 14, 15, 16} };
	int anum2[10][10] = { 0,0,1,1,0,0,0,0,0,0,
	 1,1,0,0,0,0,0,0,0,0,
	 0,0,0,1,1,0,0,0,0,0,
	 0,0,0,0,0,0,0,1,0,0,
	 0,0,0,0,0,1,0,0,0,0,
	 1,1,0,0,0,0,0,0,0,0,
	 0,0,0,0,0,0,0,1,0,0,
	 0,0,1,1,0,0,0,0,0,0,
	 0,0,0,1,1,0,0,0,0,0,
	 0,0,0,0,1,0,0,0,0,1 };
	int anum3[10][10] = { 1,0,0,0,0,0,1,0,0,0,
		0,0,0,1,0,0,0,0,1,0,
		0,0,0,0,0,0,0,1,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,1,0,0,0,0,0,1,0,0,
		0,0,0,0,0,0,0,0,1,0,
		0,0,0,0,1,0,0,0,0,0,
		0,0,0,0,0,0,1,0,0,0,
		0,0,0,0,0,0,0,1,0,0,
		1,0,0,0,0,0,0,1,0,0
	};
	int anum4[10][10] = { 0,0,0,0,0,0,1,0,1,0,
		1,0,0,0,1,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,1,
		0,0,0,0,1,0,0,0,0,0,
		0,0,1,0,0,0,0,1,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,1,0,0,0,1,0,0,1,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,1,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0
	};
	int anum5[10][10] = { 1,0,0,1,0,0,1,0,0,0,
		1,0,0,0,0,1,0,0,1,1,
		0,0,0,0,1,1,0,1,0,0,
		0,0,1,0,0,0,0,1,0,0,
		1,0,0,1,0,0,1,0,0,1,
		0,1,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		1,0,0,0,0,1,1,0,0,0,
		0,0,0,0,0,1,0,1,0,0,
		1,0,0,0,1,0,0,0,1,0
	};
	
	//比对，记录错误变量递增
	switch (level) {
	case 1:
		   for (int i = 0; i < 4; i++) {
			   for (int j = 0; j < 4; j++) {
				   if (playnum[i][j] != anum1[i][j]) {
					   fault += 1;
				   }
			   }
		   }
		   break;
	case 2:
		for (int j = 0; j < 10; j++)
		{
			for (int i = 0; i < 10; i++)
			{
				if (playnum[i][j] != anum2[i][j])
				{
					fault += 1;
				}
			}
		}; 
		break;
	case 3:
		for (int j = 0; j < 10; j++)
		{
			for (int i = 0; i < 10; i++)
			{
				if (playnum[i][j] != anum3[i][j])
				{
					fault += 1;
				}
			}
		};
		break;
	case 4:
	for (int j = 0; j < 10; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			if (playnum[i][j] != anum4[i][j])
			{
				fault += 1;
			}
		}
	}; 
    break;
	case 5:
	for (int j = 0; j < 10; j++)
	{
		for (int i = 0; i < 10; i++)
		{
			if (playnum[i][j] != anum5[i][j])
			{
				fault += 1;
			}
		}
	};
	break;
	case 6:
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				if (playnum[i][j] != anum6[i][j]) {
					fault += 1;
				}
			}
		}
		break;
	}
	return fault;
}

//函数名：store
//功能：按顺序存储用户所按数字
int** store(COOR& coor,int **playnum,int level) {
	int order = 0;
	switch (level) {
	case 1:
		order = 4;
		playnum[step1][step2] = matrix1[coor.a][coor.b]; //按顺序点数中：按序存入所点数字
		step2++;
		if (step2 > order-1) {
			step1++;
			step2 = 0;
		};break;
	case 2:
	case 4:
	case 5:
	case 3:playnum[coor.a][coor.b] = 1; break;//找特殊的数中：被按下的键存为1
	case 6:
		order = 6;
		playnum[step1][step2] = matrix6[coor.a][coor.b];//按顺序点数中：按序存入所点数字
		step2++;
		if (step2 > order - 1) {
			step1++;
			step2 = 0;
		}; break;
	}	
	return playnum;
}