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
        secretState[i] = rand() % 6;
    }

    height = 10;
    width = 4;
    showSecret = showSecret;
    allGuessed = false;
}

void Board::drawBoard(int currentRow)
{
    int i, j;
	int rights, almost_rights;

    allGuessed = false;
	if (userLines.size() > 0)
	{
		rights = almost_rights = 0;
		for (j = 0; j < 4; j++) 
		{
			if (userLines.back().getPeg(j) == secretState[j]) 
			{
				rights++;
			}
			else if (find(begin(secretState), end(secretState), userLines.back().getPeg(j)) != end(secretState))
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
	cout << "---------" << endl;

    if (showSecret)
    {
        cout << "   " 
             << secretState[0]
             << secretState[1]
             << secretState[2]
             << secretState[3]
             << "   " << endl;
    }
    else
    {
        cout << "   XXXX   " << endl;
    }
	cout << "RIGHTS: " << rights << endl;
	if (rights == 4)
	{
		allGuessed = true;
	}
	else 
	{
		userLines.push_back(UserLine());
	}
}

void Board::placeMove(int pos, int val)
{
    userLines.back().setPeg(pos, val);
}

bool Board::gameOver()
{
    return allGuessed;
}
