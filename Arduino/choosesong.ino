//歌曲
int Eulogyofjoytune[]=                 //根据简谱列出各频率
{
  350,350,393,441,
  441,393,350,330,
  294,294,330,350,
  350,330,330,
  350,350,393,441,
  441,393,350,330,
  294,294,330,350,
  330,294,294,
  330,330,350,294,
  330,350,393,350,294,
  330,350,393,350,330,
  294,330,221,-1,
  350,350,393,441,
  441,393,350,393,330,
  294,294,330,350,
  330,294,294
};
int lstune[]={
  262,262,393,393,
  441,441,393,
  350,350,330,330,
  294,294,262,
  393,393,350,350,
  330,330,294,
  393,393,350,350,
  330,330,294,
  262,262,393,393,
  441,441,393,
  350,350,330,330,
  294,294,262
};
int chuanyouwanli1[]={
  196,330,330,330,330,350,393,294,
  196,294,294,294,294,330,350,330,
  262,441,441,441,441,495,525,393,350,330,
  221,350,350,350,350,393,441,393,294,
  196,330,330,330,330,350,393,294,
  196,294,294,294,294,330,350,330,
  262,441,441,441,441,495,525,393,350,330,
  221,294,294,294,330,294,262,221,262
};
int twotigers1[]={
  262,294,330,262,
  262,294,330,262,
  330,350,393,
  330,350,393,
  393,441,393,350,330,262,
  393,441,393,350,330,262,
  330,196,262,
  330,196,262
};

//节拍
float Eulogyofjoybeat[]=                   //根据简谱列出各节拍
{
  1,1,1,1,
  1,1,1,1,
  1,1,1,1,
  1+0.5,0.5,1+1,
  1,1,1,1,
  1,1,1,1,
  1,1,1,1,
  1+0.5,0.5,1+1,
  1,1,1,1,
  1,0.5,0.5,1,1,
  1,0.5,0.5,1,1,
  1,1,1,1,
  1,1,1,1,
  1,1,1,0.5,0.5,
  1,1,1,1,
  1+0.5,0.5,1+1,
};
float lsbeat[]={
  1,1,1,1,
  1,1,1+1,
  1,1,1,1,
  1,1,1+1,
  1,1,1,1,
  1,1,1+1,
  1,1,1,1,
  1,1,1+1,
  1,1,1,1,
  1,1,1+1,
  1,1,1,1,
  1,1,1+1
};
float chuanyouwanli2[]={
  1,1+0.5,0.5,0.75,0.25,0.75,0.25,1+1+1,
  1,1+0.5,0.5,0.75,0.25,0.75,0.25,1+1+1,
  1,1+0.5,0.5,1,0.3,0.3,0.3,1,1,1+0.5,
  0.5,1+0.5,0.5,1,0.3,0.3,0.3,1,1+1,
  1,1+0.5,0.5,0.75,0.25,0.75,0.25,1+1+1,
  1,1+0.5,0.5,0.75,0.25,0.75,0.25,1+1+1,
  1,1+0.5,0.5,1,0.3,0.3,0.3,1,1,1+0.5,
  0.5,1+0.5,0.5,1,0.3,0.3,0.3,1,1+1
};
float twotigers2[]={
  0.5,0.5,0.5,0.5,
  0.5,0.5,0.5,0.5,
  0.5,0.5,1,
  0.5,0.5,1,
  0.25,0.25,0.25,0.25,0.5,0.5,
  0.25,0.25,0.25,0.25,0.5,0.5,
  0.5,0.5,1,
  0.5,0.5,1
};
//设置接口
int buzzerpin=5;
int ledpin=2;

void setup() {
  pinMode(buzzerpin,OUTPUT);
  pinMode(ledpin,OUTPUT);
  Serial.begin(9600);
}
//播放歌曲的函数
void start(int len,int buzzpin,int lepin,int *tune,float *beat){
  for(int x=0;x<len;x++)
  {
    tone(buzzpin,tune[x]);
    digitalWrite(lepin, HIGH); 
    delay(500*beat[x]);//与前一代码不同之处，这里将原来的500分为了400和100，分别控制led的开与关，对于蜂鸣器来说依然是500.
    digitalWrite(lepin, LOW);
    noTone(buzzpin);   
    delay(100);
  }
}
void loop() {
  String select;
  while(Serial.available()>0){
    select+=char(Serial.read());
    delay(2);
  }
  if(select!=""){
    int len;
    if(select=="Ode to Jo"){
      Serial.println("Next, we will play the Ode to Jo");
      len=sizeof(Eulogyofjoytune)/sizeof(Eulogyofjoytune[0]);
      start(len,buzzerpin,ledpin,Eulogyofjoytune,Eulogyofjoybeat);
    }else if(select=="little star"){
      Serial.println("Next, we will play the little star");
      len=sizeof(lstune)/sizeof(lstune[0]);
      start(len,buzzerpin,ledpin,lstune,lsbeat);
    }else if(select=="chuanyouwanli"){
      Serial.println("Next, we will play the chuanyouwanli");
      len=sizeof(chuanyouwanli1)/sizeof(chuanyouwanli1[0]);
      start(len,buzzerpin,ledpin,chuanyouwanli1,chuanyouwanli2);
    }else if(select=="two tigers"){
      Serial.println("Next, we will play the two tigers");
      len=sizeof(twotigers1)/sizeof(twotigers1[0]);
      start(len,buzzerpin,ledpin,twotigers1,twotigers2);
    }else{
      Serial.println("Sorry, there is no such song in the music library.");
    }
  }
  
}
