Beaglebone GPIO Class
=====================
By Philip D. Geramian
---------------------
### pdgerami@syr.edu

The following code provides a Beaglebone GPIO Class.

Release 1.0  
Feb. 29th, 2016

Public Functions:
-----------------

###GPIO()
This Constructor does nothing and should not be used

###GPIO(int pin)
This Constructor should be used at all times.
This checks to make sure the user is running the
program with sufficient privilages (root or sudo).
To use provide the constructor with the absolute 
Beaglebone GPIO number (Bank*32+Offset).
This constructor handles exporting the GPIO and 
leaves everything set to defaults.

###void Set(int value)
This member function sets the GPIO to the passed value
(1 or 0).

###int Get()
This member function gets the current value of the GPIO
(1 or 0).

###void Mode(std::string mode)
This member function sets the direction of the GPIO to 
either 'IN' or 'OUT'. The code can accept the passed
parameter in any letter case (upper or lower).

###~GPIO()
This Destructor will unexport the GPIO pin we are using
and should be manually called if allocating the GPIO on 
the Heap (by using 'new'), by calling delete, otherwise
if the GPIO is on the stack, the destructor should be 
automatically called when the code goes out of scope
(leaves {...}).

Example Code
------------
The file GPIO.cpp includes a macro protected main 
function to test functionality. It makes use of GPIO 60 
The macro is named "TEST_GPIO". To use this main while 
compiling with GCC the following command can be used:

```g++ -D TEST_GPIO GPIO.cpp -o GPIO_TEST```
