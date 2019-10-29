package project2;

import java.util.InputMismatchException;
import java.util.Scanner;

public class TaxTable {
	public static void main(String[] args) {
		while(true) {
			double downbound=0,upbound=0,interval=0;
			double level1=0,level2=0,level3=0,level4=0,level5=0;
			double tax=0;
			while(true) {
				System.out.println("��������Ҫ��ӡ˰��Ľ���½�(��λ:$)��");
				try {
				@SuppressWarnings("resource")
				Scanner scan1=new Scanner(System.in);
				downbound=scan1.nextDouble();
				System.out.println("��������Ҫ��ӡ˰��Ľ���Ͻ�(��λ:$)��");
				upbound=scan1.nextDouble();
				System.out.println("��������Ҫ��ӡ˰��Ľ����(��λ:$)��");
				interval=scan1.nextDouble();
				//��������Ϊ0���׳��쳣
				if(interval==0)throw new IllegalAccessException("Input is not a number");
				//���½�����Ͻ�����벻Ϊ���֣��׳��쳣
				if(downbound>=upbound)throw new InputMismatchException("Downbound must be smaller than upbound");
				else break;
				}catch(InputMismatchException ex) {
					System.out.println("Input should be number!And downbound must be smaller than upbound!");
				}
				catch(IllegalAccessException e) {
					System.out.println("Interval shouldn't be zero!");
				}
			}
			System.out.println("--------------------------------------------");
			System.out.println("taxable  Single   Married  Married   Head of");
			System.out.println("income             joint   Separate  a House");
			for(;downbound<=upbound;downbound+=interval){
				System.out.print(downbound+"  ");
				for(int mode=1;mode<=4;mode++){
				switch(mode){
				case 1://X
				level1=7300;
				level2=29700;
				level3=71950;
				level4=15150;
				level5=326450;
				break;
				case 2://Y-1
				level1=14600;
				level2=59400;
				level3=119950;
				level4=182800;
				level5=326450;
				break;
				case 3://Y-2
				level1=7300;
				level2=29700;
				level3=59975;
				level4=91400;
				level5=163225;
				break;
				case 4://Z
				level1=10450;
				level2=39800;
				level3=102800;
				level4=166450;
				level5=326450;
				break;
				}
				if(downbound<=level1)tax=downbound*0.1;
				else if(downbound<=level2)tax=level1+(downbound-level1)*0.15;
				else if(downbound<=level3)tax=level2+(downbound-level2)*0.25;
				else if(downbound<=level4)tax=level3+(downbound-level3)*0.28;
				else if(downbound<=level5)tax=level4+(downbound-level4)*0.33;
				else tax=level5+(downbound-level5)*0.35;
				System.out.print(tax+"  ");
				  }
			System.out.println(" ");
			}
			System.out.println("--------------------------------------------");
			while(true) {
				System.out.println("1��������ӡ��һ�ű�2���˳�����");
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
