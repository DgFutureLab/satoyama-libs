#include "sensors.h"
#include <chibi.h>
#include <utilsawesome.h>

void read_vbat_new(unsigned char *buffer, int battery_voltage_pin){
  // float batt;
  unsigned int vbat = analogRead(battery_voltage_pin);
  double batt = ((vbat/1023.0) * ADCREFVOLTAGE) * 2;
  // Serial.print("BATT DOUBLE:");
  // Serial.println(batt);
  Reading battery_voltage = {"vbat", batt, millis()};
  // Serial.print("READING:");
  // Serial.println(battery_voltage.value);
  add_to_tx_buf_new(buffer, &battery_voltage);
}