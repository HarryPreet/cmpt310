#include"pch.h"
#include<iostream>
#include "Header.h"


using namespace std;




int main()
{
	cout << "\t\t\t\t\tCONNECT 4 Game\n\t\t\tTo win Connect Four you must be the first player to get four of your\n\t\t\tcolored checkers in a row either horizontally, vertically or diagonally\n";

	Connect4 c;
	c.drawBoard();
	c.gameplay();


}