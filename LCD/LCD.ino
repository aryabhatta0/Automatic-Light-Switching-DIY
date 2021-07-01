//Basic code for LCD 

#include <LiquidCrystal.h>

int i = 0;
LiquidCrystal lcd(1, 2, 4, 5, 6, 7);    //declare & initialize LCD  *Pins are as in the model*

void setup() {
  lcd.begin(16, 2);   //(16,2) is the dimension of LCD.
}

void loop() {
  lcd.setCursor(0,0);     //Make cursor poin to from where you wanna print things.      
  lcd.print("Testing 1");
  delay(1000);
  
  lcd.setCursor(0,0);   
  lcd.print("Testing 2");
  delay(1000);
  
  lcd.setCursor(0,0);
  lcd.print("Testing 3");
  lcd.setCursor(0,1);
  delay(1000);
  
  i++;  
  lcd.print(String("Iterations:")+String(i));
}
