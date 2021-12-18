#include<iostream>
#include<string>
#include<fstream>
#include"FrequencyCounter.h"
#include"BitStream.h"


FrequencyCounter:: FrequencyCounter()
{
	for(int i =0; i<256;++i)
	{
		frequency[i]=0;
	}
}


void  FrequencyCounter :: makeTable(string fileName)
{
		BitStream stream;
		stream.charRead(fileName);
		char* freqString=stream.getArray();

		for(int i =0; i<stream.getLength();++i)
		{
			frequency[freqString[i]]++;
			
		}
		

}
