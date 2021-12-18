/*
 * List.cpp
 *
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - (What other characteristic does our List have?)
 *
 * Author: Harry Preet Singh
 * Date:19th January, 2019
 */


#include<iostream>
#include<string>
#include "List.h"
#include "Patient.h"

using namespace std;

List::List()
{
	cout << "Works";
	elementCount = 0;
	capacity = MAX_ELEMENTS-1;
}

int List:: getElementCount() const
{
	return elementCount;
}
// Description: Insert an element.
	// Precondition: newElement must not already be in data collection.  
	// Postcondition: newElement inserted and elementCount has been incremented. 
bool List::insert(const Patient& newElement)
{
	//Checking whether the new element is alrady in the list or not
	for (int i = 0; i < elementCount; ++i)
	{
		if (elements[i].getCareCard == newElement.getCareCard())
			return false;

	}
	//Checking whether there is space to add a new element or not
	if (elementCount = MAX_ELEMENTS-1)
	{
		return false;
	}
	Patient temp;
	//If the list is empty the element is inserted at the first position
	if (elementCount == 0)
	{
		elements[0] = newElement;
		elementCount++;
		return true;
		
	}
	//If the list has only one element the new element is inserted at second position
	if (elementCount == 1)
	{
		elements[1] = newElement;
		elementCount++;
		return true;

	}

	//Iterating until the second last element
	for (int i = 0; i < elementCount - 1; i++)
	{	
		//Condition of insertion: only if the new element's care card# is less than the next element but greater than the current element
		if (elements[i].getCareCard() < newElement.getCareCard() && elements[i] > newElement.getCareCard())
		{
			for (int j = elementCount - 1; j > i; --j)
			{
				elements[j + 1] = elements[j];
			}
			elements[i] = newElement;
			elementCount++;
			return true;

		}
	}
	//If the new element's care card# is the greatest i.e insertion at last
	elements[elementCount]=newElement;
	elementCount++;
	return true;
	
}
// Description: Remove an element. 
// Postcondition: toBeRemoved is removed and elementCount has been decremented.	
bool List::remove(const Patient& toBeRemoved)
{	
	//When list is empty
	if (elementCount == 0)
		return false;
	//If the first element is the element to be removed
	if (elementCount == 1 && elements[0].getCareCard() == toBeRemoved.getCareCard())
	{
		elementCount == 0;
	}
	//Iterates throuigh the list and shifts the elements to one place to the left of array if the element is found
	for (int i = 0; i < elementCount-1; ++i)
	{
		if (elements[i].getCareCard() == toBeRemoved.getCareCard())
		{
			for (int j = i; j < elementCount - 2; ++j)
			{
				elements[j] = elements[j + 1];
			}
			elementCount--;
			return true;
		}
	}
	//Removal of last element
	if (elements[elementCount - 1].getCareCard() == toBeRemoved.getCareCard())
	{
		elementCount--;
		return true;
	}
	else
		return false;	
}

void List::removeAll()
{
	elementCount = 0;
}

Patient* List::search(const Patient& target)
{
	for (int i = 0; i < elementCount; ++i)
	{
		if (elements[i].getCareCard() == target.getCareCard())
			return &elements[i];
	}
	return NULL;
}
