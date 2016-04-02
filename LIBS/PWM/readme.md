Beaglebone PWM Class
====================
By Philip D. Geramian
---------------------
### pdgerami@syr.edu

The following code provides a Beaglebone PWM Class.

Release 1.0  
March 25th, 2016

Public Functions:
-----------------

###PWM(int sysFS, int hdr, int pin)
This constructor sets up the file path for the PWM passed to the object.
sysFS is the value that comes after the ' . ' in the pwm folder, while hdr 
is either 8 or 9, and pin is the pin number on that header that we are 
using.

###void setPeriod(int period)
This member function sets the period of the PWM that our object is 
supporting.

###void setDuty(int duty)
This member function sets the duty of the PWM that our object is 
supporting.

###void setRun(bool run)
This member function turns on the PWM that our object is supporting.

###void setPolarity(bool polarity)
This member function sets the polarity of the PWM that our object is 
supporting.

###~PWM()
This Destructor will turn off the pwm that we are using
and should be manually called if allocating the pwm on 
the Heap (by using 'new'), by calling delete, otherwise
if the pwm is on the stack, the destructor should be 
automatically called when the code goes out of scope
(leaves {...}).

Example Code
------------
The file PWM.cpp includes a macro protected main 
function to test functionality. It makes use of PWM P8_13. 
The macro is named "TEST_PWM". To use this main while 
compiling with GCC the following command can be used:

```g++ -std=c++11 -D TEST_PWM PWM.cpp -o PWM_TEST```
