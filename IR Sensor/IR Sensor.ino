//Basic Arduino code for IR Sensor

int IR = 7;
int LED = 13;

void setup() {
  pinMode(IR, INPUT);       //IR: Input for LED
  pinMode(LED, OUTPUT);
  Serial.begin(9600);       //Start the serial monitor
}

void loop() {
  if(digitalRead(IR) == LOW){              /* Remember, it's opposite than PIR. */
    Serial.print("Object detected..");
    digitalWrite(LED, HIGH);
    delay(10);
  }
  else{
    Serial.print("No obstacle..");
    digitalWrite(LED, LOW);
    delay(10);    
  }  
}
