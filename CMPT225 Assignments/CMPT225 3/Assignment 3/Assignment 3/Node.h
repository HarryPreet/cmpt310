#pragma once
#include<iostream>
#include"pch.h"
#include"Event.h"

template <class T>

class Node
{

	

public:
	T data;
	Node* link;

	Node()
	{
		data();
		link = NULL;
	}
	Node(T d, T l)
	{
		data = d;
		link = l;
	}



};