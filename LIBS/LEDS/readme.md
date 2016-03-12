Beaglebone LEDS Class
=====================
By Philip D. Geramian
---------------------
### pdgerami@syr.edu

The following code provides a Beaglebone LED Class 
for the USR LEDS

Release 1.0  
Feb. 29th, 2016

Public Functions:
-----------------
###LEDS()
This Constructor does nothing and should not be used

###LEDS(int pin);
This Constructor should be used at all times.
Pass the USR LED number you wish to control as the 
provided parameter.

###void Set(int value);
This member function will set the value of the LED to
the value passed in (1 or 0).

###~LEDS();
This Destructor does nothing upon being called

Example Code
------------
The file LEDS.cpp includes a macro protected main 
function to test functionality. The macro is named
"TEST_LEDS". This main makes use of USR LED 1. To 
use this main while compiling with GCC the following 
command can be used:

```g++ -D TEST_LEDS LEDS.cpp -o LEDS_TEST```
