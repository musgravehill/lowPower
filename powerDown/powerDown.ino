#include "LowPower.h"

//if 10,20,60 => 20=10*2  60=10*6  60=20*3 collisions
//Prime number => it minimizes collisions
uint16_t counterSleep_x7 = 0; 
uint16_t counterSleep_x17 = 0; 
uint16_t counterSleep_x31 = 0; 
unsigned long t = 0;

const int ledPin =  13;

void setup(){  
  delay(1000);
  pinMode(ledPin, OUTPUT); 
  Serial.begin(9600);  
  delay(1000);
}

void loop() {  
  LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF);
  counterSleep_x7++;
  counterSleep_x17++;
  counterSleep_x31++;

  if(counterSleep_x7 >= 3){
    counterSleep_x7 = 0;
    task_x7();     
  } 

  if(counterSleep_x17 >= 5){
    counterSleep_x17 = 0;
    task_x17();     
  } 

  if(counterSleep_x31 >= 7){
    counterSleep_x31 = 0;
    task_x31();     
  }  


}

void task_x7(){
  digitalWrite(ledPin, 1);
  delay(100);
  digitalWrite(ledPin, 0); 
}

void task_x17(){
  digitalWrite(ledPin, 1);
  delay(100);
  digitalWrite(ledPin, 0);
  delay(100);
  digitalWrite(ledPin, 1);
  delay(100);
  digitalWrite(ledPin, 0);  
}

void task_x31(){
  digitalWrite(ledPin, 1);
   delay(100);
   digitalWrite(ledPin, 0);
   delay(100);
   digitalWrite(ledPin, 1);
   delay(100);
   digitalWrite(ledPin, 0);
   delay(100);
   digitalWrite(ledPin, 1);
   delay(100);
   digitalWrite(ledPin, 0);
  
  Serial.println("Zzz..");
  delay(500); //time to send data, then CPU sleep
}




