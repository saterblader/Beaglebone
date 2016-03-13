#include "AIN.h"
#include <fstream>
#include <string>
#include <iostream>

AIN::AIN(int pin)
{
	if (pin >=0 || pin <7)
	{
		_pin=pin;
		sprintf(_path,"/sys/devices/ocp.3/helper.12/AIN%d",_pin);
	}
}

int AIN::Get()
{
	int value=0;
  	std::fstream in(_path,std::fstream::in);
  	if (!in.good())
  	{
    	std::cout << "can't open file " << _path << "\n";
    	return -1;
  	}
  	in>>value;
  	in.close();
	return value;
}

AIN::~AIN()
{
	_pin = -1;
	_path="\0";
}

#ifdef TEST_AIN
int main()
{
	AIN AIN1(1);
	std::cout<<"The current value of AIN1 is "<<AIN1.Get()<<std::endl;
	return 0;
}
#endif