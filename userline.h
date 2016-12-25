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
		void setResultLine(string resultLine);
    private:
        int state[4];
		string result;
};

#endif
