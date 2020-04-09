#pragma once


#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

#define SERIALCLASS_H_INCLUDED
#define ARDUINO_WAIT_TIME 2000

using namespace std;
class Serial
{
private:
    //Serial comm handler
    HANDLE hSerial;
    //Connection status
    bool connected;
    //Get various information about the connection
    COMSTAT status;
    //Keep track of last error
    DWORD errors;

public:
    //Initialize Serial communication with the given COM port
    Serial(const char* portName);
    //Close the connection
    ~Serial();
    //Read data in a buffer, if nbChar is greater than the
    //maximum number of bytes available, it will return only the
    //bytes available. The function return -1 when nothing could
    //be read, the number of bytes actually read.
    int ReadData(char* buffer, unsigned int nbChar);
    //Writes data from a buffer through the Serial connection
    //return true on success.
    bool WriteData(const char* buffer, unsigned int nbChar);
    //Check if we are actually connected
    bool IsConnected();


};

Serial* ARDUINO_CONNECTIN(string port_name);
void ARDUINO_SERIAL_TXT(Serial* SP, string txt);
void ARDUINO_SERIAL_CONNECTION(Serial* SP, string port_name);