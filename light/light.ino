float light;
int lig =A1;
int kaiguan=4;
int val=0,mark=0,thre_value=90,zhuan=0,j=0;
String comdata="";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(lig,INPUT);
  pinMode(kaiguan,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  light = analogRead(lig);
  light=(1000/light)*80;
 // light= (light/1024)*3.3*1.515;
   // 定义光强变量名
  String  light_data = "\"light(lx)\":";
  String dataRes="{"+light_data+light+"}";

  Serial.print(dataRes);
  delay(1000);
  while (Serial.available() > 0)
{
delay(2);
//读入之后将字符串，串接到comdata上面。

comdata += char(Serial.read());
//延时一会，让串口缓存准备好下一个数字，不延时会导致数据丢失，

delay(3);
mark=1;
}

if(mark=1){
  zhuan=0
 for(int i = 0; i < comdata.length() ; i++)
        {
        //逐个分析comdata[i]字符串的文字，如果碰到文字是分隔符（这里选择逗号分割）则将结果数组位置下移一位
        //即比如11,22,33,55开始的11记到numdata[0];碰到逗号就j等于1了，
        //再转换就转换到numdata[1];再碰到逗号就记到numdata[2];以此类推，直到字符串结束
          
         
             //如果没有逗号的话，就将读到的数字*10加上以前读入的数字，
             //并且(comdata[i] - '0')就是将字符'0'的ASCII码转换成数字0（下面不再叙述此问题，直接视作数字0）。
             //比如输入数字是12345，有5次没有碰到逗号的机会，就会执行5次此语句。
             //因为左边的数字先获取到，并且numdata[0]等于0，
             //所以第一次循环是numdata[0] = 0*10+1 = 1
             //第二次numdata[0]等于1，循环是numdata[0] = 1*10+2 = 12
             //第三次是numdata[0]等于12，循环是numdata[0] = 12*10+3 = 123
             //第四次是numdata[0]等于123，循环是numdata[0] = 123*10+4 = 1234
             //如此类推，字符串将被变成数字0。
             
            zhuan = zhuan * 10 + (comdata[i] - '0');
          
        }
  if(zhuan%10!=0)
  {
  if(zhuan%10==1)
  {
  val=zhuan%10;
  }
  if(zhuan%10==2){
    val=0;
    }
  }
  mark=0;
  comdata="";
}

 if(val==1) {
    digitalWrite(kaiguan,LOW);
    }
    else
    {
      digitalWrite(kaiguan,HIGH);
      } 
}
