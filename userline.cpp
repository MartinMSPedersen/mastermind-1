#include <iostream>
#include <sstream>

#include "userline.h"

using namespace std;

UserLine::UserLine() 
{
    int i;

    for (i = 0; i < 4; i++) 
    {
        this->state[i] = -1;
    }
}

string UserLine::toString()
{
    int i;
    stringstream res;

    for (i = 0; i < 4; i++)
    {
        if (this->state[i] == -1)
        {
            res << ".";
        }
        else
        {
            res << to_string(this->state[i]);
        }
    }
    return res.str();
}

void UserLine::setPeg(int pos, int val)
{
    this->state[pos] = val;
}

int UserLine::getPeg(int pos)
{
    return this->state[pos];
}