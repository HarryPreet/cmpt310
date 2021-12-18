#pragma once
#include"pch.h"
#include<iostream>

using namespace std;

class Event
{
	char type;
	int time;
	int length;
public:
	Event();
	Event(char type, int time, int length);
	char getType();
	int getTime()const;
	int getLength()const;

	bool operator<(Event &E);
	friend ostream& operator<<(ostream &cout, const Event &E);


};