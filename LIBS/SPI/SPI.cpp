#include "SPI.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>
using namespace std;

#define HEX(x) setw(2) << setfill('0') << hex << (int)(x)  //!< Macro for filling in leading 0 on HEX outputs

SPIDevice::SPIDevice(unsigned int bus, unsigned int device)
{
	this->_bus=bus;
	this->_device=device;
	stringstream s;
	s << SPI_PATH << _bus << "." << _device;
	this->filename = string(s.str());
	this->mode = SPIDevice::MODE3;
	this->bits = 8;
	this->speed = 500000;
	this->delay = 0;
	this->open();
}

int SPIDevice::open(){
	if ((this->file = ::open(filename.c_str(), O_RDWR))<0){
		perror("SPI: Can't open device.");
		return -1;
	}
	if (this->setMode(this->mode)==-1) return -1;
	if (this->setSpeed(this->speed)==-1) return -1;
	if (this->setBitsPerWord(this->bits)==-1) return -1;
	return 0;
}

int SPIDevice::transfer(unsigned char send[], unsigned char receive[], int length){
	struct spi_ioc_transfer	transfer;
	memset(&transfer,0,sizeof(transfer));
	transfer.tx_buf = (unsigned long) send;
	transfer.rx_buf = (unsigned long) receive;
	transfer.len = length;
	transfer.speed_hz = this->speed;
	transfer.bits_per_word = this->bits;
	transfer.delay_usecs = this->delay;
	int status = ioctl(this->file, SPI_IOC_MESSAGE(1), &transfer);
	if (status < 0) {
		perror("SPI: SPI_IOC_MESSAGE Failed");
		return -1;
	}
	return status;
}

unsigned char SPIDevice::readRegister(unsigned int registerAddress){
	unsigned char send[2], receive[2];
	memset(send, 0, sizeof send);
	memset(receive, 0, sizeof receive);
	send[0] = (unsigned char) (0x80 | registerAddress);
	this->transfer(send, receive, 2);
	return receive[1];
}

unsigned char* SPIDevice::readRegisters(unsigned int number, unsigned int fromAddress){
	unsigned char* data = new unsigned char[number];
	unsigned char send[number+1], receive[number+1];
	memset(send, 0, sizeof send);
	send[0] =  (unsigned char) (0x80 | 0x40 | fromAddress);
	this->transfer(send, receive, number+1);
	memcpy(data, receive+1, number);
	return data;
}

int SPIDevice::write(unsigned char value){
	unsigned char null_return = 0x00;
	//printf("[%02x]", value);
	this->transfer(&value, &null_return, 1);
	return 0;
}

int SPIDevice::write(unsigned char value[], int length){
	unsigned char null_return = 0x00;
	this->transfer(value, &null_return, length);
	return 0;
}

int SPIDevice::writeRegister(unsigned int registerAddress, unsigned char value){
	unsigned char send[2], receive[2];
	memset(receive, 0, sizeof receive);
	send[0] = (unsigned char) registerAddress;
	send[1] = value;
	this->transfer(send, receive, 2);
	return 0;
}

void SPIDevice::debugDumpRegisters(unsigned int number){
	cout << "SPI Mode: " << this->mode << endl;
	cout << "Bits per word: " << (int)this->bits << endl;
	cout << "Max speed: " << this->speed << endl;
	cout << "Dumping Registers for Debug Purposes:" << endl;
	unsigned char *registers = this->readRegisters(number);
	for(int i=0; i<(int)number; i++){
		cout << HEX(*(registers+i)) << " ";
		if (i%16==15) cout << endl;
	}
	cout << dec;
}

int SPIDevice::setSpeed(uint32_t speed){
	this->speed = speed;
	if (ioctl(this->file, SPI_IOC_WR_MAX_SPEED_HZ, &this->speed)==-1){
		perror("SPI: Can't set max speed HZ");
		return -1;
	}
	if (ioctl(this->file, SPI_IOC_RD_MAX_SPEED_HZ, &this->speed)==-1){
		perror("SPI: Can't get max speed HZ.");
		return -1;
	}
	return 0;
}

int SPIDevice::setMode(SPIDevice::SPIMODE mode){
	this->mode = mode;
	if (ioctl(this->file, SPI_IOC_WR_MODE, &this->mode)==-1){
		perror("SPI: Can't set SPI mode.");
		return -1;
	}
	if (ioctl(this->file, SPI_IOC_RD_MODE, &this->mode)==-1){
		perror("SPI: Can't get SPI mode.");
		return -1;
	}
	return 0;
}

int SPIDevice::setBitsPerWord(uint8_t bits){
	this->bits = bits;
	if (ioctl(this->file, SPI_IOC_WR_BITS_PER_WORD, &this->bits)==-1){
		perror("SPI: Can't set bits per word.");
		return -1;
	}
	if (ioctl(this->file, SPI_IOC_RD_BITS_PER_WORD, &this->bits)==-1){
		perror("SPI: Can't get bits per word.");
		return -1;
	}
	return 0;
}

void SPIDevice::close(){
	::close(this->file);
	this->file = -1;
}

SPIDevice::~SPIDevice() {
	this->close();
}
