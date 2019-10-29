package project4;

import java.util.Calendar;
import java.util.GregorianCalendar;

public class CreateTime {
	public static void main(String[] args) {
		//��������ʱ�����
		Time t1=new Time();
		Time t2=new Time(555550000);
		//��ʾ����ʱ������ʱ����
		System.out.println("��һ��ʱ�����");
		System.out.println("ʱ��"+t1.gethour()+";"+"�֣�"+t1.getminute()+";"
		+"�룺"+t1.getsecond()+";");
		System.out.println("�ڶ���ʱ�����");
		System.out.println("ʱ��"+t2.gethour()+";"+"�֣�"+t2.getminute()+";"
		+"�룺"+t2.getsecond()+";");
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
	public Time(){//Ĭ�Ϲ��캯��
		setCurrentTime();
	}
	public Time(int ms){//ָ��ʱ��Ĺ��캯��
		hour=((ms/1000)/3600)%24;
		minute=(((ms/1000)%3600)/60)%60;
		second=((ms/1000)%3600)%60;
	}
	public int gethour() {//��ȡʱ
		return hour;
	}
	public int getminute() {//��ȡ��
		return minute;
	}
	public int getsecond() {//��ȡ��
		return second;
	}
}