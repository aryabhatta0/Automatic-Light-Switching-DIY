#include <LiquidCrystal.h>  //library for LCD commands

#define IR_f 13     //front IR Sensor
#define IR_b 12     //back IR Sensor
#define LED 8
 
int count=0;        //for calculating no. of people
int light_state=0;  //0 means light off; 1 light on

//variables for time calculation
unsigned long ledON;
unsigned long ledOFF;
unsigned long timeTaken;

LiquidCrystal lcd(1, 2, 4, 5, 6, 7);   //declare & initialize LCD

void setup() 
{
  lcd.begin(16, 2);     //declaring dimensions
  pinMode(IR_f, INPUT);
  pinMode(IR_b, INPUT);
  pinMode(LED, OUTPUT);
}

void enter_room(){
  count++;
  lcd.setCursor(0, 0);   //start of second line
  lcd.print(String("People In: ")+String(count)+String("   "));
}

void exit_room()
{
  count--;
  lcd.setCursor(0, 0);   //start of second line
  lcd.print(String("People In: ")+String(count)+String("   "));
}

void control_the_led()
{
  if(count>0){
    if(light_state==0){   //if light off
      digitalWrite(LED, HIGH);
      ledON = millis();    //record the starting time
      light_state=1;
    }
    
    lcd.setCursor(0, 1);
    lcd.print("Light: ON       ");    //extra space at last, to overwrite anything underneath
  }
  else{
    if(light_state==1){
      digitalWrite(LED, LOW);
      ledOFF = millis();     //record the ending time
      light_state=0;

      lcd.setCursor(0, 1);
      lcd.print("Turning bulb off..");

      timeTaken = (ledOFF-ledON)/1000;  //in sec
      lcd.setCursor(0, 1);
      lcd.print(String("Time: ") + String(timeTaken) + String("s") +String("         "));  
      delay(1000);    
    }
    
    else{
      lcd.setCursor(0, 1);
      lcd.print("Light: OFF      ");
    }
  }
}

void loop() 
{                                    /* There must be some overlaping reason b/w the 2 sensors. */
  if(digitalRead(IR_f)==LOW){
    while(1)
    {
      if(digitalRead(IR_b)==LOW){
        enter_room();
        delay(1000);
        break;
      }
      else if(digitalRead(IR_f)==HIGH){
        //person returns from the gate
        break;
      }
    }
  }

  if(digitalRead(IR_b)==LOW){
    while(1)
    {
      if(digitalRead(IR_f)==LOW){
        exit_room();
        delay(1000);
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
