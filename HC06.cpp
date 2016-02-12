#include "hc06.h"

HC06::HC06(byte rx, byte tx)
:
	_btSerial(rx, tx)
{
	_btSerial.begin(9600);
	delay(2000);
}

bool HC06::isConnected()
{
	_btSerial.print("AT");
	delay(2000);

	//Response TODO
	return true;
}

void HC06::setName(char* name)
{
	_btSerial.print("AT+NAME");
	_btSerial.print(name);
	delay(2000);
}

void HC06::setPassword(int code)
{
	_btSerial.print("AT+PIN");
	_btSerial.print(code);
	delay(2000);
}

void HC06::setBaudrate(int baudrate)
{
	switch(baudrate)
	{
		case 1200:
			_btSerial.print("AT+BAUD1");
			break;
		case 2400:
			_btSerial.print("AT+BAUD2");
			break;
		case 4800:
			_btSerial.print("AT+BAUD3");
			break;
		case 9600:
			_btSerial.print("AT+BAUD4");
			break;
		case 19200:
			_btSerial.print("AT+BAUD5");
			break;
		case 38400:
			_btSerial.print("AT+BAUD6");
			break;
		case 57600:
			_btSerial.print("AT+BAUD7");
			break;
		case 115200:
			_btSerial.print("AT+BAUD8");
			break;
		default:
			_btSerial.print("AT+BAUD4");
			break;
	}

	_btSerial.begin(baudrate);
	delay(2000);
}

void HC06::reset()
{
	_btSerial.print("AT+RESET");
	delay(2000);
}

void HC06::hardReset()
{
	_btSerial.print("AT+ORGL");
	delay(2000);
}


byte HC06::available()
{
	return _btSerial.available();
}

byte HC06::read()
{
	return _btSerial.read();
}
