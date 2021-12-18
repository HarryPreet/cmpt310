#include<iostream>
#include"Bitstream.h"
#include"FrequencyCounter.h"
#include"Node.h"
#include"PriorityQueue.h"
using namespace std;

int main(int argc, char** argv) {
	
    string inFile = "";
    string outFile = "";
    if( argc == 3 ) {
      inFile = argv[1];
      outFile = argv[2];
    }
    else {
      cout << "Usage: ./cppfile InputFile OutputFile\n";
      return 1;
    }
	
	Node N(2, 'a', NULL, NULL);
	Node N1(3, 'b', NULL, NULL);
	Node N2(1,'c',NULL, NULL);
	PriorityQueue p;
	p.enqueue(N);
	p.enqueue(N1);
	p.enqueue(N2);
	p.printPriorityQueue();
	p.dequeue();
	cout<<endl;
	p.printPriorityQueue();
	return 0;
}