package project4;

public class DrawRec {
	public static void main(String[] args) {
		//�����������ζ���
		Rectangle r1= new Rectangle(4,40);
		Rectangle r2= new Rectangle(3.5,35.9);
		r1.setcolor("RED");
		r2.setcolor("RED");
		//��ʾ�������ε����Բ�����������ܳ�
		System.out.println("��һ�����Σ�");
		System.out.println("��"+r1.getwidth()+";"+"�ߣ�"+r1.getheight()+";"
		+"��ɫ��"+r1.getcolor()+";"+"�����"+r1.getArea()+";"+"�ܳ���"+r1.getPerimeter()+";");
		System.out.println("�ڶ������Σ�");
		System.out.println("��"+r2.getwidth()+";"+"�ߣ�"+r2.getheight()+";"
		+"��ɫ��"+r2.getcolor()+";"+"�����"+r2.getArea()+";"+"�ܳ���"+r2.getPerimeter()+";");
	}
}
class Rectangle{
	private double width,height;
	private String color;
	public Rectangle(){//Ĭ�Ͼ��ι��캯��
		width=1;
		height=1;
		color="WHITE";
	}
	public Rectangle(double w,double h){//ָ����ߵĹ��캯��
		width=w;
		height=h;
	}
	public double getwidth() {//��ȡ��
		return width;
	}
	public void setwidth(double w) {//���ÿ�
		this.width=w;
	}
	public double getheight() {//��ȡ��
		return height;
	}
	public void setheight(double h) {//���ø�
		this.height=h;
	}
	public String getcolor() {//��ȡ��ɫ
		return color;
	}
	public void setcolor(String c) {//������ɫ
		this.color=c;
	}
	public double getArea() {//�������
		return width*height;
	}
	public double getPerimeter() {//�����ܳ�
		return 2*(width+height);
	}
}
