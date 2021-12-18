

//This assignment was done in group of two students: Harry Preet Singh(SINHD1801) and Navdeep Singh Cheema(CHEND1801)

// Questions done : 1,3,4,6,7,8,5 in this order
//ALL CODES ARE COMMENTED HENCE WOULD REQUIRE UNCOMMENTING TO RUN




// Assignment 2.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include "pch.h"
#include <iostream>
using namespace std;

/*question 1
class Animal
{
	string name;
	int age;

public:
	string get_name()
	{
		return name;

	}

	int get_age()
	{
		return age;
	}
	virtual void speak()
	{
		cout << "  ";
		cout << endl;
	}

};

class Dog : public Animal
{
public :
	virtual void speak()
	{
		cout << "Barks";
	}
	void action()
	{
		cout << "Action";

	}


};

class PetDog : public Dog
{
public:

	void action()
	{
		cout << "Fetch a Stick";
	}

};

class StrayDog:public Dog
{
public :

	void action()
	{
		cout << "Chase Cars";
	}
	void speak()
	{
		cout << "woof woof";
	}


};

class Cat :public Animal
{
public :
	void speak()
	{
		cout << "Meow";
	}
};




int main()
{
	Animal *an_arr[7],animal;
	Dog dog;
	PetDog pdog,pdog2;
	Cat cat;
	StrayDog sdog,sdog3;

	an_arr[0] = &dog;
	an_arr[1] = &pdog;
	an_arr[2] = &pdog2;
	an_arr[3] = &cat;
	an_arr[4] = &sdog;
	an_arr[5] = &sdog3;
	an_arr[6] = &animal;

	for (int i = 0; i < 7; ++i)
	{	
		cout << endl;
		an_arr[i]->speak();
	}

	system("pause");
	return 0;
}
*/

//Question 3
/*
void findAndReplace(char*phrase, char find, char replace, int startPos)
{
	if (phrase[startPos] == '\0')
		return;
	else
	{
		if (phrase[startPos] == find)
		{
			phrase[startPos] = replace;
			findAndReplace(phrase, find, replace, startPos + 1);
			return;
		}
		else
			findAndReplace(phrase, find, replace, startPos+1);

	}
}

int main()
{	
	char def[6];
	cin >> def;
	findAndReplace(def, '1', '2', 0);
	cout << def;
	system("pause");
	return 0;
}
*/
//Question4

#include<fstream>
#include<string>

/*int main()
{
	ifstream read;
	ofstream write;
	string line;
	
	read.open("Read_File.txt", ios::out);
	
	write.open("Write_File.txt",ios::app);
	if (read.is_open() &&write.is_open())
	{
		int i = 0;
		while (getline(read, line))
		{
			
			write << line;
			write << endl;

		}
	}
	else 
		cout << "error";
	read.close();
	write.close();
	system("pause");
	return 0;
}*/


/*int main()
{
	ifstream read;
	ofstream write;
	string line;

	read.open("Read_File.txt", ios::out);

	write.open("Write_File.txt", ios::in);

	if (read.is_open() && write.is_open())
	{
		int i = 0;
		while (getline(read, line))
		{
			write << line;
			write << endl;
			write << endl;

		}
	}
	else
		cout << "error";
	read.close();
	write.close();
	system("pause");
	return 0;

}*/

/*int main()
{
	ifstream read;
	ofstream write;
	string line,line1;

	read.open("Read_File.txt", ios::out);

	write.open("Write_File.txt", ios::in);

	if (read.is_open() && write.is_open())
	{
		int i = 0;
		while (getline(read, line))
		{
			
			getline(read, line1);
			write << line1;
			write << endl;
			write << line;
			write << endl;



		}
	}
	else
		cout << "error";
	read.close();
	write.close();
	system("pause");
	return 0;

}*/

//Question 6

/*class Weapon
{
	int strength;
protected:
	char type;
	
	
public:
	void setPower(int p)
	{
		strength = p;
	}
	int return_strength()
	{
		return strength;
	}
	char return_type()
	{
		return type;
	}
	
	int modified = 0;

};


class Rock :public Weapon
{
public:
	Rock()
	{
		type = 'R';
	}
	bool battle(Weapon a)
	{
		if (a.return_type() == 'P')
		{
			modified = return_strength() / 2;
			a.modified = a.return_strength() * 2;
		}
		if (a.return_type() == 'S')
		{
			modified = return_strength()*2;
			a.modified = a.return_strength() / 2;
		}

		if (modified > a.modified)
		{
			modified = 0;
			a.modified = 0;
			return true;
		}
		else if (modified < a.modified)
		{
			modified = 0;
			a.modified = 0;
			return false;
		}
		
	}
};
class Papers :public Weapon
{
public:
	Papers()
	{
		type = 'P';
	}
	bool battle(Weapon a)
	{
		if (a.return_type() == 'S')
		{
			modified = return_strength() / 2;
			a.modified = a.return_strength() * 2;
		}
		if (a.return_type() == 'R')
		{
			modified = return_strength() * 2;
			a.modified = a.return_strength() / 2;
		}

		if (modified > a.modified)
		{
			modified = 0;
			a.modified = 0;
			return true;
		}
		else if (modified < a.modified)
		{
			modified = 0;
			a.modified = 0;
			return false;
		}

	}
};
class Scissors :public Weapon
{
	
public:
	Scissors()
	{
		type = 'S';
	}
	bool battle(Weapon a)
	{
		if (a.return_type() == 'R')
		{
			modified = return_strength() / 2;
			a.modified = a.return_strength() * 2;
		}
		if (a.return_type() == 'P')
		{
			modified = return_strength() * 2;
			a.modified = a.return_strength() / 2;
		}

		if (modified > a.modified)
		{
			modified = 0;
			a.modified = 0;
			return true;
		}
		else if (modified < a.modified)
		{
			modified = 0;
			a.modified = 0;
			return false;
		}

	}
};

int main()
{

	Rock R;
	Papers P;
	Scissors S;
	int r, p, s;
	cout << "Enter Strength for Rock : ";
	cin >> r; cout << endl;
	cout << "Enter Strength for Papers : ";
	cin >> p; cout << endl;
	cout << " Enter Strength for Scissors : ";
	cin >> s; cout << endl;

	R.setPower(r);
	P.setPower(p);
	S.setPower(s);

	cout << "Result of Rock vs Papers : " << R.battle(P);
	cout << endl;
	cout << " Result of Rock vs Scissors : " << R.battle(S);
	cout << endl;
	cout << "Result of Papers vs Rock : " << P.battle(R);
	cout << endl;
	cout << " Result of Papers vs Scissors : " << P.battle(S);
	cout << endl;
	cout << "Result of Scissors vs Rock : " << S.battle(R);
	cout << endl;
	cout << " Result of Scissors vs Papers : " << S.battle(P);
	cout << endl;

	system("pause");
	return 0;
}
*/
//Question 7;

/*struct rational
{
	int numerator;
	int denominator;
};

void reduce(rational &num)
{
	for (int n =num.numerator; n >0; n--)
	{
		if (num.denominator%n==0 && num.numerator%n==0)
		{
			
			num.numerator = num.numerator / n;
			num.denominator = num.denominator / n;
			

		}
	}
	
}


bool isEqual(rational &num1, rational &num2)
{
	reduce(num1);
	reduce(num2);

	
	if (num1.numerator == num2.numerator && num1.denominator == num1.denominator)
		return true;
	else
		return false;
}

int main()
{
	int result;
	rational num1, num2;
	cout << "Enter Details of Number 1" << endl;
	cout << "Enter Numerator:" << endl;
	cin >> num1.numerator;
	cout << "Enter Denominator:" << endl;
	cin >> num1.denominator;
	cout << "Enter Details of Number 2" << endl;
	cout << "Enter Numerator:" << endl;
	cin >> num2.numerator;
	cout << "Enter Denominator:" << endl;
	cin >> num2.denominator;
	result = isEqual(num1, num2);
	if (result == true)
		cout << "Both rational numbers are equal" << endl;
	else
		cout << "Both rational numbers are not equal" << endl;
	system("pause");
	return 0;

}*/

//Question 8



//#include <iostream>
//#include <string>
//#include <ctime>
//
//using namespace std;
//
//class Shape
//{
//public:
//	virtual string getName() const = 0;
//	virtual double getPerimeter() const = 0;
//	virtual double getArea() const = 0;
//};
//typedef Shape* ShapePtr;
//
//class Triangle : public Shape
//{
//private:
//	double s1, s2, s3;
//public:
//	Triangle();
//	Triangle(double s1, double s2, double s3);
//	double getSide1()const;
//	double getSide2()const;
//	double getSide3()const;
//	void setSide1(const double s1);
//	void setSide2(const double s2);
//	void setSide3(const double s3);
//	virtual string getName() const;
//	virtual double getPerimeter() const;
//	virtual double getArea() const;
//	static Triangle generateRandomValidTriangle();
//};
//Triangle::Triangle()
//{
//	this->s1 = 1.0;
//	this->s2 = 1.0;
//	this->s3 = 1.0;
//}
//Triangle::Triangle(double s1, double s2, double s3)
//{
//	if (s1 > 0 && s2 > 0 && s3 > 0 && s1 + s2 > s3 && s1 + s3 > s2 && s2 + s3 > s1)
//	{
//		this->s1 = s1;
//		this->s2 = s2;
//		this->s3 = s3;
//	}
//	else
//		*this = Triangle();
//}
//double Triangle::getSide1()const
//{
//	return this->s1;
//}
//double Triangle::getSide2()const
//{
//	return this->s2;
//}
//double Triangle::getSide3()const
//{
//	return this->s3;
//}
//void Triangle::setSide1(const double x)
//{
//	if (x > 0 && x + s2 > s3 && x + s3 > s2 && s2 + s3 > x)
//		this->s1 = x;
//	else
//		return;	//Do nothing because the parameter is invalid
//}
//void Triangle::setSide2(const double x)
//{
//	if (x > 0 && s1 + x > s3 && s1 + s3 > x && x + s3 > s1)
//		this->s2 = x;
//	else
//		return;	//Do nothing because the parameter is invalid
//}
//void Triangle::setSide3(const double x)
//{
//	if (x > 0 && s1 + s2 > x && s1 + x > s2 + s2 + x > s1)
//		this->s3 = x;
//	else
//		return;	//Do nothing because the parameter is invalid
//}
//double Triangle::getPerimeter() const
//{
//	return this->s1 + this->s2 + this->s3;
//}
//string Triangle::getName() const
//{
//	return "Triangle";
//}
//double Triangle::getArea() const
//{
//	double s = (this->s1 + this->s2 + this->s3) / 2;
//	double area = sqrt(s*(s - this->s1)*(s - this->s2)*(s - this->s3));
//	return area;
//}
//Triangle Triangle::generateRandomValidTriangle()
//{
//	double a, b, c;
//	do
//	{
//		a = (1.0 * rand() / RAND_MAX) * 4.0 + 1.0;
//		b = (1.0 * rand() / RAND_MAX) * 4.0 + 1.0;
//		c = (1.0 * rand() / RAND_MAX) * 4.0 + 1.0;
//	} while (a + b <= c || a + c <= b || b + c <= a);
//	return Triangle(a, b, c);
//}
//
//class Rectangle : public Shape
//{
//private:
//	double height, width;
//
//public:
//	Rectangle();
//	Rectangle(double h, double w);
//
//	double getHeight() const;
//	double getWidth() const;
//
//	void setHeight(const double h);
//	void setWidth(const double w);
//
//	virtual string getName() const;
//	virtual double getPerimeter() const;
//	virtual double getArea() const;
//};
//Rectangle::Rectangle()
//{
//	this->height = 1.0;
//	this->width = 2.0;
//}
//Rectangle::Rectangle(double h, double w)
//{
//	if (h > 0 && w > 0)
//	{
//		this->height = h;
//		this->width = w;
//	}
//	else
//		*this = Rectangle();
//}
//double Rectangle::getHeight() const
//{
//	return this->height;
//}
//double Rectangle::getWidth() const
//{
//	return this->width;
//}
//void Rectangle::setHeight(const double h)
//{
//	if (h > 0)
//		this->height = h;
//	else
//		return;	//Do nothing because the parameter is invalid
//}
//void Rectangle::setWidth(const double w)
//{
//	if (w > 0)
//		this->width = w;
//	else
//		return;	//Do nothing because the parameter is invalid
//}
//string Rectangle::getName() const
//{
//	return "Rectangle";
//}
//double Rectangle::getPerimeter() const
//{
//	double circ;
//	circ = 2 * (this->height + this->width);
//	return circ;
//}
//double Rectangle::getArea() const
//{
//	return this->height*this->width;
//}
//
//class Circle : public Shape
//{
//private:
//	double radius;
//
//public:
//	Circle();
//	Circle(double r);
//
//	double getRadius() const;
//	void setRadius(const double r);
//
//	virtual string getName() const;
//	double getPerimeter() const;
//	virtual double getArea() const;
//};
//Circle::Circle()
//{
//	this->radius = 1.0;
//}
//Circle::Circle(double r)
//{
//	if (r > 0)
//		this->radius = r;
//	else
//		*this = Circle();
//}
//double Circle::getRadius() const
//{
//	return this->radius;
//}
//void Circle::setRadius(const double r)
//{
//	if (r > 0)
//		this->radius = r;
//	else
//		return;	//Do nothing because the parameter is invalid
//}
//string Circle::getName() const
//{
//	return "Circle";
//}
//double Circle::getPerimeter() const
//{
//	return 2 * 3.14 * this->radius;
//}
//double Circle::getArea() const
//{
//	return 3.14 * this->radius * this->radius;
//}
//
//class Node
//{
//private:
//	ShapePtr sPtr;
//	Node* link;
//public:
//	Node();
//	Node(ShapePtr sPtr, Node* link);
//	~Node();
//
//	ShapePtr getShapePtr() const;
//	Node* getLink() const;
//
//	void setShapePtr(ShapePtr sPtr);
//	void setLink(Node* link);
//};
//typedef Node* NodePtr;
//
//Node::Node()
//{
//	this->sPtr = nullptr;
//	this->link = nullptr;
//}
//Node::Node(ShapePtr sPtr, NodePtr link)
//{
//	this->sPtr = sPtr;
//	this->link = link;
//}
//Node::~Node()
//{
//	if (this->sPtr != nullptr)
//	{
//		delete this->sPtr;
//		this->sPtr = nullptr;
//	}
//	else
//		return;
//}
//ShapePtr Node::getShapePtr() const
//{
//	return this->sPtr;
//}
//NodePtr Node::getLink() const
//{
//	return this->link;
//}
//void Node::setShapePtr(ShapePtr sPtr)
//{
//	this->sPtr = sPtr;
//}
//void Node::setLink(NodePtr link)
//{
//
//	this->link = link;
//}
//
//class LinkedList
//{
//private:
//	NodePtr head;
//
//public:
//	LinkedList();
//	~LinkedList();
//	bool isEmptyLinkedList() const;
//	void printLinkedList() const;
//	void head_insert(ShapePtr sPtr);
//	void insert_grouped(ShapePtr sPtr);
//	void insert_grouped_sorted(ShapePtr sPtr);
//};
//LinkedList::LinkedList()
//{
//	this->head = nullptr;
//}
//LinkedList::~LinkedList()
//{
//	//This member function wipes out the whole Linked List
//	while (this->isEmptyLinkedList() == false)
//	{
//		//First get the pointer of the Node to be deleted
//		NodePtr temp = this->head;
//		//Advance head to the next Node
//		this->head = this->head->getLink();
//		//Delete the temp Node together with its shape object
//		delete temp;
//	}
//}
//bool LinkedList::isEmptyLinkedList() const
//{
//	if (this->head == nullptr)
//		return true;
//	else
//		return false;
//}
//
//void LinkedList::printLinkedList() const
//{
//	if (this->isEmptyLinkedList())
//	{
//		cout << "Empty Linked List" << endl << endl;
//		return;
//	}
//	else
//	{
//		NodePtr temp = head;
//		while (temp != nullptr)
//		{
//			cout << temp->getShapePtr()->getName() << ": \tPerimeter = " << temp->getShapePtr()->getPerimeter() << "\tArea = " << temp->getShapePtr()->getArea() << endl;
//			temp = temp->getLink();
//		}
//	}
//}
//
//
//void LinkedList::head_insert(ShapePtr sPtr)
//{
//	NodePtr temp = new Node();
//	temp->setShapePtr(sPtr);
//	temp->setLink(this->head);
//	this->head = temp;
//}
//
//void LinkedList::insert_grouped(ShapePtr sPtr)
//{
//	/*
//	Implement the insert_grouped member function.
//	This function must create a new Node object on the heap memory.
//	Then set the shape pointer member variable of the new Node object to the
//	shape pointer argument. Finally insert the new Node to the Linked list such
//	that same shapes are always grouped together in the Linked List. Here it does
//	not matter where you insert the new shape within the group of shapes of same type
//	*/
//	NodePtr node = new Node;
//	
//	node->setShapePtr(sPtr);
//	node->setLink(nullptr);
//	NodePtr curr=head;
//	NodePtr prev = head;
//
//	if (this->isEmptyLinkedList())
//	{
//		head = node;
//		return;
//	}
//	else
//	{
//		while (curr!= nullptr)
//		{
//			
//
//
//
//			if ((curr->getShapePtr())->getName() == sPtr->getName())
//			{
//				node->setLink(curr->getLink());
//				curr->setLink(node);
//				prev = curr;
//				curr = curr->getLink();
//				
//				return;
//
//			}
//			prev = curr;
//			curr = curr->getLink();
//
//		}
//
//		if (curr ==nullptr)
//		{
//			prev->setLink(node);
//			node->setLink(nullptr);
//		}
//		
//	}
//
//}
//
//
//
//void LinkedList::insert_grouped_sorted(ShapePtr sPtr)
//{
//		/*
//	Implement the insert_grouped_sorted member function.
//	This function must create a new 
//	Node object on the heap memory.
//	Then set the shape pointer member variable of the new Node object to the
//	shape pointer argument. Finally	insert the new Node to the Linked List such
//	that same shapes are always grouped together in the Linked List and group of
//	the same shapes are sorted in increasing order of their areas.*/
//
//	if (this->isEmptyLinkedList() == true)
//	{
//		head_insert(sPtr);
//		return;
//	}
//	else
//	{
//		string Shape = sPtr->getName();
//		double Area = sPtr->getArea();
//		NodePtr temp = this->head;
//		if ((temp->getShapePtr()->getName() == Shape) && (temp->getShapePtr()->getArea() > Area))
//		{
//			head_insert(sPtr);
//			return;
//		}
//		else
//		{
//			NodePtr n = new Node();
//			n->setShapePtr(sPtr);
//			while (temp->getLink() != nullptr)
//			{
//				if (((temp->getShapePtr()->getName() == Shape) && (temp->getLink()->getShapePtr()->getName() == Shape)) && ((temp->getShapePtr()->getArea() <= Area) && (temp->getLink()->getShapePtr()->getArea() >= Area)))
//				{
//					n->setLink(temp->getLink());
//					temp->setLink(n);
//					return;
//				}
//				else if ((temp->getShapePtr()->getName() == Shape) && (temp->getLink()->getShapePtr()->getName() != Shape) && (temp->getShapePtr()->getArea() <= Area))
//				{
//					n->setLink(temp->getLink());
//					temp->setLink(n);
//					return;
//				}
//				else if ((temp->getShapePtr()->getName() != Shape) && (temp->getLink()->getShapePtr()->getName() == Shape) && (temp->getLink()->getShapePtr()->getArea() >= Area))
//				{
//					n->setLink(temp->getLink());
//					temp->setLink(n);
//					return;
//				}
//				else if (temp->getShapePtr()->getName() == Shape&& temp->getLink() == nullptr)
//				{
//					n->setLink(nullptr);
//					temp->setLink(n);
//					return;
//				}
//				else
//				{
//					temp = temp->getLink();
//				}
//
//			}
//			n->setLink(nullptr);
//			temp->setLink(n);
//
//		}
//
//	}
//
//}



//int main()
//{
//	/*
//	Seed the random number generator with a fixed value integer, say to 2.
//	I recommend you to use the same integer in order to generate the same
//	random numbers as mine (in Visual Studio at least) so that your output
//	will have to be identical as mine. Once you are convinced your program
//	is working correctly, then you can change the fixed value 2 to time(0)
//	so as to get different random numbers every time you run your program.
//	*/
//
//	//Create an Empty Linked List
//	LinkedList L;
//
//	//Insert twenty random objects in the Linked List using head_insert member function
//	srand(2);
//	for (int i = 0; i < 20; i++)
//	{
//		int randomShape = rand() % 3;
//		if (randomShape == 0)
//		{
//			cout << "Inserting Triangle with head_insert member function." << endl;
//			Triangle t = Triangle::generateRandomValidTriangle();
//			L.head_insert(new Triangle(t.getSide1(), t.getSide2(), t.getSide3()));
//		}
//		else if (randomShape == 1)
//		{
//			cout << "Inserting Rectangle with head_insert member function." << endl;
//			double h = (1.0 * rand() / RAND_MAX) * 4.0 + 1.0;
//			double w = (1.0 * rand() / RAND_MAX) * 4.0 + 1.0;
//			L.head_insert(new Rectangle(h, w));
//		}
//		else
//		{
//			cout << "Inserting Circle with head_insert member function." << endl;
//			double r = (1.0 * rand() / RAND_MAX) * 4.0 + 1.0;
//			L.head_insert(new Circle(r));
//		}
//	}
//
//	//Print the Linked List to see we have inserted ten Nodes
//	cout << endl << "After inserting twenty nodes with head_insert member function, the Linked List is" << endl;
//	L.printLinkedList();
//
//	//Delete the Linked List
//	cout << endl << "Deleting the Linked List" << endl;
//	L.~LinkedList();
//
//	//Print the Linked List to see it is Empty Linked List
//	cout << endl << "After deleting the Linked List, the Linked List is" << endl;
//	L.printLinkedList();
//	system("Pause");
//
//	//Insert twenty random shapes using insert_grouped member function
//	//In order to get the same ten objects let us reset the random number generator
//	srand(2);
//	for (int i = 0; i < 20; i++)
//	{
//		int randomShape = rand() % 3;
//		if (randomShape == 0)
//		{
//			cout << "Inserting Triangle with insert_grouped member function." << endl;
//			Triangle t = Triangle::generateRandomValidTriangle();
//			L.insert_grouped(new Triangle(t.getSide1(), t.getSide2(), t.getSide3()));
//		}
//		else if (randomShape == 1)
//		{
//			cout << "Inserting Rectangle with insert_grouped member function." << endl;
//			double h = (1.0 * rand() / RAND_MAX) * 4.0 + 1.0;
//			double w = (1.0 * rand() / RAND_MAX) * 4.0 + 1.0;
//			L.insert_grouped(new Rectangle(h, w));
//		}
//		else
//		{
//			cout << "Inserting Circle with insert_grouped member function." << endl;
//			double r = (1.0 * rand() / RAND_MAX) * 4.0 + 1.0;
//			L.insert_grouped(new Circle(r));
//		}
//	}
//
//	//Print the Linked List to see we have inserted ten Nodes
//	cout << endl << "After inserting twenty nodes with insert_grouped member function, the Linked List is" << endl;
//	
//	L.printLinkedList();
//
//	//Delete the Linked List
//	cout << endl << "Deleting the Linked List" << endl;
//	L.~LinkedList();
//
//	//Print the Linked List to see it is Empty Linked List
//	cout << endl << "After deleting the Linked List, the Linked List is" << endl;
//	L.printLinkedList();
//	system("Pause");
//
//	//Insert twenty random shapes using insert_grouped_sorted member function
//	//In order to get the same ten objects let us reset the random number generator
//	srand(2);
//	for (int i = 0; i < 20; i++)
//	{
//		int randomShape = rand() % 3;
//		if (randomShape == 0)
//		{
//			cout << "Inserting Triangle with insert_grouped_sorted member function." << endl;
//			Triangle t = Triangle::generateRandomValidTriangle();
//			L.insert_grouped_sorted(new Triangle(t.getSide1(), t.getSide2(), t.getSide3()));
//		}
//		else if (randomShape == 1)
//		{
//			cout << "Inserting Rectangle with insert_grouped_sorted member function." << endl;
//			double h = (1.0 * rand() / RAND_MAX) * 4.0 + 1.0;
//			double w = (1.0 * rand() / RAND_MAX) * 4.0 + 1.0;
//			L.insert_grouped_sorted(new Rectangle(h, w));
//		}
//
//		else
//		{
//			cout << "Inserting Circle with insert_grouped_sorted member function." << endl;
//			double r = (1.0 * rand() / RAND_MAX) * 4.0 + 1.0;
//			L.insert_grouped_sorted(new Circle(r));
//		}
//	}
//
//	//Print the Linked List to see we have inserted ten Nodes
//	cout << endl << "After inserting twenty nodes with insert_grouped_sorted member function, the Linked List is" << endl;
//	L.printLinkedList();
//
//	//Delete the Linked List
//	cout << endl << "Deleting the Linked List" << endl;
//	L.~LinkedList();
//
//	//Print the Linked List to see it is Empty Linked List
//	cout << endl << "After deleting the Linked List, the Linked List is" << endl;
//	L.printLinkedList();
//
//	system("Pause");
//	return 0;
//}





/*Question 5*/
/*
using namespace std;

template <typename T, int length>
class SortedList
{
private:
	ostream& put(ostream& out) const;
	T list[length];
	int size;
public:
	SortedList()
	{
		size = 0;
	}
	void insert(T item);
	friend ostream& operator<<(ostream& out, const SortedList& list)
	{
		return list.put(out);
	}
};
template<typename T, int length>
void SortedList<T, length>::insert(T item)
{
	if (size == length) {
		printf("List Full"); return;
	}
	int i = size - 1;
	while (i >= 0 && item < list[i])
	{
		list[i + 1] = list[i];
		i--;
	}
	list[i + 1] = item;
	size++;
}
template<typename T, int length>
ostream& SortedList<T, length>::put(ostream& out) const
{
	for (int i = 0; i < size; i++)
		cout << list[i] << " ";
	cout << endl;
	return out;
}
/*int main()
{
	int values[] = { 5, 1, 7, 8, 11, 2 };
	SortedList<int, 10> list;
	for (int i = 0; i < 6; i++)
		list.insert(values[i]);
	cout << list;
	return 0;
}*/
//The class SortedList cannot be instantiated for any arbitrary type.For example, consider the following instantiation for a wrapper integer class.

/*
class Int
{
public:
	Int()
	{
		i = 0;
	}
	Int(int i) { this->i = i; }
	friend ostream& operator<<(ostream& out, const Int n)
	{
		cout << n.i;
		return out;
	}
	friend bool operator<(const Int n1, const Int n2)
	{
		
		return n1.i<n2.i;
	}
private:
	int i;
};

int main()
{
	Int values[] = { Int(5), Int(1), Int(7), Int(8), Int(11), Int(2) };
	SortedList<Int, 10> list;
	for (int i = 0; i < 6; i++)
		list.insert(values[i]);
	cout << list;
	return 0;
}
//Explain why the second implementation fails.What must be added to that class, so this program will compile ? Provide the correct program.
*/
