#include <iostream>
#include <sstream>

#include "userline.h"

using namespace std;

UserLine::UserLine() 
{
    int i;

    for (i = 0; i < 4; i++) 
    {
        state[i] = -1;
    }
    result = "....";
}

string UserLine::toString()
{
    int i;
    stringstream res;
    res << result;
    res << " ";
    for (i = 0; i < 4; i++)
    {
        if (state[i] == -1)
        {
            res << ".";
        }
        else
        {
            res << to_string(state[i]);
        }
    }
    return res.str();
}

void UserLine::setPeg(int pos, int val)
{
    state[pos] = val;
}

int UserLine::getPeg(int pos)
{
    return state[pos];
}

void UserLine::setResultLine(string resultLine)
{
    result = resultLine;
}
