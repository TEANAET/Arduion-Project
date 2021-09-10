#include<LiquidCrystal.h>
#include<OneWire.h>
#include<DallasTemperature.h>
#define ONE_WIRE_BUS 2
OneWire temp(ONE_WIRE_BUS);
DallasTemperature sensors(&temp);
LiquidCrystal lcd(12,11,9,8,7,6);
float temperature = 0;
void setup() {
//   put your setup code here, to run once:
  Serial.begin(9600);
  sensors.begin();
  lcd.begin(16,2);
  lcd.print("Arduino world");
  delay(1000);
}
void loop() {
//   put your main code here, to run repeatedly:
  sensors.requestTemperatures();
  temperature=sensors.getTempCByIndex(0);
  delay(100);
  temperature=(temperature*10);
  lcd.clear();
  lcd.print("temperature is");
  lcd.setCursor(0,1);
  lcd.print((long)temperature/10);
  lcd.print(".");
  lcd.print((long)temperature%10);
  lcd.print((char)223);
  lcd.print("C");
  delay(1000);
  lcd.print(millis()/100);

}
