#include <LiquidCrystal.h>
const int BUZZER=9;
const int LDR = A0; 
const int BUTTON = 7;
LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

void setup()
{
  Serial.begin(9600);
pinMode(BUZZER,OUTPUT);
pinMode(LDR,INPUT);
pinMode(BUTTON,INPUT);
  lcd_1.begin(16, 2); // Set up the number of columns and rows on the LCD.

  // Print a message to the LCD.
  lcd_1.print("Safety Status:");
}

void loop()
{
  int LDR_STS = analogRead(LDR);
bool BUTTON_STS = digitalRead(BUTTON);
Serial.println(LDR_STS);
  { 
Serial.print("its safe");
Serial.println(LDR_STS);
 noTone(9); 
  lcd_1.setCursor(0, 1);
  lcd_1.print ("its safe");
  delay(1000);
  
}
if (LDR_STS <300)
{
 tone(9,2000);
delay(100);
tone(9,2000);
  delay(100);
  Serial.print("its unsafe");
  Serial.println(LDR_STS);
  lcd_1.setCursor(0, 1);
  lcd_1.print("its unsafe");
  delay(1000);
}
 if ( BUTTON_STS == HIGH)
{ 
noTone(9);
Serial.print("its safe");
Serial.println(LDR_STS);
   lcd_1.setCursor(0, 1);
  lcd_1.print("its safe");
  delay(1000);
 }
}