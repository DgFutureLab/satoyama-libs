#include "saboten.h"
#include <chibi.h>
#if ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

#include <avr/sleep.h>



Saboten::Saboten(){
}

void Saboten::sleep_mcu(){
  attachInterrupt(2, rtcInterrupt, FALLING);
  delay(100);

  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_radio();
  sleep_enable();        // setting up for sleep ...
  
  ADCSRA &= ~(1 << ADEN);    // Disable ADC
  sleep_mode();

  sleep_disable();
  wakeup_radio();
  ADCSRA |= (1 << ADEN); // Enable ADC
}

void Saboten::rtcInterrupt(){
  detachInterrupt(2);
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