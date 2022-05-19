/*
Дано две строки s и goal,
верните true, если вы можете поменять местами две буквы в s, чтобы результат был равен goal,
в противном случае верните false.
Перестановка букв определяется как взятие двух индексов i и j (с нулевым индексом),
таких что i != j, и перестановка символов в s[i] и s[j].
Например, замена индексов 0 и 2 в «abcd» приводит к «cbad».

1 <= s.length      goal.length <= 20 000
s and goal состоят из строчных букв.


Input: s = "ab", goal = "ba"
Output: true

Input: s = "ab", goal = "ab"
Output: false

Input: s = "aa", goal = "aa"
Output: true

*/

#include <iostream>
#include <cstring>
using namespace std;
#include "swap.h"

int main()
{
    string s = "abc";
    string goal = "bca";
    cout << "string s =    "<< s << endl;
    cout << "string goal = "<< goal << endl;

//swap_string (s, goal);

cout << (swap_string (s, goal) ? "true" : "false") << endl;

    return 0;
}
