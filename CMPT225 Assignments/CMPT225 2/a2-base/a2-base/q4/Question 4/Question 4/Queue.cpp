/* 
 * Queue.cpp
 *
 * Description: Implementation of an int sequence with enqueue/dequeue ...
 * Class Invariant: ... in FIFO order
 *
 * Author: Harry Preet Singh
 * Date: February 6, 2018
 */
#include"pch.h"
#include "Queue.h"
#include<iostream>
using namespace std;
// Desc:  Constructor
Queue::Queue() : elementCount(0), capacity(INITIAL_SIZE), frontindex(0), backindex(0) {
	elements = new int[INITIAL_SIZE];
} // constructor

Queue::~Queue()
{
	delete[]elements;
}


// Desc:  Inserts element x at the back (O(1))
void Queue::enqueue(int x) {
	
	if (elementCount == capacity)
	{
		int* newElements = new int[capacity * 2];
		int  newIndex = 0;
		for (int i = frontindex; i < (frontindex + elementCount); ++i)
		{
			newElements[newIndex] = elements[i%capacity];
			newIndex++;
		}
		elementCount = newIndex;
		delete[]elements;
		capacity = capacity * 2;
		elements = newElements;
		newElements = nullptr;
		delete newElements;
		frontindex = 0; backindex = elementCount;
		enqueue(x);
	}

	
	else if (elementCount < capacity)
	{
		elementCount++;
		elements[backindex] = x;
		backindex = (backindex + 1) % capacity;
	}
	
	
	

    
} // enqueue


// Desc:  Removes the frontmost element (O(1))
//  Pre:  Queue not empty
void Queue::dequeue() {
    elementCount--;
    frontindex = (frontindex + 1) % capacity;
	
	if (((static_cast<float>(elementCount) / static_cast<float>(capacity)) <0.25) && ((capacity / 2) > INITIAL_SIZE))
	{
		cout << "capcity old :" << capacity;
		int* newElements = new int[capacity * 2];
		int newIndex = 0;
		for (int i = frontindex; i < (frontindex + elementCount); ++i)
		{
			newElements[newIndex] = elements[i%capacity];
			newIndex++;
		}
		elementCount = newIndex;
		delete[]elements;
		capacity = capacity / 2;
		elements = newElements;
		newElements = nullptr;
		delete newElements;
		frontindex = 0; backindex = elementCount;
		cout << "capacity new :" << capacity;

	}
} // dequeue


// Desc:  Returns a copy of the frontmost element (O(1))
//  Pre:  Queue not empty
int Queue::peek() const {
    return elements[frontindex];
} // top


// Desc:  Returns true if and only if queue empty (O(1))
bool Queue::isEmpty() const {
    return elementCount == 0;
} // isempty




