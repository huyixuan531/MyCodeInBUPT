package project5;

public class MyRandom{
	//生成不重复的指定范围的指定个数随机数
		public int[] random(int min, int max, int n){//参数分别为范围下界，上界，生成个数
		    if (n > (max - min + 1) || max < min) { //若参数不满足条件 
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
		//将图片编号转换成扑克面值
		public int[] trans(int[]array4) {
			int[] after4= {0,0,0,0};
			for(int i=0;i<4;i++) {
				after4[i]=(array4[i]%13);//每种花色有13张
				if(array4[i]%13==0) after4[i]=13;
			}
			return after4;
		}
 }