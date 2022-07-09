#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<stdlib.h>
#include"SerialPort.h"
#include <windows.h>

char output[MAX_DATA_LENGTH];
char incomingData[MAX_DATA_LENGTH];

// change the name of the port with the port name of your computer
// must remember that the backslashes are essential so do not remove them
char port[] = "COM6"; //\\\\.\\

int main() {
	unsigned int microsecond = 1000000;
	int i=1;
	int num;
	SerialPort arduino(port);
	if (arduino.isConnected()) {
		cout << "Connection made" << endl << endl;
	}
	else {
		cout << "Error in port name" << endl << endl;
	}
	while (arduino.isConnected())
	{
		/*cout << "Enter your command: " << endl;
		string data;
		cin >> data;

		char* charArray = new char[data.size() + 1];
		copy(data.begin(), data.end(), charArray);
		charArray[data.size()] = '\n';

		arduino.writeSerialPort(charArray, MAX_DATA_LENGTH);*/
		i++;
		//Sleep(1 * microsecond);  
		arduino.readSerialPort(output, MAX_DATA_LENGTH);
		num = atoi(output);
		//cout << "Gia tri encoder la:" << output << endl;
		//cout << "<<" << output << endl;
		cout << ">> " << num << endl;
		/*if (num == 1000)
		{
			cout << "suceefull" << endl;
			break;
		}*/
		if (i == 1000)
		{
			break;
		}
		memset(output, 0, MAX_DATA_LENGTH);   
		//delete[] charArray;
	}
	return 0;
}



//#include<windows.h>
//#include<iostream>
//
//int main()
//{
//
//    HANDLE hComm;
//    std::string port_name = "COM6";  //change port name
//    char write_buffer[] = "Test Data";
//    char read_buffer[100];
//    DWORD dNoOFBytestoWrite;         // No of bytes to write into the port
//    DWORD dNoOfBytesWritten = 0;     // No of bytes written to the port
//    DWORD bytes_read = 0;
//
//    hComm = CreateFileA(port_name.c_str(),                //port name
//        GENERIC_READ | GENERIC_WRITE, //Read/Write
//        0,                            // No Sharing
//        NULL,                         // No Security
//        OPEN_EXISTING,// Open existing port only
//        0,            // Non Overlapped I/O
//        NULL);        // Null for Comm Devices
//
//    if (hComm == INVALID_HANDLE_VALUE)
//    {
//        std::cerr << "Error in opening serial port”";
//        return -1;
//    }
//    else
//        std::cerr << "opening serial port successful";
//
//    DCB dcbSerialParams = { 0 }; // Initializing DCB structure
//    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
//    GetCommState(hComm, &dcbSerialParams);
//
//    dcbSerialParams.BaudRate = CBR_9600;  // Setting BaudRate = 9600
//    dcbSerialParams.ByteSize = 8;         // Setting ByteSize = 8
//    dcbSerialParams.StopBits = ONESTOPBIT;// Setting StopBits = 1
//    dcbSerialParams.Parity = NOPARITY;  // Setting Parity = None
//    SetCommState(hComm, &dcbSerialParams);
//
//    COMMTIMEOUTS timeouts = { 0 };
//    timeouts.ReadIntervalTimeout = 20; // in milliseconds
//    timeouts.ReadTotalTimeoutConstant = 100; // in milliseconds
//    timeouts.ReadTotalTimeoutMultiplier = 10; // in milliseconds
//    timeouts.WriteTotalTimeoutConstant = 100; // in milliseconds
//    timeouts.WriteTotalTimeoutMultiplier = 10; // in milliseconds 
//
//
//    dNoOFBytestoWrite = sizeof(write_buffer);
//
//    WriteFile(hComm,        // Handle to the Serial port
//        write_buffer,     // Data to be written to the port
//        dNoOFBytestoWrite,  //No of bytes to write
//        &dNoOfBytesWritten, //Bytes written
//        NULL);
//    do
//    {
//        ReadFile(hComm,      //Handle of the Serial port
//            &read_buffer,       //Temporary character
//            100,//Size of TempChar
//            &bytes_read,    //Number of bytes read
//            NULL);
//
//    } while (bytes_read <= 0);
//
//    std::cout << "Read Data : " << read_buffer << std::endl;
//    CloseHandle(hComm);//Closing the Serial Port
//    int i = 1;
//    while (1)
//    {
//        i++;
//        ReadFile(hComm,      //Handle of the Serial port
//            &read_buffer,       //Temporary character
//            100,//Size of TempChar
//            &bytes_read,    //Number of bytes read
//            NULL);
//        std::cout << "Read Data : " << read_buffer << std::endl;
//        //memset(read_buffer, 0, 100);
//        if (i == 1000)
//            break;
//    }
//    return 0;
//}