/*
Author: Manuel Ballesteros
        Damián Junquera
Test Graphic Library of old Nokia 5110 LCD Display.
 */

#include <LCD5110_Graph.h>

LCD5110 lcd(8,9,10,11,12);

extern unsigned char SmallFont[];
extern unsigned char BigNumbers[];
extern uint8_t borderRoundedIcon[];

char TempCelcius[6];

float tempC = 27.8;

void setup(void)
{
  lcd.InitLCD();
}

void loop(void)
{ 
  lcd.clrScr();
  lcd.drawBitmap(0, 0, borderRoundedIcon, 84, 48);

  convertToString(tempC);  //These are degrees.
  lcd.setFont(BigNumbers);
  lcd.print(TempCelcius,22,14); // You can set position of the text here.
  lcd.setFont(SmallFont);
  lcd.print("Manuel Home",17,5);

  lcd.update();  
  delay(1000);
}
void convertToString(float number)
{
   dtostrf(number, 3, 1, TempCelcius);
}
