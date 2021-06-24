//Things to add: Serial Monitor?

#include <LiquidCrystal.h>   //library for LCD commands

#define IR_f 13     //front IR Sensor
#define IR_b 12     //back IR Sensor
#define LED 8
 
int count=0;   

LiquidCrystal lcd(1, 2, 4, 5, 6, 7);   //declare & initialize LCD

void setup()
{
  lcd.begin(16, 2);     //dimensions of LCD
 
  pinMode(IR_f, INPUT);
  pinMode(IR_b, INPUT);
  pinMode(LED, OUTPUT);
}

void enter_room(){
  count++;
  lcd.setCursor(0, 1);   //start of second line
  lcd.print(String("People in room:")+String(count));
}

void exit_room(){
  count--;
  lcd.setCursor(0, 1);   //start of second line
  lcd.print(String("People in room:")+String(count));
}

void control_the_led()
{  
  if(count>0){
    digitalWrite(LED, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Light: ON       ");    //extra space at last, to overwrite anything underneath
  }
  else{
    digitalWrite(LED, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Light: OFF      ");
  }
}

void loop() 
{                                    /*There must be some overlaping reason b/w the 2 sensors.*/
  if(digitalRead(IR_f)==LOW){
    while(1)
    {
      if(digitalRead(IR_b)==LOW){
        enter_room();
        break;
      }
      else if(digitalRead(IR_f)==HIGH){
        //person returns from the gate
        break;
      }
    }
  }

  else if(digitalRead(IR_b)==LOW){
    while(1)
    {
      if(digitalRead(IR_f)==LOW){
        exit_room();
        break;
      }
      else if(digitalRead(IR_b)==HIGH){
        //person returns from the gate
        break;
      }
    }
  }

  control_the_led();   
}
