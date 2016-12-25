#include <iostream>
#include <time.h>
#include <algorithm>
#include <vector>
#include <sstream>

#include "board.h"

using namespace std;

Board::Board(bool showSecret)
{
    int i;

    srand(time(NULL));
    
    for (i = 0; i < 4; i++) 
    {
        this->secretState[i] = rand() % 6;
    }

    this->height = 10;
    this->width = 4;
    this->showSecret = showSecret;
    this->allGuessed = false;
}

void Board::drawBoard(int currentRow)
{
    int i, j;
	int rights, almost_rights;

    this->allGuessed = false;
	if (userLines.size() > 0)
	{
		rights = almost_rights = 0;
		for (j = 0; j < 4; j++) 
		{
			if (userLines.back().getPeg(j) == this->secretState[j]) 
			{
				rights++;
			}
			else if (find(begin(this->secretState), end(this->secretState), userLines.back().getPeg(j)) != end(this->secretState))
			{
				almost_rights++;
			}
		}
		stringstream res;
		for (j = 0; j < rights; j++)
		{
			res << "B";
		}
		for (j = 0; j < almost_rights; j++)
		{
			res << "W";
		}
		for (j = 0; j < (4-(rights+almost_rights)); j++)
		{
			res << ".";
		}
		userLines.back().setResultLine(res.str());
	}

    for (UserLine i: userLines) 
    {
        cout << "---------" << endl;
        cout << i.toString() << endl;   
    }

    if (this->showSecret)
    {
        cout << "   " 
             << this->secretState[0]
             << this->secretState[1]
             << this->secretState[2]
             << this->secretState[3]
             << "   " << endl;
    }
    else
    {
        cout << "   XXXX   " << endl;
    }
	cout << "RIGHTS: " << rights << endl;
	if (rights == 4)
	{
		this->allGuessed = true;
	}
	else 
	{
		userLines.push_back(UserLine());
	}
}

void Board::placeMove(int pos, int val)
{
    this->userLines.back().setPeg(pos, val);
}

bool Board::gameOver()
{
    return this->allGuessed;
}
