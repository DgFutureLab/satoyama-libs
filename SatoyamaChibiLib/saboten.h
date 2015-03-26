class Saboten{
	public:
		static const float ADCREFVOLTAGE = 3.3;
		static const int BATTERY_VOLTAGE_PIN = 31;
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
		void read_sensors();
		// void registerSensor(char *sensor_name, void (*func)(unsigned int buffer));
		static void rtcInterrupt();
};