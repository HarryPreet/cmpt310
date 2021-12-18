#include<iostream>
#include<fstream>
#include<string>
#include"BitStream.h"
using namespace std;



void BitStream:: charRead( string fileName)
{
	
	ifstream is;;
	char buffer;
	length=0;
	cout<< fileName;
	is.open(fileName);
	
	while(!is.eof())
	{
		is>>buffer;
		length++;
	}
	
	//loop to populate array

	fileString= new char[length];
	is.close();
	is.open(fileName);
	
	if(is)
	{	
		int i =0;
		while(!is.eof())
		{
			
			is>>buffer;
			fileString[i++]=buffer;
			
		}

		fileString[length]='\0';
		
		is.close();
		
	
	}

	
}

char* BitStream::getArray()
{
	return fileString;
}

int BitStream::getLength()
{
	return length;
}
