/*
 This is a Exemple for a simple temperature controler

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int lcd_bl = 8;
const int lm35 = A0;
const int triac_sinal = 12;

float temperature;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
 
  pinMode(lcd_bl, OUTPUT);
  pinMode(triac_sinal, OUTPUT);
  
  digitalWrite(lcd_bl, HIGH);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  digitalWrite(lcd_bl, HIGH);
  
  
  temperature = (float(analogRead(lm35))*4.83/(1023))*100;
  
  lcd.setCursor(0, 0);
  // print the number of seconds since reset:
   // Print a message to the LCD.
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print("C");


  
  if(temperature <= 27.8){
    digitalWrite(triac_sinal, HIGH);
      
    }else{
      digitalWrite(triac_sinal, LOW);
      };

  delay(1000);
  
  
}
