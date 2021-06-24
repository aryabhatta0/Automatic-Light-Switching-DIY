//Things to add: LCD & Serial Monitor.

#define IR_f 13     //front IR Sensor
#define IR_b 12     //back IR Sensor
#define LED 8
 
int count=0;   

void setup() {

  ///Initialize the LCD.
  
  pinMode(IR_f, INPUT);
  pinMode(IR_b, INPUT);
  pinMode(LED, OUTPUT);
}

void enter_room(){
  count++;
  ///print things on lcd.
}

void exit_room(){
  count--;
  ///print things on lcd.
}

void control_the_led(){
  
  if(count>0){
    digitalWrite(LED, HIGH);
    ///print things on lcd.
  }
  else{
    digitalWrite(LED, LOW);
    ///print things on lcd.
  }
}

void loop() {
                                    /*There must be some overlaping reason b/w the 2 sensors.*/
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
