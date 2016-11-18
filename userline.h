#ifndef USERLINE
#define USERLINE

#include <iostream>

using namespace std;

class UserLine
{   
    public:
        UserLine();
        string toString();
        void setPeg(int pos, int val);
        int getPeg(int pos);
    private:
        int state[4];
};

#endif