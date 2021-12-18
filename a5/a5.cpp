







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




	Connect4 ::Connect4()
	{
		for (int i = 1; i < 43; i++)
		{
			board.insert(pair<int, char>(i, '0'));
		}

		while (1) 
		{
			cout << "\n\t\t\t\tChoose your tile: Red or Yellow?(R/Y)";
			cin >> user_move;
			user_move = toupper(user_move);
			if (user_move != 'R' && user_move !='Y')
			{
				cout << "\nInvalid tile! Enter again";
			}
			else
			{
				break;
			}

		}
		if (user_move == 'R') {
			ai_move = 'Y';
		}
		else
		{
			ai_move = 'R';
		}
		

	}
	Connect4::Connect4( Connect4 &c)
	{
		this->board = c.board;
		this->user_move = c.user_move;
		this->ai_move = c.ai_move;

	}
	void Connect4:: drawBoard()
	{
		cout << endl;

		for (int i = 1; i < 8; i++)
		{
			cout << " \t" << i<< "\t";
		}
		cout << endl;
		for (itr = board.begin(); itr != board.end(); ++itr)
		{	
			
			if ((itr->first) % 7 == 1)
			{
				cout <<endl <<endl;
			}
			
			cout <<" \t"<<itr->second<<"\t";
		}
	}
	
	
	bool Connect4:: addColor(int col, char move)
	{
		if (col == 0)
		{
			board.find(this->find_lowest_position(7))->second = move;
		}
		
		for (int i = col+35; i > 0; i = i -7)
		{
			if (this->board.find(i)->second == '0')
			{
				board.find(i)->second = move;
				return true;
				
			}
		}
		return false;
	}
	bool Connect4:: validateMove(int u_pos)
	{	
		int pos = this->find_lowest_position(u_pos);
		if (pos == -1)
		{
			return false;
		}
		return true;
	}


	int Connect4:: find_lowest_position(int col)
	{
		for (int i = col + 35; i > 0; i = i - 7)
		{
			if (this->board.find(i)->second == '0')
			{
				return i;

			}
		}
		return -1;
	}

	int Connect4:: inputUserMove()
	{
		int pos;
		cout << "\n\n\t\t\t\t\tEnter your move : ";
		if (!(cin >> pos))
		{
			cout << "Please enter numbers only!";
			cin.clear();
			cin.ignore();
			cout << "\n\n\t\t\t\t\tEnter your move : ";
			cin >> pos;
		}
		cout << "Your Move: " << pos<<endl;
		if (!validateMove(pos) || pos >7 || pos<1)
		{
			cout << "\nWrong Move";
			return inputUserMove();
		}
		
		return pos;
	}
	int Connect4::inputComputerMove_mcts(char ai_move)
	{

		srand(time(0));
		float max_stat = -999999;
		int index = 1;



		for (int j = 1; j < 8; ++j)
		{
			float wins, loss, draws;
			wins = loss = draws = 1;
			clock_t timeStart = clock();
			int pos = this->find_lowest_position(j);

			while (pos == 0)
			{
				j++;
				pos = this->find_lowest_position(j);
			}
			for (int k = 0; k < 100; k++)
			{

				if ((clock() - timeStart) / CLOCKS_PER_SEC > 8)
				{
					cout << endl << "Time out!";
					return index;
				}

				
				Connect4 temp(*this);
				temp.addColor(j, temp.ai_move);


				while (true)
				{
					if (temp.win_check(temp.ai_move))
					{
						wins = wins + 1;
						break;
					}
					if (temp.check_draw())
					{

						draws = draws + 1;
						break;
					}
					int pos1 = temp.find_lowest_position((rand() % 7) + 1);

					while (pos1 == 0)
					{
						pos1 = temp.find_lowest_position((rand() % 7) + 1);
					}


					temp.addColor(pos1 % 7, temp.user_move);

					if (temp.win_check(temp.user_move))
					{
						loss = loss - 1;
						break;
					}
					if (temp.check_draw())
					{

						draws = draws + 1;
						break;
					}
					pos1 = temp.find_lowest_position((rand() % 7) + 1);

					while (pos1 == 0)
					{
						pos1 = temp.find_lowest_position((rand() % 7) + 1);

					}
					temp.addColor(pos1 % 7, temp.ai_move);

				}

			}

			float stat = loss + wins + draws;
			
			if (stat > (max_stat))
			{
				max_stat = stat;
				index = j;

			}
		}
		
		return index;

	}
	
	
	bool Connect4::possibleMoves()
	{
		int i;
		for (itr = board.begin(), i = 0; itr != board.end(); ++itr)
		{
			if (itr->second == '0')
			{
				return true;
			}
		}
		return false;

	}
	
	bool Connect4::check_draw()
	{
		if (this->possibleMoves())
		{
			return false;
		}
		return true;
	}

	bool Connect4:: win_check(char move)
	{
		//Right Diagnols

		for (int i = 1; i < 16; i = i + 7)
		{
			itr = board.find(i);

			for (citr = itr; citr->first < board.find(itr->first + 4)->first; citr++)
			{
				if (citr->second == move && (citr->second == board.find(citr->first + 8)->second) && (citr->second == board.find(citr->first + 16)->second) && (citr->second == board.find(citr->first + 24)->second))
				{
					return true;
				}
			}
		}


		//Left Diagnols
		for (int i = 36; i > 21; i = i - 7)
		{
			itr = board.find(i);

			for (citr = itr; citr->first < board.find(itr->first + 4)->first; citr++)
			{
				if (citr->second == move && (citr->second == board.find(citr->first - 6)->second) && (citr->second == board.find(citr->first - 12)->second) && (citr->second == board.find(citr->first - 18)->second))
				{
					return true;
				}
			}
		}

		//Columns
		for (itr = board.begin(); itr != board.find(22); ++itr)
		{
			if (itr->second == move && (itr->second == board.find(itr->first + 7)->second) && (itr->second == board.find(itr->first + 14)->second) && (itr->second == board.find(itr->first + 21)->second))
			{
				return true;
			}

		}

		//Rows

		for (int i = 1; i < 37; i = i + 7)
		{
			itr = board.find(i);

			for (citr = itr; citr->first < board.find(itr->first + 4)->first; citr++)
			{
				if (citr->second == move && (citr->second == board.find(citr->first + 1)->second) && (citr->second == board.find(citr->first + 2)->second) && (citr->second == board.find(citr->first + 3)->second))
				{
					return true;
				}
			}

		}
		return false;
	}


	int Connect4::score(char move, char oppo_move)
	{
		int score_move=0;
		int score_oppo_move = 0;

		//Right Diagnols
		for (int i = 1; i < 16; i = i + 7)
		{
			itr = board.find(i);

			for (citr = itr; citr->first < board.find(itr->first + 4)->first; citr++)
			{ 
				for (int j = 0; j < 25; j=j+8)
				{
					if (board.find(citr->first + j)->second == move)
					{
						score_move++;
					}
					if (board.find(citr->first + j)->second == oppo_move)
					{
						score_oppo_move++;
					}
				}
			}
		}


		//Left Diagnols
		for (int i = 36; i > 21; i = i - 7)
		{
			itr = board.find(i);

			for (citr = itr; citr->first < board.find(itr->first + 4)->first; citr++)
			{
				for (int j = 0; j < 19; j=j+6)
				{
					if (board.find(citr->first - j)->second == move)
					{
						score_move++;
					}
					if (board.find(citr->first - j)->second == oppo_move)
					{
						score_oppo_move++;
					}
				}
			}
		}


		//Columns
		int j = 0;
		for (itr = board.begin(); itr != board.find(22); ++itr)
		{
			for (int j = 0; j < 22; j=j+7)
			{
				if (board.find(itr->first + j)->second == move)
				{
					score_move++;
				}
				if (board.find(itr->first + j)->second == oppo_move)
				{
					score_oppo_move++;
				}
			}
		}

		//Rows

		for (int i = 1; i < 37; i = i + 7)
		{
			itr = board.find(i);

			for (citr = itr; citr->first < board.find(itr->first + 4)->first; citr++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (board.find(citr->first + j)->second == move)
					{
						score_move++;
					}
					if (board.find(citr->first + j)->second == oppo_move)
					{
						score_oppo_move++;
					}
				}
			
			}

		}
	

		return (score_move - score_oppo_move);
		

	}


	 
	void Connect4::gameplay()
	{
		
		int u_pos, ai_pos;
	
		while (true)
		{
			
			u_pos = inputUserMove();
			
			addColor(u_pos, user_move);
			
			drawBoard();
			
			
			if (win_check(user_move))
			{
				cout << "\nMCTS Won";
				break;
			}
			clock_t start, end;
			double cpu_time_used;

			start = clock();
			ai_pos = inputComputerMove_mcts(ai_move);
			end = clock();
			cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
			
			cout << "\n\nComputer moves: " << ai_pos<<endl;
			cout << "\n\nTime Used to compute move: " << cpu_time_used;
			addColor(ai_pos, ai_move);	
			drawBoard();
			if (win_check(ai_move))
			{
				cout << "\nComputer Won";
				break;
			}
			
		}

	}


	int Connect4::inputComputerMove_heuristic(char ai_move)
	{
		/*
		Choose one possible move at a time(){
		
		verify whether the move is possible
		run random playouts{
			run the move on the board and complete the game
			{
				count the wins,draws or loss
			}
		compare the score with other moves
		choose the one with the best score
			
		}
		
		
		
		
		*/





		srand(time(0));
		float max_stat = -999999999999;
		int index = 1;

		for (int j = 1; j < 8; ++j)
		{
			float score ;
			score=0;
			clock_t timeStart = clock();
			int pos = this->find_lowest_position(j);

			while (pos == -1)
			{
				j++;
				pos = this->find_lowest_position(j);
			}
			for (int k = 0; k < 25; k++)
			{

				if ((clock() - timeStart) / CLOCKS_PER_SEC > 15)
				{
					cout << endl << "Time out!";
					return index;
				}


				Connect4 temp(*this);
				temp.addColor(j, temp.ai_move);
				if (j == 0)
				{
					cout << "hey";
				}


				while (true)
				{
					if (temp.win_check(temp.ai_move))
					{
						
						break;
					}
					if (temp.check_draw())
					{

						break;
					}
					int pos1 = temp.find_lowest_position((rand() % 7) + 1);
					score = score + temp.score(temp.ai_move, temp.user_move);
					while (pos1 == 0)
					{
						pos1 = temp.find_lowest_position((rand() % 7) + 1);
					}


					temp.addColor(pos1 % 7, temp.user_move);
					score = score + temp.score(temp.ai_move, temp.user_move);

					if (temp.win_check(temp.user_move))
					{
						
						break;
					}
					if (temp.check_draw())
					{

						
						break;
					}
					pos1 = temp.find_lowest_position((rand() % 7) + 1);

					while (pos1 == 0)
					{
						pos1 = temp.find_lowest_position((rand() % 7) + 1);

					}
					temp.addColor(pos1 % 7, temp.ai_move);
					score = score + temp.score(temp.ai_move, temp.user_move);

				}

			}
		float stat = score;
		if (stat > (max_stat))
			{
				max_stat = stat;
				index = j;

			}
		}
		
		return index;
	
	}


	void Connect4::gameplay_auto()
	{
		int ai_pos1, ai_pos2;

		while (true)
		{

			ai_pos1 = inputComputerMove_mcts(user_move);
			cout << "\n\nMCTS moves: " << ai_pos1 << endl;
			addColor(ai_pos1, user_move);
			drawBoard();


			if (win_check(user_move))
			{
				cout << "\nMcts Won";
				break;
			}
			clock_t start, end;
			double cpu_time_used;

			start = clock();
			ai_pos2 = inputComputerMove_heuristic(ai_move);
			end = clock();
			cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

			cout << "\n\nH moves: " << ai_pos2 << endl;
			cout << "\n\nTime Used to compute move: " << cpu_time_used;
			addColor(ai_pos2, ai_move);
			drawBoard();
			if (win_check(ai_move))
			{
				cout << "\nHeuristic Won";
				break;
			}

			if (check_draw())
			{
				cout << "\n\nDrawn";
			}

		}
	}
	
	



















int main()
{
	cout << "\t\t\t\t\tCONNECT 4 Game\n\t\t\tTo win Connect Four you must be the first player to get four of your\n\t\t\tcolored checkers in a row either horizontally, vertically or diagonally\n";

	Connect4 c;
	c.drawBoard();
	c.gameplay();


}