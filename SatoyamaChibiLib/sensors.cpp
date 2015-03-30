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


  // // Read temperature
  // float temperature = DHT.temperature;  
  // Serial.println(temperature);
  // if (temperature > 0) {
  //   Reading temp = {"temperature", temperature, millis()};
  //   add_to_tx_buf((char*)tx_buf, &temp);
  // }

  // // Read humidity
  // float humidity = DHT.humidity;
  // if (humidity > 0) {
  //   Reading hum = {"humidity", humidity , millis()};
  //   add_to_tx_buf((char*)tx_buf, &hum);
  // }


void Sensors::read_Paralax28015REVC(unsigned char *buffer, int sonar_pin, NewPing sonar){
	/*
	Conmf
	*/
	float distance = sonar.ping() / US_ROUNDTRIP_CM; 

    if (distance > 0) {
      Reading dist = {"distance", distance, millis()};
      add_to_tx_buf_new(buffer, &dist);
    } else{
    	float hum = 0.1;
    	 Reading dist = {"distance", hum, millis()};
    	 add_to_tx_buf_new(buffer, &dist);
    }	
}

// std::vector<BaseSensor> 





#include <NewPing.h>

Paralax28015REVC_Sensor::Paralax28015REVC_Sensor(int sonar_pin){
	this->sonar = new NewPing(sonar_pin, sonar_pin, 200);
};

void Paralax28015REVC_Sensor::read(unsigned char *buffer){
	float distance = (float) sonar->ping() / US_ROUNDTRIP_CM; 
	Reading dist = {"distance", distance, millis()};
	add_to_tx_buf_new(buffer, &dist);
};



// class DHT11Sensor:public BaseSensor{

// 	PCF2127Sensor(){
// 		DHT temp(0, 0, 0, RTC_CHIPSELECT_PIN, &temp);
	

// 	}
// };

