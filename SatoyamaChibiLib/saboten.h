#include <vector>
#include <sensors.h>
#include <pcf2127.h>
#include <string>
// #include <interfaces.h>


class NetworkInterface{
	public:
		void sleep_interface();
};

class Board{
	private:
		std::vector<BaseSensor*> *sensors; 
		std::vector<NetworkInterface*> *network_interfaces; 
	public:
		Board();
		void register_sensor(BaseSensor *sensor);
		void read_sensors(unsigned char *buffer);
		virtual void read_board_diagnostics(unsigned char *buffer) = 0;
		

		void register_network_interface(NetworkInterface *interface);
		void send_on_interface(NetworkInterface *interface, unsigned char *buffer);
		void recv_on_interface(NetworkInterface *interface, unsigned char *buffer);
		
};

class Chibi:public Board{
	public:
		Chibi(unsigned char serial_baud_rate);

};


class Saboten:public Board{
	private:
		static const int BATTERY_VOLTAGE_PIN = 31;
		static const float ADC_REFERENCE_VOLTAGE = 3.3;

		void read_battery_voltage(unsigned char *buffer);


	public:
		PCF2127 *rtc;
		
		
		static const int HIGH_GAIN_MODE_PIN = 14;
		static const int SD_CHIPSELECT_PIN = 15;
		static const int SD_DETECT_PIN = 19;

		static const int RTC_CHIPSELECT_PIN = 28; 
		static const int ledPin = 18;
		static const int vbatPin = 31;
		static const int vsolPin = 29;
		static void rtcInterrupt();

		Saboten(unsigned int serial_baud_rate);
		char* timestamp();
		void set_datetime(int year, int month, int day, int hour, int minute, int second);

		/*
		Functions that implement Board interface
		*/
		void read_board_diagnostics(unsigned char *buffer);
		
		/*
		Saboten specific functions
		*/

		void sleep_mcu();
		void sleep_radio();
		void wakeup_radio();

};

