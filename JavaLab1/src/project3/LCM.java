package project3;

import java.util.InputMismatchException;
import java.util.Scanner;

public class LCM {
	public static void main(String[] args) {
		while(true) {
			int result=1,num1=0,num2=0,flag;
			//两个二维数组存放分别两个数的因子和因子出现次数
			int[][] prime1=new int[50][2];
			int[][] prime2=new int[50][2];
			System.out.println("本程序求两个数的最小公倍数");
			do {//do-while循环、flag和异常处理一起保证用户输入为数字
				flag=0;
				System.out.println("请输入第一个数：");
				try {
				@SuppressWarnings("resource")
				Scanner scan1=new Scanner(System.in);
				num1=scan1.nextInt();
				System.out.println("请输入第二个数：");
				num2=scan1.nextInt();
				}catch(InputMismatchException ex) {//捕获输入不为数字的异常
					System.out.println("Input should be number!");
					flag=1;
				}
			}while(flag==1);
			if(num2==1) {
				int temp=num1;
				num1=num2;
				num2=temp;
			}
			Prime prime_v=new Prime();//实例化自定义类Prime
			prime_v.getPrimeFactors(prime1,num1);//分别计算两个数的因子，并存入对应数组
			prime_v.getPrimeFactors(prime2,num2);
			//跟据因子计算最小公倍数
			int k=0,j=0;
			for(;prime1[k][0]!=0;) {//遍历第一个数的因子
				for(;prime2[j][0]!=0;) {//固定第一个数的某个因子a，遍历第二个数的因子b
					if(prime1[k][0]<prime2[j][0]) {//比较a,b;若a<b
						result*=Math.pow(prime1[k][0],prime1[k][1]);//将a乘进result
						if((prime1[k+1][0]==0)&&(prime2[j+1][0]!=0))j++;//如果此时a已经是数1的最后一个因子，且b不是数2的最后一个因子，数2指针向后移
						k++;//数1指针向后移
						break;
					}
					if(prime1[k][0]>prime2[j][0]) {//若a>b
						result*=Math.pow(prime2[j][0],prime2[j][1]);//将b乘进result
						j++;//数2指针向后移
						if(prime2[j][0]==0) {//如果此时b已经是数2的最后一个因子
							result*=Math.pow(prime1[k][0],prime1[k][1]);//将a也乘进result
							k++;//数1指针向后移
						}
						break;
					}
					if(prime1[k][0]==prime2[j][0]) {//若a=b
						result*=Math.pow(prime1[k][0],Math.max(prime1[k][1],prime2[k][1]));//取该因子出现最大次数进行乘方运算，乘进result
						k++;//数1数2指针均向后移
						j++;
					}
				}
			}
			if(prime2[j][0]!=0)//如果第一个数的因子已经遍历完，但第二个数还有未遍历的因子
				for(;prime2[j][0]!=0;j++)result*=Math.pow(prime2[j][0],prime2[j][1]);//把剩下的因子都乘进result
			System.out.println("它们的最小公倍数为："+result);
			System.out.println("-----------------");
			while(true) {
				System.out.println("1、重新计算；2、退出程序");
				try {
				@SuppressWarnings("resource")
				Scanner scan2=new Scanner(System.in);
				int op=scan2.nextInt();
				if(op==2) System.exit(0);
				else if(op==1)break;
				//如果输入不是1或2，抛出异常
				else throw new InputMismatchException("Input only can be 1 or 2");
				}catch (InputMismatchException ex) {
						System.out.println("Please input only 1 or 2!");	
				}
			}
		}
	}

}
class Prime{
	//计算数的因子及其出现次数，存入一个二维数组
	public int[][] getPrimeFactors(int[][]prime,int number){
		int j=0;
		for(int i=2;i<=number;i++) {//从最小因子2开始遍历
			while(number%i==0) {//若能整除，则i为因子
					prime[j][0]=i;//将i存入数组第一列
					prime[j][1]++;//i出现次数加1，存入数组第二列
					if(number%i==0&&(number/i)%i!=0) {//若number中不再出现i重复的因子
						j++;//二维数组指针指向下一行
					}
					number=number/i;//从number中剔除因子i
			}
		}
		return prime;
	}
}