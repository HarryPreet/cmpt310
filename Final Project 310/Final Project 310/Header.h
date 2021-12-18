#include "pch.h"
#include <iostream>
#include<string>
#include<map>
#include <iterator>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;



class Connect4
{
	map<int, char> board;
	map<int, char>::iterator itr, citr, s;
	char user_move, ai_move;

public:
	Connect4();
	Connect4(Connect4 &c);
	void drawBoard();
	bool addColor(int col, char move);
	bool validateMove(int u_pos);
	int find_lowest_position(int col);
	int inputUserMove();
	int inputComputerMove_mcts(char ai_move);
	bool possibleMoves();
	bool check_draw();
	bool win_check(char move);
	int score(char move, char oppo_move);
	void gameplay();
	int inputComputerMove_heuristic(char ai_move);
	void gameplay_auto();
};