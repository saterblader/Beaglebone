#include "PWM.h"
#include <fstream>
#include <iostream>
#include <cstring>

PWM::PWM(int sysFS, int hdr, int pin)
{
	_sysFS=sysFS;
	_hdr=hdr;
	_pin=pin;
	sprintf(_path,"/sys/devices/ocp.3/pwm_test_P%d_%d.%d",_hdr,_pin,_sysFS);
	_period=getPeriod();
	_duty=getDuty();
	_run=getRun();
	_polarity=getPolarity();
}

void PWM::setPeriod(int period)
{
    if (_period!=period)
    {
    	char path[50];
		strcpy (path,_path);
		strcat (path,"/period");
		std::fstream in(path,std::fstream::out);
		if (!in.good())
		{
				std::cout << "can't open file " << path << "\n";
		}
		in<<period;
		in.close();
		_period=period;
  	}
}

void PWM::setDuty(int duty)
{
    if (_duty!=duty)
    {
    	char path[50];
		strcpy (path,_path);
		strcat (path,"/duty");
		std::fstream in(path,std::fstream::out);
		if (!in.good())
		{
				std::cout << "can't open file " << path << "\n";
		}
		in<<duty;
		in.close();
		_duty=duty;
  	}
}
void PWM::setRun(bool run)
{
	if (_run!=run)
	{
		char path[50];
		strcpy (path,_path);
		strcat (path,"/run");
		std::fstream in(path,std::fstream::out);
		if (!in.good())
		{
				std::cout << "can't open file " << path << "\n";
		}
		in<<run;
		in.close();
		_run=run;
  	}
}

void PWM::setPolarity(bool polarity)
{
	if (_polarity!=polarity)
	{
		char path[50];
		strcpy (path,_path);
		strcat (path,"/polarity");
		std::fstream in(path,std::fstream::out);
		if (!in.good())
		{
				std::cout << "can't open file " << path << "\n";
		}
		in<<polarity;
		in.close();
		_polarity=polarity;
	}
}

PWM::~PWM()
{
	setRun(1);
	setDuty(0);
	setPolarity(1);
	setPeriod(500000);
	_period=0;
	_duty=0;
	_run=0;
	_polarity=0;
	_path[0]='\0';
}

int PWM::getPeriod()
{
	char path[50];
    strcpy (path,_path);
  	strcat (path,"/period");
  	std::fstream in(path,std::fstream::in);
  	if (!in.good())
  	{
    	std::cout << "can't open file " << path << "\n";
    	return -1;
  	}
  	in>>_period;
  	in.close();
	return _period;
}

int PWM::getDuty()
{
	char path[50];
    strcpy (path,_path);
  	strcat (path,"/duty");
  	std::fstream in(path,std::fstream::in);
  	if (!in.good())
  	{
    	std::cout << "can't open file " << path << "\n";
    	return -1;
  	}
  	in>>_duty;
  	in.close();
	return _duty;
}

bool PWM::getRun()
{
	char path[50];
    strcpy (path,_path);
  	strcat (path,"/run");
  	std::fstream in(path,std::fstream::in);
  	if (!in.good())
  	{
    	std::cout << "can't open file " << path << "\n";
    	return -1;
  	}
  	in>>_run;
  	in.close();
	return _run;
}

bool PWM::getPolarity()
{
	char path[50];
    strcpy (path,_path);
  	strcat (path,"/polarity");
  	std::fstream in(path,std::fstream::in);
  	if (!in.good())
  	{
    	std::cout << "can't open file " << path << "\n";
    	return -1;
  	}
  	in>>_polarity;
  	in.close();
	return _polarity;
}

#ifdef TEST_PWM
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std:: cout<<"invalid number of arguments\n";
		return 0;
	}
	int sysFS= std::stoi (argv[1],nullptr,10);
	PWM PWMP8_13(sysFS,8,13);
	PWMP8_13.setRun(1);
	PWMP8_13.setDuty(300000);
	char quit[2]={'a','\n'};
	while(1)
	{
		quit[0]=getchar();
		getchar();
		if (quit[0]=='Q' || quit[0]== 'q')
			break;
	}
	return 0;
}
#endif