
#pragma once


#include<iostream>
#include<fstream>
#include<string>
#include "Node.h"
#include "EmptyDataCollectionException.h"
using namespace std;


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





using namespace std;


class PriorityQueue {

private:

   Node * head;      // Pointer to first node in the chain
   int elementCount;   // Current count of list items

/* You can add private methods to this class */

   // Utility method - Locates the node that is before the node that should or does
   //                  contain the anElement.
   Node * getNodeBefore(const Node& anElement) const;

   // Utility method - Destroy the whole linked list - same as dequeueAll()
   void clear();

   // Utility method - Copy a linked list
   Node * copyLinkedList(const Node * originalHead);

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
   bool enqueue(const Node& newElement);

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
   Node peek() const throw(EmptyDataCollectionException);

   // For Testing Purposes
   // Description: Prints the content of "this".
   void printPriorityQueue( ) const;

   // To deal with the warning regarding template and friend function: 
   // I used the first "Introvert" solution described in 
   // https://stackoverflow.com/questions/4660123/overloading-friend-operator-for-template-class
   // The idea: only declare a particular instantiation of the << operator as a friend
   // by inlining the operator.  
   friend ostream & operator<< (ostream & os, const PriorityQueue & rhs) {
      Node * current = rhs.head;

      os << "elementCount = " << rhs.elementCount;
      
      // Traverse the list
      while (current != NULL){
         os << current -> letter; // Print data
         current = current -> next; // Go to next Node
      }

      return os;
   } // end of operator <<

}; // end PriorityQueue

// Default Constructor

PriorityQueue ::PriorityQueue() {
   head = NULL;
   elementCount = 0;
   // cout << "PriorityQueue Default constructor" << endl; // For learning purposes!
} // end of default constructor

// Copy Constructor

PriorityQueue ::PriorityQueue(const PriorityQueue& rhsPriorityQueue) {
   head = copyLinkedList(rhsPriorityQueue.head);
   elementCount = rhsPriorityQueue.elementCount;
   // cout << "PriorityQueue Copy constructor" << endl; // For learning purposes!
}  // end copy constructor

// Utility method - Copy a linked list

Node * PriorityQueue ::copyLinkedList(const Node * originalHead) {
    Node * copiedHead = NULL;

   if (originalHead != NULL)
   {
      // Build new linked list from given one
      copiedHead = new Node (originalHead->data);
      if ( copiedHead != NULL )
         copiedHead->next = copyLinkedList(originalHead->next);
      else
         return NULL;
   }  // end if

   return copiedHead;
}  // end copylinked list

// Destructor

PriorityQueue ::~PriorityQueue() {
   clear();
   // cout << "PriorityQueue destructor" << endl; // For learning purposes!
}  // end destructor

// Utility method - Destroy the whole linked list - same as dequeueAll()
void PriorityQueue ::clear()
{
   while (!isEmpty())
      dequeue();
}  // end clear

// Description: Returns the number of elements in the Priority Queue.

int PriorityQueue ::getElementCount() const {
   return elementCount;
}

// Description: Returns "true" is this Priority Queue is empty, otherwise "false".
// Time Efficiency: O(1)
bool PriorityQueue ::isEmpty() const {
   return ( elementCount == 0 && head == NULL );
}  // end isEmpty


// Description: Inserts newElement in sort order.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is sorted.
// Postcondition: Once newElement is inserted, this Priority Queue remains sorted.
// Time Efficiency: O(n)
bool PriorityQueue ::enqueue(const Node& newElement) {

   // cout << "PriorityQueue::enqueue" << endl;

   bool ableToEnqueue = false;

   Node * newNode = new Node (newElement);

   if ( newNode != NULL ){
         Node * previous = getNodeBefore(newElement);

      if ( isEmpty() || previous == NULL) { // Add at beginning
         newNode->next = head;
         head = newNode;
      }
      else {  // Add after node before
            Node * afterNode = previous->next;
            newNode->next = afterNode;
            previous->next = newNode;
       } // end if

      elementCount++;    // Increment count of elements
      ableToEnqueue = true;
   }

   return ableToEnqueue;
} // end enqueue

// Utility method - Locates the node that is before the node that should or does
//                  contain the anElement.

Node * PriorityQueue ::getNodeBefore(const Node& anElement) const {

   Node * current = head;
   Node * previous = NULL;

   // Enqueueing the newElement after the already enqueued elements with smaller or equal priority value
   // i.e., preserving the FIFO characteristic of this PriorityQueue
   while ( (current != NULL) && (current->data <= anElement.data) )
   {
      previous = current;
      current = current->next;
   } // end while

   return previous;
} // end getNodeBefore

// Description: Removes the element with the "highest" priority.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is not empty.
// Time Efficiency: O(1)

bool PriorityQueue ::dequeue() {
   bool ableToDequeue = false;

   if ( !isEmpty() ) {
      Node * current = head;

      // Delete the first node in the linked list
      head = head->next;

      // Return deleted node to system
      current->next = NULL;
      delete current;
      current = NULL;

      elementCount--;  // Decrement count of elements
      ableToDequeue = true;
   }  // end if

   return ableToDequeue;
}  // end remove


// Description: Returns (a copy of) the element with the "highest" priority.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
// Time Efficiency: O(1)

Node PriorityQueue ::peek() const throw(EmptyDataCollectionException) {

   // Enforce precondition
   if ( !isEmpty() )
   {
      Node * node = head;
      return node->data;
   }
   else
      throw(EmptyDataCollectionException("peek() called with an empty PriorityQueue."));

}  // end peek


// For Testing Purposes - See Labs 3 and 4.
// Description: Prints the content of "this".

void PriorityQueue ::printPriorityQueue( ) const {
   Node * current = head;

   // Traverse the list
   while (current != NULL){
      cout << current -> data; // Print data
      current = current -> next; // Go to next Node
   }

}  // end printPriorityQueue

//  End of implementation file.


