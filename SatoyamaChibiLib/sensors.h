
class Sensors{
	/*
	This class does not really represent a sensor, but it's
	just for adding some namespacing to the programs running
	in the microcontroller.
	*/
	public: 
		static void read_battery_voltage(unsigned char *buffer, int battery_voltage_pin, float reference_voltage);
};