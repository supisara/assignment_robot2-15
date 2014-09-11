#include <SoftwareSerial.h>
#define rxPin 18
#define txPin 18
SoftwareSerial MySerial = SoftwareSerial(rxPin,txPin);
int gp2;
float d;
void setup()
{
  pinMode(txPin,OUTPUT);
  MySerial.begin(9600);
  delay(1000);
}
void LCD_CMD(int c)
{
  MySerial.write(0xFE);
  MySerial.write(c);
}
void loop()
{
  gp2 = analogRead(2);
  d = (2914/(gp2+5))-1;
  LCD_CMD(0x8A);
  MySerial.print(gp2,DEC);
  
  LCD_CMD(0xC0);
  MySerial.print("Distance= ");
  LCD_CMD(0xCA);
  MySerial.print(d,DEC);
  LCD_CMD(0xCE);
  MySerial.print("CM");
  delay(200);
}
