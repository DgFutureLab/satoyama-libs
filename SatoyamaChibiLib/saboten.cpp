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
 
}

void Saboten::sleep_radio(){

}

void Saboten::wakeup_radio(){
	
}