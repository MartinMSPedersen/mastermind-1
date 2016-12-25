#include <iostream>

#include "board.h" 

using namespace std;

int main(int argc, char** argv)
{
    int gameCounter = 0;
    int pos = 0;
    int val = -1;
    int i;

    cout << "******************" << endl
         << "*   Welcome to   *" << endl
         << "*  Master  mind  *" << endl
         << "******************" << endl;

    cout << endl
         << "You must enter your guess a peg at the time" << endl
         << "Use the numbers 0-5 to indicate your guess"
         << endl;

    Board b(true);

    while (gameCounter < 10 && !b.gameOver())
    {
        cout << "ROUND: " << gameCounter << endl;
        b.drawBoard(gameCounter);
        if (b.gameOver())
        {
            break;
        }

        for (i = 0; i < 4; i++) 
        {
            cout << "Peg for pos " << i << endl;
            cin >> val;
            b.placeMove(i, val);
        }
        gameCounter++;
    }

    if (gameCounter < 10) 
    {
        cout << "You won" << endl;
    }

	if (gameCounter >= 10 && !b.gameOver())
	{
		cout << "You lost" << endl;
	}
	else if (gameCounter >= 10)
	{
		cout << "You won" << endl;
	}

    return 0;
}
