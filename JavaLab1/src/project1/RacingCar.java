package project1;

import javafx.animation.PathTransition;
import javafx.application.Application;
import javafx.collections.ObservableList;
import javafx.geometry.Insets;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.shape.*;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import javafx.util.Duration;

public class RacingCar extends Application{
	@Override
	public void start(Stage primaryStage) {
		//Create 4 pane
		Pane pane1=new Pane();
		Pane pane2=new Pane();
		Pane pane3=new Pane();
		Pane pane4=new Pane();
		//Create 4 car and place them in panes
		Car car1=new Car(pane1);
		Car car2=new Car(pane2);
		Car car3=new Car(pane3);
		Car car4=new Car(pane4);
		//Create a HBox
		HBox hbox=new HBox(5);
		hbox.setPadding(new Insets(5,5,5,5));
		//Create some labels and TextField and put them in HBox
		TextField tx1=new TextField();
		TextField tx2=new TextField();
		TextField tx3=new TextField();
		TextField tx4=new TextField();
		hbox.getChildren().addAll(new Label("Car 1:"),tx1,new Label("Car 2:"),tx2,
				new Label("Car 3:"),tx3,new Label("Car 4:"),tx4);
		//Place nodes in a VBox
		VBox vbox=new VBox(5);
		vbox.setPadding(new Insets(5,5,5,5));
		vbox.getChildren().addAll(hbox,pane1,pane2,pane3,pane4);
		
		//TextField's EventHandler
		tx1.setOnAction(e-> {
			try {
		    		int input1 = Integer.valueOf(tx1.getText()).intValue();
		    		car1.setspeed(input1);
			}catch(Exception ex) {
				System.out.println("Please input number!");
			}
		    		car1.run();
		});
		tx2.setOnAction(e-> {
			try {
		    		int input2 = Integer.valueOf(tx2.getText()).intValue();
		    		car2.setspeed(input2);
			}catch(Exception ex) {
				System.out.println("Please input number!");
			}
		    		car2.run();
		});
		tx3.setOnAction(e-> {
			try {
		    		int input3 = Integer.valueOf(tx3.getText()).intValue();
		    		car3.setspeed(input3);
			}catch(Exception ex) {
				System.out.println("Please input number!");
			}
		    		car3.run();
		});
		tx4.setOnAction(e->{
			try {
		    		int input4 = Integer.valueOf(tx4.getText()).intValue();
		    		car4.setspeed(input4); 
			}catch(Exception ex) {
				System.out.println("Please input number!");
			}
		    		car4.run();
		});
		
		//Create a scene and place it in stage
		Scene scene=new Scene(vbox,850,350);
		primaryStage.setTitle("Exercise16_17");
		primaryStage.setScene(scene);
		primaryStage.show();
	}
}
class Car extends Pane{
	//创建一个移动动画类PathTransition的对象
	private PathTransition pt = new PathTransition();
	private int speed=100;
	private Line l=new Line(0,65,830,65);//小车跑道
	private Group group=new Group();
	Car(Pane pane){//画一辆小车
        Rectangle r=new Rectangle(0,50,50,10);
        Circle c1=new Circle(15,63,5);
        Circle c2=new Circle(35,63,5);
        Polygon p=new Polygon();
        ObservableList<Double> list=p.getPoints();
        list.addAll(15.0,40.0,5.0,50.0,35.0,50.0,25.0,40.0);
        r.setFill(Color.LIGHTGREEN);
        c1.setFill(Color.BLACK);
        c2.setFill(Color.BLACK);
        p.setFill(Color.RED);    
        group.getChildren().addAll(p,r,c1,c2);//将小车各部分形状绑成组
        pane.getChildren().addAll(group,l);
	}
    void run() {//使小车运动的函数
		  pt.setDuration(Duration.millis(speed*100));//设置动画周期持续时间
		  pt.setPath(l);//小车运动轨迹
		  pt.setNode(group);//设置要移动的图形为小车组
		  pt.setAutoReverse(false);//设置不自动转向
		  pt.setCycleCount(1);//设置循环次数为1
		  pt.play();
		  return;
	}	
	void setspeed(int sp) {//设置小车速度因子
		speed=sp;
	}
	
}
