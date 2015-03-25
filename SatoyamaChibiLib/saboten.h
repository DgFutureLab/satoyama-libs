/*
IN H FILE:

PCF2127(uint8_t devAddr, uint8_t mode, uint8_t i2c, uint8_t cs, uint8_t *temp);
void writeTime(uint8_t hour, uint8_t minutes, uint8_t seconds);


IN CPP FILE:

CONSTRUCTOR:

PCF2127::PCF2127(uint8_t devAddr, uint8_t mode, uint8_t i2c, uint8_t cs, uint8_t *temp)
{
   
}


void PCF2127::writeTime(uint8_t hours, uint8_t minutes, uint8_t seconds)
{
 
}

*/

// void rtcInterrupt();


class Saboten{
	public:

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
		void hum();
		static void rtcInterrupt();
};