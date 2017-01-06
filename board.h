#ifndef BOARD
#define BOARD

#include <vector>
#include "userline.h"

using namespace std;

class Board
{
    public:
        void drawBoard();
        Board(bool showSecret);
        void placeMove(int pos, int val);
        bool gameOver();
        string getSecretState();

    private:
        int secretState[4];
        vector<UserLine> userLines;

        bool showSecret;

        bool allGuessed;
};

#endif
