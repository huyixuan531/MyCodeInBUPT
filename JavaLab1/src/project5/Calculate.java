package project5;

public class Calculate {
  //��������ı��ʽ�Ƿ��������˿˵��ĸ���ֵ
  public int verifynum(String input,int[] array4) {
	 int[] flag4= {0,0,0,0};
	 String result="";
	 int a=0,b=0,c=0,d=0;
	//���ַ����еķ������ַ�ת��Ϊ�ո�
	 for(int i=0;i<input.length();i++){
		 if(Character.isDigit(input.charAt(i))){
			 result+=input.charAt(i);
		 }
		 else{
			 result+=' ';
		 }
	 }
	 String[] arrStr=result.trim().split("\\s+");//ȥ��ǰ��ո�����Կո�ָ��ַ���
	 a=Integer.parseInt(arrStr[0]);//�ֱ��ĸ���(char)ת����int����ֵ��a,b,c,d
	 b=Integer.parseInt(arrStr[1]);
	 c=Integer.parseInt(arrStr[2]);
	 d=Integer.parseInt(arrStr[3]);
	 for(int k=0;k<4;k++) {
		 if(a==array4[k]||b==array4[k]||c==array4[k]||d==array4[k]) 
			 flag4[k]=1;//������һ��ֵƥ�䣬flag��1
	 }
	 
	 if(flag4[0]==1&&flag4[1]==1&&flag4[2]==1&&flag4[3]==1)//����ĸ�����ƥ��
		 return 1;
	 else return 0;
  }
}
