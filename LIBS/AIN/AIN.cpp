#include "AIN.h"
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>

AIN::AIN(int sysFS, int pin)
{
	if (pin >=0 || pin <7)
	{
		_pin=pin;
		_sysFS=sysFS
		sprintf(_path,"/sys/devices/ocp.3/helper.%d/AIN%d",_sysFS,_pin);
	}
	else
	{
		std::cout<< "Invalid Pin\n";
		exit(1);
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
	_sysFS = -1;
	_path[0] = '\0';
}

#ifdef TEST_AIN
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std:: cout<<"invalid number of arguments\n";
		return 0;
	}
	int sysFS= std::stoi (argv[1],nullptr,10);
	AIN AIN1(sysFS,1);
	std::cout<<"The current value of AIN1 is "<<AIN1.Get()<<std::endl;
	return 0;
}
#endif