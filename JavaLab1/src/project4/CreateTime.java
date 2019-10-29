package project4;

import java.util.Calendar;
import java.util.GregorianCalendar;

public class CreateTime {
	public static void main(String[] args) {
		//创建两个时间对象
		Time t1=new Time();
		Time t2=new Time(555550000);
		//显示两个时间对象的时分秒
		System.out.println("第一个时间对象：");
		System.out.println("时："+t1.gethour()+";"+"分："+t1.getminute()+";"
		+"秒："+t1.getsecond()+";");
		System.out.println("第二个时间对象：");
		System.out.println("时："+t2.gethour()+";"+"分："+t2.getminute()+";"
		+"秒："+t2.getsecond()+";");
	}
}
class Time{
	private int hour,minute,second;
	public void setCurrentTime() {
		Calendar calendar=new GregorianCalendar();
		this.hour=calendar.get(Calendar.HOUR_OF_DAY);
		this.minute=calendar.get(Calendar.MINUTE);
		this.second=calendar.get(Calendar.SECOND);
	}
	public Time(){//默认构造函数
		setCurrentTime();
	}
	public Time(int ms){//指定时间的构造函数
		hour=((ms/1000)/3600)%24;
		minute=(((ms/1000)%3600)/60)%60;
		second=((ms/1000)%3600)%60;
	}
	public int gethour() {//获取时
		return hour;
	}
	public int getminute() {//获取分
		return minute;
	}
	public int getsecond() {//获取秒
		return second;
	}
}