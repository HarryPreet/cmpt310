#include"pch.h"
#include<iostream>
#include"Event.h"

using namespace std;

Event::Event()
{
	type = 'N';
	time = 0;
	length = 0;

}

Event::Event(char type, int time, int length)
{
	this->type = type;
	this->time = time;
	this->length = length;
}
char Event::getType()
{
	return type;
}

int Event::getTime()const
{
	return time;
}

int Event::getLength()const
{
	return length;
}


bool Event:: operator<(Event &E)
{
	if (this->time < E.time)
		return true;
	else
		return false;
}

ostream& operator<<(ostream& cout, const Event &E)
{
	cout << "Type: " << E.type << " Time: " << E.time << " Lenght: " << E.length;

	return cout;

}