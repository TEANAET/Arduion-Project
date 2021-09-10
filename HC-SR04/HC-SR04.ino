int Trig = 5; //发射管脚
int Echo = 6; //接收管脚
float Distance;  //距离变量
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); 
  pinMode(Trig,OUTPUT);  //输出模式
  pinMode(Echo,INPUT);   //输入模式
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(Trig,LOW);   //管脚定义为低电平
  delayMicroseconds(20);    //延迟20微秒
  digitalWrite(Trig,HIGH);  //管脚定义为高电平
  delayMicroseconds(20);    //延迟20微秒
  digitalWrite(Trig,LOW);   //管脚定义为低电平
  Distance = pulseIn(Echo,HIGH)*340/2/10000;   //计算其距离
  Serial.print("检测距离为：");
  Serial.print(Distance);
  Serial.println("cm");
  delay(1000);
}
