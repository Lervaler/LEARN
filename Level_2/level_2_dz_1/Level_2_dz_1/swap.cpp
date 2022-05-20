#include <iostream>
#include <cstring>
using namespace std;

#include "swap.h"

bool swap_string (string s, string goal)
{
    bool found = false;
    string s_temp;
    string g_temp;

    if (s.size() != goal.size()) return false;
    if (goal.size() >20001) return false;

    if (s == goal)
    {
        for (unsigned long long int i = 0; i<s.size(); ++i)
        {
            if (found == true) break;
            for (unsigned long long int j = i; j < goal.size(); ++j)
            {
                if(s[i] == s[j+1])
                found = true;
            }
        }
    }

    if (s != goal)
    {
        for (unsigned int i = 0; i<goal.size(); ++i)
        {
            if(s[i] != goal[i])
            {
                 s_temp.push_back(s[i]);
                 g_temp.push_back(goal[i]);
            }
            if (s_temp.size() > 2) found = false;
            if (s_temp [0] == g_temp[1] && s_temp [1] == g_temp[0] && s_temp.size() == 2 ) found = true;
         }
     }
    return found;
}
