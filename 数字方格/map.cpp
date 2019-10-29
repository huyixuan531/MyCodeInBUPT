#include"head.h"

//函数名：map
//功能：显示不同关卡的地图
void map(int level) {
	int order, interval;//矩阵阶数
	int matrix[10][10] = { 0 };//要被比对的答案数组，每关不同
	switch (level) {
	case 1:
		order = 4; 
		interval = 135;
		for (int k = 0; k < order; k++) {
			for (int m = 0; m < order; m++) {
				matrix[k][m] = matrix1[k][m];
			}
		}
		break;
	case 2:
		order = 10; 
		interval = 54; 
		for (int k = 0; k < order; k++) {
			for (int m = 0; m < order; m++) {
				matrix[k][m] = matrix2[k][m];
			}
		}
		break;
	case 3:
		order = 10;
		interval = 54;
		for (int k = 0; k < order; k++) {
			for (int m = 0; m < order; m++) {
				matrix[k][m] = matrix3[k][m];
			}
		}
		break;
	case 4:
		order = 10;
		interval = 54;
		for (int k = 0; k < order; k++) {
			for (int m = 0; m < order; m++) {
				matrix[k][m] = matrix4[k][m];
			}
		}
		break;
	case 5:
		order = 10;
		interval = 54;
		for (int k = 0; k < order; k++) {
			for (int m = 0; m < order; m++) {
				matrix[k][m] = matrix5[k][m];
			}
		}
		break;
	case 6:
		order = 6;
		interval = 90;
		for (int k = 0; k < order; k++) {
			for (int m = 0; m < order; m++) {
				matrix[k][m] = matrix6[k][m];
			}
		}
		break;
	}
	
	IMAGE img1, img2, img3, img4, img5, img6, img7, img8, img9, img10,
		img11, img12, img13, img14, img15, img16, img17, img18, img19, img20,
		img21, img22, img23, img24, img25, img26, img27, img28, img29, img30,
		img31, img32, img33, img34, img35, img36, img37, img38, img39, img40,
		img41, img42, img43, img44, img45, img46, img47, img48, img49, img50,
		img51, img52, img53, img54, img55, img56, img57, img58, img59, img60;
	for (int i = 0; i < order; i++)
	{
		for (int j = 0; j < order; j++)
		{
			switch (matrix[i][j])
			{
			case 0:break;
			case 1:loadimage(&img1, ".\\res\\1.JPG",interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img1); break;
			case 2:loadimage(&img2, ".\\res\\2.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img2); break;
			case 3:loadimage(&img3, ".\\res\\3.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img3); break;
			case 4:loadimage(&img4, ".\\res\\4.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img4); break;
			case 5:loadimage(&img5, ".\\res\\5.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img5); break;
			case 6:loadimage(&img6, ".\\res\\6.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img6); break;
			case 7:loadimage(&img7, ".\\res\\7.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img7); break;
			case 8:loadimage(&img8, ".\\res\\8.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img8); break;
			case 9:loadimage(&img9, ".\\res\\9.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img9); break;
			case 10:loadimage(&img10, ".\\res\\10.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img10); break;
			case 11:loadimage(&img11, ".\\res\\11.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img11); break;
			case 12:loadimage(&img12, ".\\res\\12.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img12); break;
			case 13:loadimage(&img13, ".\\res\\13.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img13); break;
			case 14:loadimage(&img14, ".\\res\\14.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img14); break;
			case 15:loadimage(&img15, ".\\res\\15.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img15); break;
			case 16:loadimage(&img16, ".\\res\\16.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img16); break;
			case 17:loadimage(&img17, ".\\res\\17.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img17); break;
			case 18:loadimage(&img18, ".\\res\\18.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img18); break;
			case 19:loadimage(&img19, ".\\res\\19.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img19); break;
			case 20:loadimage(&img20, ".\\res\\20.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img20); break;
			case 21:loadimage(&img21, ".\\res\\21.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img21); break;
			case 22:loadimage(&img22, ".\\res\\22.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img22); break;
			case 23:loadimage(&img23, ".\\res\\23.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img23); break;
			case 24:loadimage(&img24, ".\\res\\24.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img24); break;
			case 25:loadimage(&img25, ".\\res\\25.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img25); break;
			case 26:loadimage(&img26, ".\\res\\26.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img26); break;
			case 27:loadimage(&img27, ".\\res\\27.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img27); break;
			case 28:loadimage(&img28, ".\\res\\28.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img28); break;
			case 29:loadimage(&img29, ".\\res\\29.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img29); break;
			case 30:loadimage(&img30, ".\\res\\30.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img30); break;
			case 31:loadimage(&img31, ".\\res\\31.JPG", interval, interval); putimage(j * interval +j+30, i * interval + i + 30, &img31); break;
			case 32:loadimage(&img32, ".\\res\\32.JPG", interval, interval); putimage(j * interval +j+ 30, i * interval + i + 30, &img32); break;
			case 33:loadimage(&img33, ".\\res\\33.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img33); break;
			case 34:loadimage(&img34, ".\\res\\34.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img34); break;
			case 35:loadimage(&img35, ".\\res\\35.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img35); break;
			case 36:loadimage(&img36, ".\\res\\36.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img36); break;
			case 37:loadimage(&img37, ".\\res\\37.JPG", interval,interval); putimage(j * interval + j + 30, i * interval + i + 30, &img37); break;
			case 38:loadimage(&img38, ".\\res\\38.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img38); break;
			case 39:loadimage(&img39, ".\\res\\39.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img39); break;
			case 40:loadimage(&img40, ".\\res\\40.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img40); break;
			case 41:loadimage(&img41, ".\\res\\41.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img41); break;
			case 42:loadimage(&img42, ".\\res\\42.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img42); break;
			case 43:loadimage(&img43, ".\\res\\43.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img43); break;
			case 44:loadimage(&img44, ".\\res\\44.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img44); break;
			case 45:loadimage(&img45, ".\\res\\45.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img45); break;
			case 46:loadimage(&img46, ".\\res\\46.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img46); break;
			case 47:loadimage(&img47, ".\\res\\47.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img47); break;
			case 48:loadimage(&img48, ".\\res\\48.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img48); break;
			case 49:loadimage(&img49, ".\\res\\49.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img49); break;
			case 50:loadimage(&img50, ".\\res\\50.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img50); break;
			case 51:loadimage(&img51, ".\\res\\51.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img51); break;
			case 52:loadimage(&img52, ".\\res\\52.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img52); break;
			case 53:loadimage(&img53, ".\\res\\53.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img53); break;
			case 54:loadimage(&img54, ".\\res\\54.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img54); break;
			case 55:loadimage(&img55, ".\\res\\55.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img55); break;
			case 56:loadimage(&img56, ".\\res\\56.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img56); break;
			case 57:loadimage(&img57, ".\\res\\57.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img57); break;
			case 58:loadimage(&img58, ".\\res\\58.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img58); break;
			case 59:loadimage(&img59, ".\\res\\59.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img59); break;
			case 60:loadimage(&img60, ".\\res\\60.JPG", interval, interval); putimage(j * interval + j + 30, i * interval + i + 30, &img60); break;
			}
		}
	}
}
