#include<MsTimer2.h>
int pin=13,spin=12,light=11;
volatile int state=HIGH;
volatile int sta=LOW;
volatile int stat=HIGH;
void setup() {
  // put your setup code here, to run once:
  pinMode(pin,OUTPUT);
  pinMode(spin,OUTPUT);
  pinMode(light,OUTPUT);
  //attachInterrupt(0,blink,CHANGE);
  MsTimer2::set(100,blink);
  MsTimer2::start();
 // pinMode(pin,OUTPUT);
  //pinMode(spin,OUTPUT);
  //MsTimer2::stop();

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pin,state);
  digitalWrite(spin,sta);
  digitalWrite(light,stat);
}
void blink()
{
  state=!state;//取反
  sta=!sta;
  stat=!stat;
  }
