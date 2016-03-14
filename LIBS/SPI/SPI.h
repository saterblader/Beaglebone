#ifndef BB_SPI_H
#define BB_SPI_H

#include<string>
#include<stdint.h>

#define SPI_PATH "/dev/spidev"

class SPIDevice
{
public:
	/// The SPI Modes
	enum SPIMODE{
		MODE0 = 0,   //!< Low at idle, capture on rising clock edge
		MODE1 = 1,   //!< Low at idle, capture on falling clock edge
		MODE2 = 2,   //!< High at idle, capture on falling clock edge
		MODE3 = 3    //!< High at idle, capture on rising clock edge
	};

private:
	std::string filename;
public:
	SPIDevice(unsigned int bus, unsigned int device);
	int open();
	unsigned char readRegister(unsigned int registerAddress);
	unsigned char* readRegisters(unsigned int number, unsigned int fromAddress=0);
	int writeRegister(unsigned int registerAddress, unsigned char value);
	void debugDumpRegisters(unsigned int number = 0xff);
	int write(unsigned char value);
	int write(unsigned char value[], int length);
	int setSpeed(uint32_t speed);
	int setMode(SPIDevice::SPIMODE mode);
	int setBitsPerWord(uint8_t bits);
	void close();
	int transfer(unsigned char read[], unsigned char write[], int length);
	~SPIDevice();
private:
	SPIMODE mode;
	uint8_t bits;
	uint32_t speed;
	uint16_t delay;
	unsigned int _bus;
	unsigned int _device;
	int file;
};
#endif
