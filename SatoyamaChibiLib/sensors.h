#include <NewPing.h>

class BaseSensor{
	public: 
		virtual void read(unsigned char *buffer) = 0;
};

class Paralax28015REVC_Sensor:public BaseSensor{
	private: 
		NewPing *sonar; // Sonar is a pointer that points to a NewPing instance
	
	public:
		Paralax28015REVC_Sensor(int sonar_pin);
		void read(unsigned char *buffer);
};

#include "DHT.h"
// #define DHTTYPE DHT11   // Type of DHT sensor, in our case we are using DHT11
// #define DHT11_PIN A0    // Pin where the DHT11 is connected
// dht DHT;

class DHT_V12_Sensor:public BaseSensor{
	private:
		dht *sensor;
	public:
		DHT_V12_Sensor(unsigned char signal_pin);
		void read(unsigned char *buffer);
};


class BatteryVoltage_Diagnostic:public BaseSensor{
	public:
		BatteryVoltage_Diagnostic(int mcu_pin);
		void read(unsigned char *buffer);
};


