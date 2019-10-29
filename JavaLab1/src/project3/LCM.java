package project3;

import java.util.InputMismatchException;
import java.util.Scanner;

public class LCM {
	public static void main(String[] args) {
		while(true) {
			int result=1,num1=0,num2=0,flag;
			//������ά�����ŷֱ������������Ӻ����ӳ��ִ���
			int[][] prime1=new int[50][2];
			int[][] prime2=new int[50][2];
			System.out.println("������������������С������");
			do {//do-whileѭ����flag���쳣����һ��֤�û�����Ϊ����
				flag=0;
				System.out.println("�������һ������");
				try {
				@SuppressWarnings("resource")
				Scanner scan1=new Scanner(System.in);
				num1=scan1.nextInt();
				System.out.println("������ڶ�������");
				num2=scan1.nextInt();
				}catch(InputMismatchException ex) {//�������벻Ϊ���ֵ��쳣
					System.out.println("Input should be number!");
					flag=1;
				}
			}while(flag==1);
			if(num2==1) {
				int temp=num1;
				num1=num2;
				num2=temp;
			}
			Prime prime_v=new Prime();//ʵ�����Զ�����Prime
			prime_v.getPrimeFactors(prime1,num1);//�ֱ���������������ӣ��������Ӧ����
			prime_v.getPrimeFactors(prime2,num2);
			//�������Ӽ�����С������
			int k=0,j=0;
			for(;prime1[k][0]!=0;) {//������һ����������
				for(;prime2[j][0]!=0;) {//�̶���һ������ĳ������a�������ڶ�����������b
					if(prime1[k][0]<prime2[j][0]) {//�Ƚ�a,b;��a<b
						result*=Math.pow(prime1[k][0],prime1[k][1]);//��a�˽�result
						if((prime1[k+1][0]==0)&&(prime2[j+1][0]!=0))j++;//�����ʱa�Ѿ�����1�����һ�����ӣ���b������2�����һ�����ӣ���2ָ�������
						k++;//��1ָ�������
						break;
					}
					if(prime1[k][0]>prime2[j][0]) {//��a>b
						result*=Math.pow(prime2[j][0],prime2[j][1]);//��b�˽�result
						j++;//��2ָ�������
						if(prime2[j][0]==0) {//�����ʱb�Ѿ�����2�����һ������
							result*=Math.pow(prime1[k][0],prime1[k][1]);//��aҲ�˽�result
							k++;//��1ָ�������
						}
						break;
					}
					if(prime1[k][0]==prime2[j][0]) {//��a=b
						result*=Math.pow(prime1[k][0],Math.max(prime1[k][1],prime2[k][1]));//ȡ�����ӳ������������г˷����㣬�˽�result
						k++;//��1��2ָ��������
						j++;
					}
				}
			}
			if(prime2[j][0]!=0)//�����һ�����������Ѿ������꣬���ڶ���������δ����������
				for(;prime2[j][0]!=0;j++)result*=Math.pow(prime2[j][0],prime2[j][1]);//��ʣ�µ����Ӷ��˽�result
			System.out.println("���ǵ���С������Ϊ��"+result);
			System.out.println("-----------------");
			while(true) {
				System.out.println("1�����¼��㣻2���˳�����");
				try {
				@SuppressWarnings("resource")
				Scanner scan2=new Scanner(System.in);
				int op=scan2.nextInt();
				if(op==2) System.exit(0);
				else if(op==1)break;
				//������벻��1��2���׳��쳣
				else throw new InputMismatchException("Input only can be 1 or 2");
				}catch (InputMismatchException ex) {
						System.out.println("Please input only 1 or 2!");	
				}
			}
		}
	}

}
class Prime{
	//�����������Ӽ�����ִ���������һ����ά����
	public int[][] getPrimeFactors(int[][]prime,int number){
		int j=0;
		for(int i=2;i<=number;i++) {//����С����2��ʼ����
			while(number%i==0) {//������������iΪ����
					prime[j][0]=i;//��i���������һ��
					prime[j][1]++;//i���ִ�����1����������ڶ���
					if(number%i==0&&(number/i)%i!=0) {//��number�в��ٳ���i�ظ�������
						j++;//��ά����ָ��ָ����һ��
					}
					number=number/i;//��number���޳�����i
			}
		}
		return prime;
	}
}