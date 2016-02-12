#ifndef INCLUDED_HC06_H
#define INCLUDED_HC06_H

#include <Arduino.h>
#include <SoftwareSerial.h>

class HC06
{
	public: 
		HC06(byte rx, byte tx);
		void setName(char* name);
		void setPassword(int code);
		void setBaudrate(int baudrate);
		bool isConnected();
		void reset();
		void hardReset();
		byte available();
		byte read();
	private:
		SoftwareSerial _btSerial;	

};
#endif
