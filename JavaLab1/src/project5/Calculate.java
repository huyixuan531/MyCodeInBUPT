package project5;

public class Calculate {
  //检验输入的表达式是否用上了扑克的四个面值
  public int verifynum(String input,int[] array4) {
	 int[] flag4= {0,0,0,0};
	 String result="";
	 int a=0,b=0,c=0,d=0;
	//将字符串中的非数字字符转换为空格
	 for(int i=0;i<input.length();i++){
		 if(Character.isDigit(input.charAt(i))){
			 result+=input.charAt(i);
		 }
		 else{
			 result+=' ';
		 }
	 }
	 String[] arrStr=result.trim().split("\\s+");//去掉前后空格后，再以空格分割字符串
	 a=Integer.parseInt(arrStr[0]);//分别将四个数(char)转换成int，赋值给a,b,c,d
	 b=Integer.parseInt(arrStr[1]);
	 c=Integer.parseInt(arrStr[2]);
	 d=Integer.parseInt(arrStr[3]);
	 for(int k=0;k<4;k++) {
		 if(a==array4[k]||b==array4[k]||c==array4[k]||d==array4[k]) 
			 flag4[k]=1;//若与任一面值匹配，flag置1
	 }
	 
	 if(flag4[0]==1&&flag4[1]==1&&flag4[2]==1&&flag4[3]==1)//如果四个数都匹配
		 return 1;
	 else return 0;
  }
}
