#include <iostream>
#include <cstring>
using namespace std;

#include "swap.h"

bool swap_string (string s, string goal)
{
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int tmp = 0;
    int k = 0;
    bool found = false;
    int d = 0;

    for (i; i<goal.size(); ++i)
    {
        if (goal.size() == 2)
        {
            tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }

        else if (s != goal && s[i] != goal[i])
        {
            for (j; j<goal.size(); ++j)
            {
                if (s[i] != goal[i] && s[j] != goal[j] && s[i] != s[j] && goal.size() != 2)
                    {
                        tmp = s[i];
                        s[i] = s[j];
                        s[j] = tmp;
                        ++k;
                    };
            }
         }

         else if (s == goal)
         {
              if(s[i] == s[i+i+1])
              found = true;
              if (found == false && k == 0) d = 1;
         }
    }

    if (s.size() != goal.size()) return false;
    if (s.size()< 2) return false;
    if (k >1) return false;
    if (found == true) return true;
    if (s == goal && d != 1 ) return true;
    else return false;
}
