#include <vector>
#include <sensors.h>
#include <pcf2127.h>


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
	private:
		void read_battery_voltage(unsigned char *buffer);

	public:
		PCF2127 *rtc;
		static constexpr float ADC_REFERENCE_VOLTAGE = 3.3;
		static constexpr int BATTERY_VOLTAGE_PIN = 31;
		static const int HIGH_GAIN_MODE_PIN = 14;
		static const int SD_CHIPSELECT_PIN = 15;
		static const int SD_DETECT_PIN = 19;

		static const int RTC_CHIPSELECT_PIN = 28; 
		static const int ledPin = 18;
		static const int vbatPin = 31;
		static const int vsolPin = 29;
		Saboten();
		void sleep_mcu();
		void sleep_radio();
		void wakeup_radio();
		static void rtcInterrupt();
		// void read_diagnostics(unsigned char *buffer);
};