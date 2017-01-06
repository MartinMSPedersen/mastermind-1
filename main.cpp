#include <iostream>

#include "board.h" 

using namespace std;

int main()
{
    int gameCounter = 0;
    int val = -1;
    int i;

    //Initialize the game and print welcome message for user

    cout << "******************" << endl
         << "*   Welcome to   *" << endl
         << "*  Master  mind  *" << endl
         << "******************" << endl;

    cout << endl
         << "You must enter your guess a peg at the time" << endl
         << "Use the numbers 0-5 to indicate your guess"
         << endl;

    Board b(false);


    //The game loop
    while (gameCounter < 10 && !b.gameOver())
    {
        cout << "ROUND: " << (gameCounter+1) << endl;
        b.drawBoard();
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

    //Final message for the user
    if (gameCounter < 10) 
    {
        cout << "You won" << endl;
    } 
    else if (gameCounter >= 10 && !b.gameOver())
    {
        cout << "You lost" << endl;
        cout << "The secret was: " << b.getSecretState() << endl;
    }
    else if (gameCounter >= 10)
    {
        cout << "You won" << endl;
    }

    return 0;
}
