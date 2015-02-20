#include "saboten.h"
#include <chibi.h>
#if ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

#include <avr/sleep.h>

/*
IN H FILE:

PCF2127(uint8_t devAddr, uint8_t mode, uint8_t i2c, uint8_t cs, uint8_t *temp);
void writeTime(uint8_t hour, uint8_t minutes, uint8_t seconds);


IN CPP FILE:

CONSTRUCTOR:

PCF2127::PCF2127(uint8_t devAddr, uint8_t mode, uint8_t i2c, uint8_t cs, uint8_t *temp)
{
   
}


void PCF2127::writeTime(uint8_t hours, uint8_t minutes, uint8_t seconds)
{
 
}

*/


Saboten::Saboten(){

}

void Saboten::sleep_mcu(){
  attachInterrupt(2, rtcInterrupt, FALLING);
  delay(100);

  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_radio(true);
  sleep_enable();        // setting up for sleep ...
  
  ADCSRA &= ~(1 << ADEN);    // Disable ADC
  sleep_mode();

  sleep_disable();
  sleep_radio(false);
}

void Saboten::sleep_radio(){
	digitalWrite(hgmPin, LOW);
    // set up chibi regs to turn off external P/A
    chibiRegWrite(0x4, 0x20);
}

void Saboten::wakeup_radio(){
	digitalWrite(hgmPin, HIGH);
    // set up chibi regs to turn on external P/A
    chibiRegWrite(0x4, 0xA0);
}