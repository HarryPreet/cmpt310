#pragma once
/*
 * Queue.h
 *
 * Description: Implementation of an int sequence with enqueue/dequeue ...
 * Class Invariant: ... in FIFO order
 *
 * Author: Harry Preet Singh
 * Date: 6 February 2018
 */
#include"pch.h"

template<class ElementType>
class Queue {
private:
	static unsigned const INITIAL_SIZE = 3;
	ElementType *elements;  // replace this by int * elements in Question 4(a)

	unsigned elementCount;  // number of elements in the queue

	unsigned frontindex;    // index the topmost element
	unsigned backindex;     // index where the next element will be placed

public:
	// Desc:  Constructor
	Queue();
	unsigned capacity;      // number of cells in the array

	//Desc: Destructor
	~Queue();

	// Desc:  Inserts element x at the back (O(1))
	void enqueue(ElementType x);


	// Desc:  Removes the frontmost element (O(1))
	//  Pre:  Queue not empty
	void dequeue();


	// Desc:  Returns a copy of the frontmost element (O(1))
	//  Pre:  Queue not empty

	ElementType peek() const throw(EmptyDataCollectionException);


	// Desc:  Returns true if and only if queue empty (O(1))
	bool isEmpty() const;

	friend ostream& operator<<(ostream& cout, ElementType T)
	{
		for (int i = 0; i < T.elementCount; ++i)
			cout << T.elements[i];
	}


};


template<class ElementType>
Queue<ElementType>::Queue() {
	elementCount = 0;
	capacity = INITIAL_SIZE;
	frontindex = 0;
	backindex = 0;
	elements = new ElementType[INITIAL_SIZE];
} // constructor
template<class ElementType>
Queue<ElementType>::~Queue()
{
	delete[]elements;
}

template<class ElementType>

// Desc:  Inserts element x at the back (O(1))
void Queue<ElementType>::enqueue(ElementType x) {

	if (elementCount == capacity)
	{
		ElementType* newElements = new ElementType[capacity * 2];
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
template<class ElementType>
void Queue<ElementType>::dequeue() {
	elementCount--;
	frontindex = (frontindex + 1) % capacity;

	if (((static_cast<float>(elementCount) / static_cast<float>(capacity)) < 0.25) && ((capacity / 2) > INITIAL_SIZE))
	{

		ElementType* newElements = new ElementType[capacity * 2];
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


	}
} // dequeue


// Desc:  Returns a copy of the frontmost element (O(1))
//  Pre:  Queue not empty
template<class ElementType>
ElementType Queue<ElementType>::peek() const throw(EmptyDataCollectionException) {

	if (this->isEmpty() == true)
		throw EmptyDataCollectionException("Queue is empty");
	else
	return elements[frontindex];
} // top

template<class ElementType>
// Desc:  Returns true if and only if queue empty (O(1))
bool Queue<ElementType>::isEmpty() const {
	return elementCount == 0;
} // isempty



