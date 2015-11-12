#include "LowPower.h"

uint16_t counterSleep_x10 = 0;
uint16_t counterSleep_x20 = 0;
uint16_t counterSleep_x30 = 0;

const int ledPin =  13;

void setup(){  
  delay(1000);
  pinMode(ledPin, OUTPUT); 
  Serial.begin(9600);  
  delay(1000);
}

void loop() {  
  LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF);
  if(counterSleep_x10<10){
    counterSleep_x10++;
    task_x10();
  }
  else{
    counterSleep_x10 = 0;
  }  

  if(counterSleep_x20<20){
    counterSleep_x20++;
    task_x20();
  }
  else{
    counterSleep_x20 = 0;
  }

  if(counterSleep_x30<30){
    counterSleep_x30++;
    task_x30();
  }
  else{
    counterSleep_x30 = 0;
  }    
}

void task_x10(){
  digitalWrite(ledPin, 1);
  delay(200);
  digitalWrite(ledPin, 0); 
}

void task_x20(){
  digitalWrite(ledPin, 1);
  delay(200);
  digitalWrite(ledPin, 0);
  delay(200);
  digitalWrite(ledPin, 1);
  delay(200);
  digitalWrite(ledPin, 0);  


}

void task_x30(){
  digitalWrite(ledPin, 1);
  delay(200);
  digitalWrite(ledPin, 0);
  delay(200);
  digitalWrite(ledPin, 1);
  delay(200);
  digitalWrite(ledPin, 0);
  delay(200);
  digitalWrite(ledPin, 1);
  delay(200);
  digitalWrite(ledPin, 0);

  Serial.println("Zzzzz...");
  delay(500); //time to send data, then CPU sleep
}
