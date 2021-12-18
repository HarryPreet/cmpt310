#include"pch.h"
#include "Scanner.h"
#include "Stack.h"  // GENERIC STACK

#include <iostream>
using namespace std;



int main () {
    Scanner S(cin);
    Token t,temp;

    Stack<Token> numstack, opstack;  // 2x Stacks of type Token
    

    t = S.getnext();

    // pretty printer coding demo.  please remove before coding
	while (t.tt != eof||opstack.isEmpty()==false) {
		if (t.tt == integer)
			numstack.push(t);
		else if (t.tt == lptok)
		{
			

			opstack.push(t);
		}
		else if(t.tt==rptok)
		{
			if (opstack.peek().tt == lptok)
				opstack.pop();
			else
			{
				string op=(opstack.pop()).text;
				if (op== "+")
				{
					t.val = (numstack.pop()).val + (numstack.pop()).val;
					numstack.push(t);
					cout << endl;
					cout << numstack.peek().val;
				}
				else if (op == "-")
				{
					int later = (numstack.pop()).val;
					t.val = ((numstack.pop()).val -later);
					numstack.push(t);
					cout << endl;
					cout << numstack.peek().val;
				}
				else if (op == "*")
				{
					t.val = (numstack.pop()).val * (numstack.pop()).val;
					numstack.push(t);
					cout << endl;
					cout << numstack.peek().val;
				}
				if (op == "/")
				{
					int later = (numstack.pop()).val;
					t.val = ((numstack.pop()).val / later);
					numstack.push(t);
					cout << endl;
					cout << numstack.peek().val;
				}
			}
		}

		else if (t.tt == pltok || t.tt == mitok || t.tt == eof)
		{
			if (opstack.isEmpty() == false && ((opstack.peek()).tt == pltok || (opstack.peek()).tt == mitok || (opstack.peek()).tt == asttok || (opstack.peek()).tt == slashtok))
			{
				string op = (opstack.pop()).text;
				if (op == "+")
				{
					t.val = (numstack.pop()).val + (numstack.pop()).val;
					numstack.push(t);
					cout << endl;
					cout << numstack.peek().val;
				}
				else if (op == "-")
				{
					int later = (numstack.pop()).val;
					t.val = ((numstack.pop()).val - later);
					numstack.push(t);
					cout << endl;
					cout << numstack.peek().val;
				}
				else if (op == "*")
				{
					t.val = (numstack.pop()).val * (numstack.pop()).val;
					numstack.push(t);
					cout << endl;
					cout << numstack.peek().val;
				}
				if (op == "/")
				{
					int later = (numstack.pop()).val;
					t.val = ((numstack.pop()).val / later);
					numstack.push(t);
					cout << endl;
					cout << numstack.peek().val;
				}
			}
			else
				opstack.push(t);
		}
		else if (t.tt == asttok || t.tt == slashtok)
		{
			if((opstack.isEmpty()==false )&& ((opstack.peek()).tt == pltok || (opstack.peek()).tt == mitok || (opstack.peek()).tt == asttok || (opstack.peek()).tt == slashtok))
			{
				string op = (opstack.pop()).text;
				if (op == "+")
				{
					t.val = (numstack.pop()).val + (numstack.pop()).val;
					numstack.push(t);
					cout << endl;
					cout << numstack.peek().val;
				}
				else if (op == "-")
				{
					int later = (numstack.pop()).val;
					t.val = ((numstack.pop()).val -later);
					numstack.push(t);
					cout << endl;
					cout << numstack.peek().val;
				}
				else if (op == "*")
				{
					t.val = (numstack.pop()).val * (numstack.pop()).val;
					numstack.push(t);
					cout << endl;
					cout << numstack.peek().val;
				}
				if (op == "/")
				{
					int later = (numstack.pop()).val;
					t.val = ((numstack.pop()).val / later);
					numstack.push(t);
					cout << endl;
					cout << numstack.peek().val;
				}
			}
			else
				opstack.push(t);
		
		}

		
        t = S.getnext();
    }
	

   
    // end pretty printer

    return 0;
}

