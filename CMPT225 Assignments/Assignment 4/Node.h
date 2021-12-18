#pragma once
#include<iostream>
using namespace std;




class Node{


public:
	int data;
	char letter;


	Node* next;

	Node();
	Node(int f, char l);
	Node(int f);
	int getFreq();
	char getLetter();
	

};


Node:: Node()
{
	
	data=0;
	letter =0;

}



Node::Node(int f, char l)
{
	data=f;
	letter=l;

}


Node::Node(int f)
{
	data=f;
	next=letter;
}



int Node:: getFreq()
{
	return data;
}


char Node:: getLetter()
{
	return letter;
}