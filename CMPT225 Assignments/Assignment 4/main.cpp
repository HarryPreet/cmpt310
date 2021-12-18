#include<iostream>
#include<fstream>
#include"Bitstream.h"
#include"FrequencyCounter.h"
#include"Node.h"
#include"PriorityQueue.h"
using namespace std;

int main(int argc, char** argv) {
	
    /*string inFile = "";
    string outFile = "";
    if( argc == 3 ) {
      inFile = argv[1];
      outFile = argv[2];
    }*/
	ostream os;
	os.open("hello.txt")
	int i;
	char num[8] = "11110011";
	unsigned char result = 0;

	for (i = 0; i < 8; ++i)
		result |= (num[i] == '1') << (7 - i);
	open>>result
	return 0;
}