#include <iostream>
#include <vector>
#include <string>

#include <func_3.h>

int main()
{
  int numRows   = 3;
  std::string s = "PAYPALISHIRING";

  std::string answ = func_3(s,  numRows);
  std::cout << answ << std::endl;

  return 0;
}

// func_3 is working
