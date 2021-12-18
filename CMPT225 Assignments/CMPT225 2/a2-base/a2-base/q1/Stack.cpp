/* 
 * Stack.cpp
 *
 * Description: Implementation of an int sequence with push/pop ...
 * Class Invariant: ... in a LIFO order
 *
 * Author:
 * Date:
 */
#include<iostream>

#include <cstddef>  // For NULL
#include "Stack.h"

using namespace std;


Stack::Stack()
{
	head = NULL;
	tail = NULL;
	
}

Stack:: ~Stack()
{
	//Kuch bakchodi
}

void Stack::push(int x)
{
	StackNode* newNode = new StackNode;
	newNode->data = x;
	newNode->next = NULL;
	if (this->isEmpty() == false)
	{
		tail->next = newNode;
		tail = newNode;
		
	}
	else
	{
		head = newNode;
		tail = newNode;
		

	}
}


int Stack()::pop()
{
	if (this->isEmpty() == true)
	{
		cout << "Error: Stack is empty";
		return -1;
	}
	else if (head == tail)
	{
		int popData = head->data;
		delete head;
		head = NULL;
		tail = NULL;
		return popData;
	}
	else
	{
		StackNode* temp = head;
		while (temp->next->next != NULL)
		{
			temp = temp->next;
		}
		int popData = temp->next->data;
		
		delete temp->next;
		temp->next = NULL;
		return popData;
	}
}

int main()
{



	return 0;
}