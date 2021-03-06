Beaglebone AIN Class
====================
By Philip D. Geramian
---------------------
### pdgerami@syr.edu

The following code provides a Beaglebone AIN Class.

Release 1.2  
March 25, 2016

Changes
-------
v1.2  
-Fixed constructor to allow for sysFS file number

v1.1  
-Fixed destructor syntax error  

Public Functions:
-----------------

###AIN(int sysFS, int pin)
This Constructor should be used at all times.
This checks to make sure the passed value is a 
valid number (between 0 and 7), and sets the required 
private member data. sysFS is the number that comes 
after "../helper." As an example "../helper.12" sysFS 
would equal 12.

###int Get()
This member function gets the current value of the AIN
(from 0 to 1799). Returns -1 when failed

###~AIN()
This Destructor will nullify all private member data
and should be manually called if allocating the AIN on 
the Heap (by using 'new'), by calling delete, otherwise
if the AIN is on the stack, the destructor should be 
automatically called when the code goes out of scope
(leaves {...}).

Example Code
------------
The file AIN.cpp includes a macro protected main 
function to test functionality. It makes use of AIN 1 
The macro is named "TEST_AIN". To use this main while 
compiling with GCC the following command can be used:

```g++ -D TEST_AIN -std=c++11 AIN.cpp -o AIN_TEST```
