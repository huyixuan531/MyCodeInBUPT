#include<IRremote.h>
#include<LiquidCrystal_I2C.h>


int pos[]={3,4,5,6,8,9,11,12,13,14,16,17,19,20};
_Bool modify_flag;
int modifyIndex;
int a,b,x,y,days;
LiquidCrystal_I2C lcd(0x20,16,2);
int RECV_PIN=10;   //定义红外接收的数字引脚口为10号口
int ALARM_PIN=4;   //定义蜂鸣器的接口为4
IRrecv irrecv(RECV_PIN);
decode_results results;  //定义红外接收装置的接收结果变量
short Y1,Y2,Y3,Y4;  //定义年份的四位，从高到低
short M1,M2;        //定义月份的四位，从高到低
short D1,D2;        //定义日期的四位，从高到低
short H1,H2;        //定义小时的四位，从高到低
short MI1,MI2;      //定义分钟的四位，从高到低
short S1,S2;        //定义秒数的四位，从高到低
short Date;         //定义星期
//定义判断闰年的宏定义表达式
#define ISYEARP(x) x/100!=0&&x%4==0||x%400==0?1:0
//定义每个月的天数
int dayOfMonth[13][2]={
    0,0,
    31,31,
    28,29,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31,
};
void xblink(){
  lcd.setCursor(x,y);
  lcd.blink();
}
void xNoblink(){
  lcd.noBlink();
}



void canlendarShow(){
  lcd.setCursor(3,0);    //定位要打印的位置，打印一次字符后自动加一
  lcd.print(Y1);    //打印年份第一位
  lcd.print(Y2);    //打印年份第二位
  lcd.print(Y3);    //打印年份第三位
  lcd.print(Y4);    //打印年份第四位
  lcd.print("/");   //打印分隔符‘/’
  lcd.print(M1);    //打印月份第一位
  lcd.print(M2);    //打印月份第二位
  lcd.print("/");   //打印分隔符‘/’
  lcd.print(D1);    //打印日期第一位
  lcd.print(D2);    //打印日期第一位
  lcd.setCursor(1,1);    //定位要打印的位置，打印一次字符后自动加一
  lcd.print(H1);    //打印小时第一位
  lcd.print(H2);    //打印小时第二位
  lcd.print(":");   //打印‘：’
  lcd.print(MI1);   //打印分数第一位
  lcd.print(MI2);   //打印分数第二位
  lcd.print(":");     //打印‘：’
  lcd.print(S1);    //打印秒数第一位
  lcd.print(S2);    //打印秒数第二位
  lcd.setCursor(10,1);    //定位要打印的位置，打印一次字符后自动加一
  switch(Date+1){
    case 1:lcd.print("Mon");break;
    case 2:lcd.print("Tue");break;
    case 3:lcd.print("Wed");break;
    case 4:lcd.print("Thu");break;
    case 5:lcd.print("Fri");break;
    case 6:lcd.print("Sat");break;
    case 7:lcd.print("Sun");break;
    default:lcd.print("Error！");break;
  }
}
void tita(void){
  S2=S2+1;    //秒数个位加一
  if(S2==10)    //若秒的个位满十则向秒的十位进一
  {
    S2=0;
    S1=S1+1;
    if(S1==6)    //若秒的十位满六则向分的个位进一
    {
      MI2=MI2+1;
      S1=0;
      if(MI2==10)    //分钟的个位满十则向分钟的十位进一
      {
        MI2=0;
        MI1=MI1+1;
        if(MI1==6)    //分钟的十位满六则向小时的个位进一
        {
          H2=H2+1;
          MI1=0;
          if(H2==10)       //若没满二十四小时则向小时的十位进一
          {
            H1=H1+1;
            H2=0;
          }
          if (H1==2&&H2==4)    //若小时的十位和个位为2,4时则向日的的个位进一
          {
             H1=0;
             H2=0;
             date();          //日月年进位函数
          }        
        }
      }
    }
  }
}
void date(){
  Date=(Date+1)%7;    //星期加一
  D2=D2+1;            //日期个位加一
  //如果日期到了本月最大天数，则向月份个位加一
  if(D1*10+D2>dayOfMonth[M1*10+M2][ISYEARP(Y1*1000+Y2*100+Y3*10+Y4)])
  {
    D1=0;
    D2=1;
    M2=M2+1;
    if(M1==1&&M2==3)
    {
      M1=0;
      M2=1;
      Y4=Y4+1;
      if(Y4==10)
      {
        Y4=0;
        Y3=Y3+1;
        if(Y3==10)
        {
          Y3=0;
          Y2=Y2+1;
          if(Y2==10)
          {
            Y2=0;
            Y1=Y1+1;
          }
        }
      }
    }
    if(M2==10)
    {
      M1=M1+1;
      M2=0;
    }
  }
  if(D2==10) 
  {
    D2=0;
    D1=D1+1 ; 
  }
}


void setup(){
  modifyIndex = 0;
  modify_flag = false;
  x = 3;
  y = 0;
  Serial.begin(9600);
  irrecv.enableIRIn();
  lcd.init();
  lcd.backlight();
  Y1=2,Y2=0,Y3=1,Y4=8;    //年份初始化
  M1=1,M2=2;              //月份初始化
  D1=1,D2=4;              //日期初始化
  H1=2,H2=2;              //小时初始化
  MI1=1,MI2=9;            //分钟初始化
  S1=0,S2=0;              //秒数初始化
  Date=4;                 //星期初始化
  canlendarShow();
}


void loop(){
if(irrecv.decode(&results)){
  Serial.println(results.value,HEX); 
  if(results.value==0xFD08F7){  //如果接收到的是1信号，则进入修改时间模式或退出修改时间模式
    modifyIndex=0;
    modify_flag=!modify_flag;
  if(modify_flag){//modify为true即进入修改时间模式
    xblink();
    Serial.print(modify_flag);
  }
  else{
    xNoblink();
  }
 }
  if(results.value==0xFD609F){      //如果接收到的是右快进信号
    if(modify_flag){  //判断允许光标移动
      xNoblink();
      modifyIndex=(modifyIndex+1)%14;
      x=pos[modifyIndex];
      //如果横坐标到了逻辑上的第二行，则要将其减去偏移量12，并使纵坐标为1
      if(x>12){
        x=x-12;
        y=1;
       }
       else{
        y=0;
       }
      xblink();
    } 
  }
  else if(results.value==0xFD20DF){      //如果接收到的是左快进信号
    if(modify_flag){  //判断允许光标移动
      xNoblink();
      //修改光标位置x,y
      modifyIndex=(modifyIndex+13)%14;
      x=pos[modifyIndex];
      //如果横坐标到了逻辑上的第二行，则要将其减去偏移量12，并使纵坐标为1
      if(x>12){
        x=x-12;
        y=1;
       }
       else{
        y=0;
       }
      xblink();
    }
}
  if(results.value==0xFD807F){  //如果接收到的是vol+信号，则调整当前数位的值加一，值可循环
  if(modify_flag){
  //修改时间
  if(y==0){ //年月日的修改
    if(x==8)//M1的修改
  {
    if(M2<3){    //这种情况下M1可以等于0或1
      M1=(M1+1)%2;
    }
    else{   //当M2>=3时M1只能等于0，因为不存在13,14,15等月份
      M1=0;
    }
    lcd.print(M1);
  }
  else if(x==9)     //M2的修改
  {
    if(M1==0){
      M2=(M2+1);
      if(M2==10){
        M2=1;
      }
    }
   else{
      M2=(M2+1)%3;
    }
    lcd.print(M2);
   }
   else if (x=11){  //D1
    days=dayOfMonth[M1*10+M2][ISYEARP(Y1*1000+Y2*100+Y3*10+Y4*1)];
    a=days/10;
    b=days%10;
    if(D2<=b){
      D1=(D1+1)%(a+1);
    }
    else {
      D1=(D1+1)%a;
    }
    lcd.print(D1);
 }  
    else if (x=12){  //D2
    days=dayOfMonth[M1*10+M2][ISYEARP(Y1*1000+Y2*100+Y3*10+Y4*1)];
    a=days/10;
    b=days%10;
    if(D1==a){
      if(b==0){
        D2=0;
      }
      else{
        D2=(D2+1)%(b+1);
      }
    }
    else if(D1==0){
      D2=D2+1;
      if(D2==10){
        D2=1;
      }
    }
    else{
      D2=(D2+1)%10;
    }
    lcd.print(D2);
 }  
    else if(x==3){
      Y1=(Y1+1)%10;
      lcd.print(Y1);
    }
    else if(x==4){
      Y2=(Y2+1)%10;
      lcd.print(Y2);
    }
    else if(x==5){
      Y3=(Y3+1)%10;
      lcd.print(Y3);
    }
    else if(x==6){
      Y4=(Y4+1);
      if(Y4==10){
        Y4=1;
      }
      lcd.print(Y4);
    }
  }
  else{
    if(x==1){
      if(H2<=3&&H2!=0){
        H1=(H1+1)%3;
      }
      else if(H2==0){
        H1=(H1+1);
        if(H1==3){
          H1=1;
        }
      }
      else{
        H1=(H1+1)%2;
      }
      lcd.print(H1);
    }
    else if(x==2){
      if(H1==2){
        H2=(H2+1)%4;
      }
      else{
        H2=(H2+1)%10;
      }
      lcd.print(H2);
    }
    else if(x==4){
      MI1=(MI1+1)%6;
      lcd.print(MI1);
    }
    else if(x==5){
      MI2=(MI2+1)%10;
      lcd.print(MI2);
    }
    else if(x==7){
      S1=(S1+1)%6;
      lcd.print(S1);
    }
    else{
      S2=(S2+1)%10;
      lcd.print(S2);
    }
  }
  canlendarShow();
  lcd.setCursor(x,y);
 }
}
 irrecv.resume();
}
if(modify_flag==false){
  canlendarShow();
  tita();
  }
  delay(1000);
 }
















