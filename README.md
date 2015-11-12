#lowPower AVR
##Who consumes current?
0. LED_POWER consumes *mA
1. LDO 
3. USB-SERIAL IC
##INFO 
http://www.rocketscream.com/blog/2011/07/04/lightweight-low-power-arduino-library/
https://github.com/rocketscream/Low-Power
Option to disable Brownout Detector (BOD) module to further reduce current consumption by approximately 17 µA. BOD module cannot be disabled through software in idle and ADC noise reduction mode. It can only be disabled through fuse setting in these 2 modes. - See more at: http://www.rocketscream.com/blog/2011/07/04/lightweight-low-power-arduino-library/#sthash.QAsdpEKN.dpuf