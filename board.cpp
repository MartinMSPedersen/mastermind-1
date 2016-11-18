#include <iostream>
#include <time.h>
#include <algorithm>

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

    this->allGuessed = true;

    for (i = 0; i < this->height; i++) 
    {
        cout << "---------" << endl;
        for (j = 0; j < 4; j++) 
        {
            if (this->userLines[i].getPeg(j) == this->secretState[j]) 
            {
                cout << "B";
            }
            else if (find(begin(this->secretState), end(this->secretState), this->userLines[i].getPeg(j)) != end(this->secretState))
            {
                cout << "W";

                //Only update the allGuessed by looking of correctness of the last row
                if (i == currentRow-1 || i == 0)
                    this->allGuessed = false;
            }
            else
            {
                cout << ".";
                if (i == currentRow-1 || i == 0)
                    this->allGuessed = false;
            }
        }
        cout << " "; 
        cout << this->userLines[i].toString() << endl;   
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
}

void Board::placeMove(int row, int pos, int val)
{
    this->userLines[row].setPeg(pos, val);
}

bool Board::gameOver()
{
    return this->allGuessed;
}