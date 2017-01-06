Beaglebone SPI Class
=====================
By Philip D. Geramian
---------------------
### pdgerami@syr.edu

The following code provides a Beaglebone SPI Class.

Release 1.1  
January 6th, 2017

Based on Code Written by Derek Molloy

Public Functions:
-----------------
###SPIDevice(unsigned int bus, unsigned int device)
The constructor for the SPIDevice that sets up and opens the SPI connection.
The destructor will close the SPI file connection.  
@param bus The SPI bus number X (first digit after spidevX.Y)  
@param device The device on the bus Y (second digit after spidevX.Y)

###int open()
This method opens the file connection to the SPI device.  
@return 0 on a successful open of the file

###unsigned char readRegister(unsigned int registerAddress)
A method to read a single register at the SPI address  
@param registerAddress the address of the register from the device datasheet  
@return the character that is returned from the address

###unsigned char* readRegisters(unsigned int number, unsigned int fromAddress=0)
A method to read a number of registers as a data array  
@param number the number of registers to read  
@param fromAddress the starting address of the block of data  
@return the data array that is returned (memory allocated by the method)

###int writeRegister(unsigned int registerAddress, unsigned char value)
Writes a value to a defined register address (check the datasheet for the device)  
@param registerAddress the address of the register to write to  
@param value the value to write to the register  
@return returns 0 if successful

###void debugDumpRegisters(unsigned int number = 0xff)
A simple method to dump the registers to the standard output -- useful for debugging  
@param number the number of registers to dump

###int write(unsigned char value)
A write method that writes a single character to the SPI bus  
@param value the value to write to the bus  
@return returns 0 if successful

###int write(unsigned char value[], int length)
A write method that writes a block of data of the length to the bus.  
@param value the array of data to write to the device  
@param length the length of the data array  
@return returns 0 if successful

###int setSpeed(uint32_t speed)
Set the speed of the SPI bus  
@param speed the speed in Hz

###int setMode(SPIDevice::SPIMODE mode)
Set the mode of the SPI bus  
@param mode the enumerated SPI mode

###int setBitsPerWord(uint8_t bits)
Set the number of bits per word of the SPI bus  
@param bits the number of bits per word

###void close()
Close the SPI device

###int transfer(unsigned char read[], unsigned char write[], int length)
Generic method to transfer data to and from the SPI device. It is used by the
following methods to read and write registers.  
@param send The array of data to send to the SPI device  
@param receive The array of data to receive from the SPI device  
@param length The length of the array to send  
@return -1 on failure

###~SPIDevice()
The destructor closes the SPI bus device

Example Code
------------
Currently no test code is provided. May be done in future releases.