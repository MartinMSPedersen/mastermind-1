#ifndef BOARD
#define BOARD

#include <vector>
#include "userline.h"

using namespace std;

class Board
{
    public:
        void drawBoard(int currentRow);
        Board(bool showSecret);
        void placeMove(int pos, int val);
        bool gameOver();

    private:
        int secretState[4];
		vector<UserLine> userLines;

        int height;
        int width;
        bool showSecret;

        bool allGuessed;
};

#endif
