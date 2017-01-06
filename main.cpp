#include <iostream>
#include <cstdlib>

#include "board.h" 

using namespace std;

int main()
{
    int gameCounter = 0;
    string user_input;
    int i;

    //Initialize the game and print welcome message for user

    cout << "******************" << endl
         << "*   Welcome to   *" << endl
         << "*  Master  mind  *" << endl
         << "******************" << endl;

    cout << endl
         << "You must enter your guess as a number with the four pegs" << endl
         << "Use the numbers 0-5. Example 1234 or 0231" << endl;

    Board b(false);


    //The game loop
    while (gameCounter < 10 && !b.gameOver())
    {
        cout << endl << "ROUND: " << (gameCounter+1) << endl;
        b.drawBoard();
        if (b.gameOver())
        {
            break;
        }

        cout << endl << "Enter guess: ";
        cin >> user_input;

        if (user_input.length() != 4) 
        {
            cout << "Guess must be 4 long" << endl;
            continue;
        }
        else
        {
            for (i = 0; i < 4; i++) 
            {
                int tmp = user_input.at(i)-'0';
                b.placeMove(i, tmp);
            }
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
