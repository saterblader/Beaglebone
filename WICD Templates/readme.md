WICD Network Templates
=======================
By Philip D. Geramian
---------------------
### pdgerami@syr.edu

The following are templates for WICD

Release 1.0  
April 2nd, 2016


Usage:
------
To use any of these templates copy them over to:
```/etc/wicd/encryption/templates``` and add their 
name(s) to the "active" file. Then issue 
```sudo serivice wicd restart```. You should now 
see the template(s) you added as options on the 
drop-down under encryption options.

Templates:
-----------------

###AirOrangeX  
This template is a customized version of the 
peap-mschapv2 template that is for usage on 
the Syracuse University Network and ask for 
the users NetID and password.  

###peap-mschapv2  
This template is for use on enterprise WPA2 
networks that make use of peap-mschapv2 sign-in 
method.
