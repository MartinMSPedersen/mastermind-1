#ifndef BOARD
#define BOARD

#include "userline.h"

class Board
{
    public:
        void drawBoard(int currentRow);
        Board(bool showSecret);
        void placeMove(int row, int pos, int val);
        bool gameOver();

    private:
        int secretState[4];
        UserLine userLines[10];

        int height;
        int width;
        bool showSecret;

        bool allGuessed;
};

#endif