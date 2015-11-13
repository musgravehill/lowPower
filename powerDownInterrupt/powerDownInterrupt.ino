/*
About Interrupt Service Routines
 
 ISRs are special kinds of functions that have some unique limitations most other functions do not have. 
 An ISR cannot have any parameters, and they shouldn't return anything.
 
 Generally, an ISR should be as short and fast as possible. 
 If your sketch uses multiple ISRs, only one can run at a time, 
 other interrupts will be executed after the current one finishes in an order that depends on the priority they have. 
 millis() relies on interrupts to count, so it will never increment inside an ISR. 
 Since delay() requires interrupts to work, it will not work if called inside an ISR. 
 micros() works initially, but will start behaving erratically after 1-2 ms. 
 delayMicroseconds() does not use any counter, so it will work as normal.
 
 Typically global variables are used to pass data between an ISR and the main program. 
 To make sure variables shared between an ISR and the main program are updated correctly, declare them as volatile.
 */

/*
     noInterrupts();
 // critical, time-sensitive code here
 interrupts();
 // other code here
 */
/*
   in newest ArduIDE  attachInterrupt(digitalPinToInterrupt(pin), ISR, mode);
 */

#include "LowPower.h"

volatile boolean isAllowSleep = true; //volatile=>interrupt may change it
volatile boolean isWakeupInitial = false; //is just woke up? //volatile=>interrupt may change it
unsigned long wakeupTimeInitial = 0;
const uint8_t ledPin =  13;

void setup(){  
  delay(1000);
  pinMode(ledPin, OUTPUT); 
  attachInterrupt(0, ISR_wakeup, RISING);  //d2 on 328
  delay(1000);    
}

void loop() {  
  if(isAllowSleep){   
    digitalWrite(ledPin, 1);
    delay(15);
    digitalWrite(ledPin, 0); 
    delay(15); 
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
  }
  else{       
    if(isWakeupInitial){
      delay(500); //deBounce button! Else interrupt occurs and occurs. //TODO add RC to d2
      isWakeupInitial = false;
      wakeupTimeInitial = millis();
    }
    //wakeup 4 seconds, then sleep again
    if ((unsigned long)(millis() - wakeupTimeInitial) > 4000 ){      
      isAllowSleep = true;             
    }
    else{
      wakeupActions();
    }
  }  
}

void ISR_wakeup(){    
  isAllowSleep = false;
  isWakeupInitial = true;  
}

void wakeupActions(){
  digitalWrite(ledPin, 1);
  delay(20);
  digitalWrite(ledPin, 0); 
  delay(20);
}











