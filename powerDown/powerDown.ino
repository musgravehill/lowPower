#include "LowPower.h"

uint16_t countSleep_counter = 0;
uint16_t countSleep = 40; //how many times sleep of 8s

const int ledPin =  13;

void setup(){  
  pinMode(ledPin, OUTPUT); 
  Serial.begin(9600);

  digitalWrite(ledPin, 1);
  delay(50);
  digitalWrite(ledPin, 0);  
  delay(50);
  digitalWrite(ledPin, 1);
  delay(50);
  digitalWrite(ledPin, 0);  
  delay(50);
  digitalWrite(ledPin, 1);
  delay(50);
  digitalWrite(ledPin, 0);  
  delay(50);
}

void loop() {    
  powerDwn();  

  digitalWrite(ledPin, 1);
  delay(900);
  digitalWrite(ledPin, 0);
  
  Serial.println("Zzzzz...");
  delay(500); //time to send data, then CPU sleep
}

void powerDwn(){  
  while(countSleep_counter < countSleep){
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF); 
    //in theory: for controlling for BOD you should change FUSEs on Arduino. So, by default BOD always ON for Arduino. 
    //But when I set BOD_OFF in code (I have not changed fuses) => arduino current consume changed from 36mkA to 14mkA O_o
    countSleep_counter++;
  }   
  countSleep_counter = 0;
}
