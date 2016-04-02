#ifndef BB_PWM_H
#define BB_PWM_H

class PWM
{
	public:
		PWM(int sysFS, int hdr, int pin);
		void setPeriod(int period);
		void setDuty(int duty);
		void setRun(bool run);
		void setPolarity(bool polarity);
		~PWM();
	private:
		int getPeriod();
		int getDuty();
		bool getRun();
		bool getPolarity();
		int _sysFS;
		int _hdr;
		int _pin;
		int _period;
		int _duty;
		bool _run;
		bool _polarity;
		char _path[50];
};
#endif