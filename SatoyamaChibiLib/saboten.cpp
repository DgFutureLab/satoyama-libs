#include "saboten.h"
#include <utilsawesome.h>
#include <chibi.h>
#if ARDUINO >= 100
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif

#include <avr/sleep.h>


Board::Board(){
  this->sensors = new std::vector<BaseSensor*>(0);
}


void Board::register_sensor(BaseSensor *sensor){
  this->sensors->push_back(sensor);
}

void Board::read_sensors(unsigned char *buffer){
  int n_sensors = this->sensors->size();
  for(int i; i<n_sensors; i++){
    this->sensors->at(i)->read(buffer);
  }
}



Saboten::Saboten(unsigned int serial_baud_rate){
  this->rtc = new PCF2127(0, 0, 0, Saboten::RTC_CHIPSELECT_PIN);
  chibiCmdInit(serial_baud_rate);

  chibiInit();

  pinMode(Saboten::RTC_CHIPSELECT_PIN, OUTPUT);
  digitalWrite(Saboten::RTC_CHIPSELECT_PIN, HIGH);

  pinMode(Saboten::SD_CHIPSELECT_PIN, INPUT);
  digitalWrite(Saboten::SD_CHIPSELECT_PIN, HIGH);

  pinMode(Saboten::SD_DETECT_PIN, INPUT);
  digitalWrite(Saboten::SD_DETECT_PIN, LOW);

  pinMode(Saboten::HIGH_GAIN_MODE_PIN, OUTPUT);
  digitalWrite(Saboten::HIGH_GAIN_MODE_PIN, LOW);

  this->rtc->enableMinuteInterrupt();
  // this->rtc->enableSecondInterrupt();
  this->rtc->setInterruptToPulse();
  attachInterrupt(2, this->rtcInterrupt, FALLING);
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

void Saboten::read_battery_voltage(unsigned char *buffer){
  unsigned int vbat = analogRead(Saboten::BATTERY_VOLTAGE_PIN);
  double batt = ((vbat/1023.0) * Saboten::ADC_REFERENCE_VOLTAGE) * 2;
  Reading battery_voltage = {"vbat", batt, millis()};
  add_to_tx_buf_new(buffer, &battery_voltage);
}



void Saboten::rtcInterrupt(){
  detachInterrupt(2);
}

void Saboten::sleep_radio(){
	digitalWrite(Saboten::HIGH_GAIN_MODE_PIN, LOW);
    // set up chibi regs to turn off external P/A
    chibiRegWrite(0x4, 0x20);
}

void Saboten::wakeup_radio(){
	digitalWrite(Saboten::HIGH_GAIN_MODE_PIN, HIGH);
    // set up chibi regs to turn on external P/A
    chibiRegWrite(0x4, 0xA0);
}