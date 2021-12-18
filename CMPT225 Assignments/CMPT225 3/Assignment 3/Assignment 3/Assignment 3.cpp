#include"pch.h"
#include<iostream>
#include"EmptyDataCollectionException.h"
#include"Event.h"
#include"Queue.h"
#include"Node.h"
#include"PriorityQueue.h"
using namespace std;

int main()
{

	Queue<int> q;
	
	try {
		cout << q.peek();
	}
	catch (EmptyDataCollectionException)
	{
		cout << "Exiting";
		return 0;
	}
	system("pause");
	return 0;
}