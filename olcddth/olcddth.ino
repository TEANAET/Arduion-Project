#include<Wire.h> //加载调用i2c和spi通讯库
#include<Adafruit_GFX.h> //调用oled库
#include<Adafruit_SSD1306.h>//调用ssd1306驱动库
#include<DHT.h>          //调用DHT库
#define OLED_RESET 4     //设置4号引脚为oled的复位引脚
#define OLED 8
Adafruit_SSD1306 display(128,64,&Wire, OLED_RESET); //设置一个ssd1306的对象
DHT DHT_11(OLED, DHT11);   //设置一个DHT函数对象，输入其连接的引脚以及传感器名称
void setup() {
  // put your setup code here, to run once:
  Wire.begin();  //初始化其通讯库
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  //初始化oled，0x3C为oled的地址
  DHT_11.begin(); //初始化DHT11传感器
}
void displayTempHumid()
{
  delay(1000);
  float Humidity = DHT_11.readHumidity();  //读取DHT11的湿度
  float Temperature = DHT_11.readTemperature();//读取DHT11的温度
  display.clearDisplay();  //清空oled屏幕
  display.setTextColor(WHITE); //设置其像素点发光
  display.setTextSize(1);      //设置oled的字体大小
  display.setCursor(33, 0);     //设置其oled的字符显示位置，第一个参数是列，第二个参数是行
  display.print("TempHumid"); //在oled上打印字符
  display.setCursor(0, 20);   
  display.print("Humidity:  ");
  display.print(Humidity);
  display.print("%");
  display.setCursor(0, 40);
  display.print("Temperature: ");
  display.print(Temperature);
  display.print(" C");
}
void loop() {
  // put your main code here, to run repeatedly:
  displayTempHumid(); //调用函数
  display.display();  // 开显示
}
