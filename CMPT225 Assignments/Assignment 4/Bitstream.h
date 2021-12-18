


#pragma once
#include<iostream>

using namespace std;





class BitStream{
		
	char* fileString;
	int length;

public:

	void charRead(string fileName);
	void charWrite(string fileName);
	char* getArray();
	int getLength();
};