#include <vector>
#include "sensors.h"
#include <chibi.h>
#include <utilsawesome.h>


// #include <saboten.h>



void Sensors::read_battery_voltage(unsigned char *buffer, int battery_voltage_pin, float reference_voltage){
  unsigned int vbat = analogRead(battery_voltage_pin);
  double batt = ((vbat/1023.0) * reference_voltage) * 2;
  Reading battery_voltage = {"vbat", batt, millis()};
  add_to_tx_buf_new(buffer, &battery_voltage);
}


// void read_Paralax28015REVC(unsigned char *buffer, int sonar_pin, NewPing sonar){
// 	/*
// 	Conmf
// 	*/
// 	float distance = sonar.ping() / US_ROUNDTRIP_CM; 

//     if (distance > 0) {
//       Reading dist = {"distance", distance, millis()};
//       add_to_tx_buf_new((char*)tx_buf, &dist);
//     }	
// }

// std::vector<BaseSensor> 





#include <NewPing.h>

PCF2127Sensor::PCF2127Sensor(int sonar_pin){
	this->sonar = new NewPing(sonar_pin, sonar_pin, 200);
};

void PCF2127Sensor::read(unsigned char *buffer){
	float distance = (float) sonar->ping() / US_ROUNDTRIP_CM; 
	Reading dist = {"distance", distance, millis()};
	add_to_tx_buf_new(buffer, &dist);
}



// class DHT11Sensor:public BaseSensor{

// 	PCF2127Sensor(){
// 		DHT temp(0, 0, 0, RTC_CHIPSELECT_PIN, &temp);
	

// 	}
// };

