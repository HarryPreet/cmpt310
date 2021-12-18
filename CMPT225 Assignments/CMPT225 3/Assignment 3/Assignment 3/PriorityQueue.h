#pragma once
/*
 * PriorityQueue.h
 *
 * Description: Priority Queue
 * Class Invariant: The elements stored in this Priority Queue are always sorted.
 *
 * Author: Inspired by Frank M. Carrano and Tim Henry (textbook).
 * Modified: February 2019
 *
 */

 /* None of the current content of this file can be modified. */

#pragma once
#include"pch.h"
#include <iostream>
#include "Node.h"
#include "EmptyDataCollectionException.h"
#include"Event.h"

using namespace std;

template <class T>  // We can use T, ElementType or other names as a placeholder
class PriorityQueue {

private:

	Node<T>* head;      // Pointer to first node in the chain
	Node<T>*tail;
	int elementCount;   // Current count of list items
	int totalElements;

 /* You can add private methods to this class */

public:

	// Default Constructor
	PriorityQueue();

	// Copy Constructor
	PriorityQueue(const PriorityQueue& rhsPriorityQueue);

	// Destructor
	~PriorityQueue();

	// Description: Returns the number of elements in the Priority Queue.
	// Time Efficiency: O(1)
	int getElementCount() const;

	// Description: Returns "true" is this Priority Queue is empty, otherwise "false".
	// Time Efficiency: O(1)
	bool isEmpty() const;

	// Description: Inserts newElement in sort order.
	//              It returns "true" if successful, otherwise "false".
	// Precondition: This Priority Queue is sorted.
	// Postcondition: Once newElement is inserted, this Priority Queue remains sorted.
	// Time Efficiency: O(n)
	bool enqueue( const T& newElement);

	// Description: Removes the element with the "highest" priority.
	//              It returns "true" if successful, otherwise "false".
	// Precondition: This Priority Queue is not empty.
	// Time Efficiency: O(1)
	bool dequeue();

	// Description: Returns the element with the "highest" priority.
	// Precondition: This Priority Queue is not empty.
	// Postcondition: This Priority Queue is unchanged.
	// Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
	// Time Efficiency: O(1)
	T peek() const throw(EmptyDataCollectionException);

}; // end PriorityQueue
template <class T>
PriorityQueue<T>::PriorityQueue()
{
	head = NULL;
	tail = NULL;
	elementCount = 0;
}
template <class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue& rhsPriorityQueue)
{
	this->head = rhsPriorityQueue.head;
	this->tail = rhsPriorityQueue.tail;
	this->elementCount = rhsPriorityQueue.elementCount;
}
template <class T>
PriorityQueue<T>::~PriorityQueue()
{
	while (this->isEmpty() == false)
	{
		this->dequeue();
	}
}
template <class T>
int PriorityQueue<T>::getElementCount() const
{
	return this->elementCount;
}

template <class T>
bool PriorityQueue<T>::isEmpty()const
{
	return elementCount == 0;
}

template <class T>
bool PriorityQueue<T>::enqueue(const T& newElement)
{

	Node<T>* newNode = new Node<T>;
	newNode->data = newElement;
	newNode->link = NULL;

	if (head == NULL)
	{
		head = newNode;
		totalElements = elementCount;
		elementCount++;
		return true;
	}

	else if (head->link = NULL)
	{
		if ((head->data.getTime()) < (newElement.getTime()))
		{
			Node<T> *newNode = new Node<T>;
			head->link = newNode;
			
			elementCount++;
			totalElements = elementCount;
			return true;
		}
		else
		{
			newNode->link = head;
			head = newNode;
			elementCount++;

			totalElements = elementCount;

			return true;
		}

	}
	else
	{
		Node<T>*prev = head;
		Node<T>*curr = head->link;
		if (prev->data.getTime() > newElement.getTime)
		{
			newNode->link = head;
			head = newNode;
			
			elementCount++;
			totalElements = elementCount;
			return true;
		}
		while (curr != NULL)
		{
			if (curr->data.getTime() < newElement.getTime())
			{
				prev = prev->link;
				curr = curr->link;
				
			}
			else
			{
				newNode->link = prev->link;
				prev->link = newNode;
				
				elementCount++;
				totalElements = elementCount;
				return true;


			}
		}
		prev->link = newNode;
		elementCount++;
		totalElements = elementCount;
	}
}
	


template <class T>
bool PriorityQueue<T>::dequeue()
{
	if (this->isEmpty() == false)
	{
		Node<T>*dqElement = head;
		head = head->link;
		delete dqElement;
		elementCount--;
		return true;
	}
	else return false;

}
template <class T>
T PriorityQueue<T>:: peek() const throw(EmptyDataCollectionException)
{
	if (this->isEmpty() == true)
		throw EmptyDataCollectionException("Queue is empty");
	else
		return head->data;
}