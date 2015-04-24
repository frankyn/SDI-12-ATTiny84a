# SDI-12-ATTiny84a
SDI-12 Protocol for the Atmel ATTiny84a mcu built to work within AVR-GCC only code. This is a port based on the https://github.com/StroudCenter/Arduino-SDI-12 project first developed by StroudCenter. 

The project focuses on porting StroudCenter's SDI-12 implementation to a non-Arduino compatible SDI-12 library for the ATTiny84a. There is small issue with port mapping that requires attention.


# Build/Compile
To build just use the MakeFile
> make 

# Flash
In the MakeFile you'll find I currently use AVRDude with a USBTiny programmer. You'll need to configure this portion of the Makefile for your environment. 

To flash:
> make flash





