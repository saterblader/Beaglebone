#ifndef BB_AIN_H
#define BB_AIN_H


class AIN
{
	public:
		AIN(int sysFS, int pin);
		int Get();
		~AIN();
	private:
		int _pin;
		int _sysFS;
		char _path[50];
};
#endif