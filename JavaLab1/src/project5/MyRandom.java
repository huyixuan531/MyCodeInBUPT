package project5;

public class MyRandom{
	//���ɲ��ظ���ָ����Χ��ָ�����������
		public int[] random(int min, int max, int n){//�����ֱ�Ϊ��Χ�½磬�Ͻ磬���ɸ���
		    if (n > (max - min + 1) || max < min) { //���������������� 
		           return null;  
		       }  
		    int[] result = new int[n];  
		    int count = 0;  
		    while(count < n) {  
		        int num = (int) (Math.random() * (max - min)) + min;  
		        boolean flag = true;  
		        for (int j = 0; j < n; j++) {  
		            if(num == result[j]){  
		                flag = false;  
		                break;  
		            }  
		        }  
		        if(flag){  
		            result[count] = num;  
		            count++;  
		        }  
		    }  
		    return result;  
		}  
		//��ͼƬ���ת�����˿���ֵ
		public int[] trans(int[]array4) {
			int[] after4= {0,0,0,0};
			for(int i=0;i<4;i++) {
				after4[i]=(array4[i]%13);//ÿ�ֻ�ɫ��13��
				if(array4[i]%13==0) after4[i]=13;
			}
			return after4;
		}
 }