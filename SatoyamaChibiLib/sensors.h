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



class Sensors{
	/*
	This class does not really represent a sensor, but it's
	just for adding some namespacing to the programs running
	in the microcontroller.
	*/
	
	public: 
		static void read_battery_voltage(unsigned char *buffer, int battery_voltage_pin, float reference_voltage);
		static void read_Paralax28015REVC(unsigned char *buffer, int sonar_pin, NewPing sonar);
}; 