package project4;

public class DrawRec {
	public static void main(String[] args) {
		//创建两个矩形对象
		Rectangle r1= new Rectangle(4,40);
		Rectangle r2= new Rectangle(3.5,35.9);
		r1.setcolor("RED");
		r2.setcolor("RED");
		//显示两个矩形的属性并计算面积和周长
		System.out.println("第一个矩形：");
		System.out.println("宽："+r1.getwidth()+";"+"高："+r1.getheight()+";"
		+"颜色："+r1.getcolor()+";"+"面积："+r1.getArea()+";"+"周长："+r1.getPerimeter()+";");
		System.out.println("第二个矩形：");
		System.out.println("宽："+r2.getwidth()+";"+"高："+r2.getheight()+";"
		+"颜色："+r2.getcolor()+";"+"面积："+r2.getArea()+";"+"周长："+r2.getPerimeter()+";");
	}
}
class Rectangle{
	private double width,height;
	private String color;
	public Rectangle(){//默认矩形构造函数
		width=1;
		height=1;
		color="WHITE";
	}
	public Rectangle(double w,double h){//指定宽高的构造函数
		width=w;
		height=h;
	}
	public double getwidth() {//获取宽
		return width;
	}
	public void setwidth(double w) {//设置宽
		this.width=w;
	}
	public double getheight() {//获取高
		return height;
	}
	public void setheight(double h) {//设置高
		this.height=h;
	}
	public String getcolor() {//获取颜色
		return color;
	}
	public void setcolor(String c) {//设置颜色
		this.color=c;
	}
	public double getArea() {//计算面积
		return width*height;
	}
	public double getPerimeter() {//计算周长
		return 2*(width+height);
	}
}
