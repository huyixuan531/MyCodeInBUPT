package project5;

import javax.script.ScriptEngine;
import javax.script.ScriptEngineManager;
import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.*;
import javafx.stage.Stage;

public class Game24 extends Application{
	int[] array4= {0,0,0,0};//存储随机数表示图片编号(1~52)
	int[] after4= {0,0,0,0};//存储将图片编号转换后的扑克面值(1~13)
	@Override
	public void start(Stage primaryStage) {
		//New 4 random numbers
		MyRandom myrandom=new MyRandom();
		array4=myrandom.random(1, 52, 4);//产生4个1~52的不重复随机数
		after4=myrandom.trans(array4);//将随机数转换成扑克面值
		//控制台输出四个面值便于计算
		System.out.println(after4[0]+" "+after4[1]+" "+after4[2]+" "+after4[3]);
		//UI
		//Create 4 images
		Image img1=new Image("file:card/"+array4[0]+".png");
		Image img2=new Image("file:card/"+array4[1]+".png");
		Image img3=new Image("file:card/"+array4[2]+".png");
		Image img4=new Image("file:card/"+array4[3]+".png");
		ImageView imgview1=new ImageView(img1);
		ImageView imgview2=new ImageView(img2);
		ImageView imgview3=new ImageView(img3);
		ImageView imgview4=new ImageView(img4);
		//Create buttons, TextFields, and Labels 
		Button bt1=new Button("Find a Solution");
		Button bt2=new Button("Refresh");
		Button bt3=new Button("Verify");
		TextField tf1=new TextField();
		TextField tf2=new TextField();
		Label l=new Label("Enter an expression:");
		//Create 3 HBox
		HBox hbox1=new HBox();
		HBox hbox2=new HBox();
		HBox hbox3=new HBox();
		//Place nodes into HBox
		hbox1.getChildren().addAll(bt1,tf1,bt2);
		hbox1.setSpacing(10);
		hbox1.setAlignment(Pos.CENTER);
		hbox2.getChildren().addAll(imgview1,imgview2,imgview3,imgview4);
		hbox2.setSpacing(10);
		hbox2.setAlignment(Pos.CENTER);
		hbox3.getChildren().addAll(l,tf2,bt3);
		hbox3.setSpacing(10);
		hbox3.setAlignment(Pos.CENTER);
		//Create a VBox and put 3 HBox in it
		VBox vbox=new VBox();
		vbox.setPadding(new Insets(10));
		vbox.setSpacing(10);
		vbox.setAlignment(Pos.CENTER);
		vbox.getChildren().addAll(hbox1,hbox2,hbox3);
		
		//Buttons' EventHandlers
		bt2.setOnAction(e->{//更新按钮
			array4=myrandom.random(1, 52, 4);//重新产生四个随机数
			after4=myrandom.trans(array4);//重新转换成面值
			changeimg(array4,hbox2);//更新图片
			tf2.clear();//将上一题输入框2内容清除
		});
		bt1.setOnAction(e->{//Find a Solution按钮
			FindExp findexp=new FindExp();
			tf1.setPromptText(findexp.find(after4));//在文本框1中显示出找到的24点表达式
		});
		bt3.setOnAction(e->{//验证按钮
			ScriptEngine jse=new ScriptEngineManager().getEngineByName("JavaScript");
			String strs=tf2.getText();//获取输入表达式
			try {
				Calculate calculate=new Calculate();
				int temp=Integer.parseInt(jse.eval(strs).toString());//将表达式转换成int并计算结果
				//若表达式结果等于24，且每个扑克面额都用到了
				if((temp==24)&&(calculate.verifynum(tf2.getText(),after4)==1))
					tf1.setPromptText("Bingo!");
				else tf1.setPromptText("Wrong!");
				System.out.println("计算结果为："+jse.eval(strs));//控制台显示计算结果便于检查是否算错
			}catch(Exception t) {//若输入不构成表达式
				tf1.setPromptText("Wrong!");
			}
		});
		
		//Create a scene and place it in stage
		Scene scene=new Scene(vbox);
		primaryStage.setTitle("Exercise25_9:24-Point Card Game");
		primaryStage.setScene(scene);
		primaryStage.show();
	}
	
	public void changeimg(int[] array4,HBox hbox2) {//更新图片
		hbox2.getChildren().clear();//将原有图片节点清空
		//添加新图片
		Image img1=new Image("file:card/"+array4[0]+".png");
		Image img2=new Image("file:card/"+array4[1]+".png");
		Image img3=new Image("file:card/"+array4[2]+".png");
		Image img4=new Image("file:card/"+array4[3]+".png");
		ImageView imgview1=new ImageView(img1);
		ImageView imgview2=new ImageView(img2);
		ImageView imgview3=new ImageView(img3);
		ImageView imgview4=new ImageView(img4);
		hbox2.getChildren().addAll(imgview1,imgview2,imgview3,imgview4);
		//重新在控制台输出四个面值
		System.out.println(after4[0]+" "+after4[1]+" "+after4[2]+" "+after4[3]);
		return;
	}
}
