#include <vector>
#include <sensors.h>


class Board{
	private:
		std::vector<BaseSensor*> *sensors; 

	public:
		Board();
		void register_sensor(BaseSensor *sensor);
		void read_sensors(unsigned char *buffer);
		// virtual void read_diagnostics(unsigned char *buffer);
		// virtual void read_values(unsigned char *buffer);


};


class Saboten:public Board{
	// private:
		// void read_battery_voltage(unsigned char *buffer);

	public:
		static constexpr float ADC_REFERENCE_VOLTAGE = 3.3;
		static constexpr int BATTERY_VOLTAGE_PIN = 31;
		static const int hgmPin = 14;
		static const int sdCsPin = 15;
		static const int rtcCsPin = 28; 
		static const int ledPin = 18;
		static const int sdDetectPin = 19;
		static const int vbatPin = 31;
		static const int vsolPin = 29;
		Saboten();
		void sleep_mcu();
		void sleep_radio();
		void wakeup_radio();
		static void rtcInterrupt();
		// void read_diagnostics(unsigned char *buffer);
};