#pragma once

#include<iostream>

using namespace std;

class FrequencyCounter{

	int frequency[256];


public:

	FrequencyCounter();
	void makeTable(string fileName);

};