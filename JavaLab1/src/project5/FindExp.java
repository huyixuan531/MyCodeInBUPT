package project5;

import java.util.ArrayList;

public class FindExp {
	   //全排列
	   private static ArrayList<int[]> Permutation(int[] a) {
	   	ArrayList<int[]> arrayList = new ArrayList<>();
	   	for (int i = 0; i < 4; i++) {
	   		for (int j = 0; j < 4; j++) {
	   			if (i == j)
	   				continue;
	   			for (int k = 0; k < 4; k++) {
	   				if (j == k || k == i)
	   					continue;
	   				for (int m = 0; m < 4; m++) {
	   					if (m == k || m == j || m == i)
	   						continue;
	   					int[] b = new int[] { a[i], a[j], a[k], a[m] };
	   					arrayList.add(b);
	   				}
	   			}
	   		}
	   	}
	   	return arrayList;
	   }
	   //获取表达式中的数字
	   private static int getNum(int a, int b, char ch) {
	   	switch (ch) {
	   	case '+':
	   		return a + b;
	   	case '-':
	   		return a - b;
	   	case '*':
	   		return a * b;
	   	case '/':
	   		return a / b;
	   	}
	   	return 0;
	   }
	   //生成24点表达式
	   private static String getPoint24Answer(int[] num) {
		try {
		   	char[] t = new char[] { '+', '-', '*', '/' };
		   	ArrayList<int[]> intlist = Permutation(num);
		   	for (int z = 0; z < intlist.size(); z++) {
		   		int a[] = intlist.get(z);
		   		for (int i = 0; i < 4; i++) {
		   			if ((i == 3 && (a[0] % a[1] != 0 || a[1] % a[0] != 0))) {
		   				break;
		   			}
		   			int a12 = getNum(a[0], a[1], t[i]);
			   			for (int j = 0; j < 4; j++) {
		   				if ((j == 3 && (a12 % a[2] != 0 || a[2] % a12 != 0))) {	   					break;
			   				}
	
			   				int a123 = getNum(a12, a[2], t[j]);
	
			   				for (int k = 0; k < 4; k++) {
			   					if ((k == 3 && (a123 % a[3] != 0 || a123 % a[3] != 0)))
			   						break;
	
			   					int a1234 = getNum(a123, a[3], t[k]);
			   					if (a1234 == 24)
			   						return "(((" + a[0] + t[i] + a[1] + ")" + t[j] + a[2] + ")" + t[k] + a[3] + ") = 24";
			   				}
			   			}
			   		}
			   	}
			    return "NO ANSWER!";//若无答案
		}catch(Exception e) {
			return "NO ANSWER!";//若无答案
		}
	  }
	 //该类提供一个公有方法find()用来获得24点表达式
	   public String find(int[] after4) {
		   	return getPoint24Answer(after4);//返回找到的表达式
	   }
}
