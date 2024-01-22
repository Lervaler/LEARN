#include <func_3.h>
#include <vector>
#include <iostream>

std::string func_3(std::string s, int numRows)
{
  std::string answer;
  std::vector<std::string> vec(numRows, "");

  for (int i = 0; i < s.size();)
  {
    for (int j = 0; j < numRows && i != s.size();)
    {
      vec[j] += s[i];
      ++j;
      ++i;
    }

    if (numRows > 2)
    {
      for (int j = numRows - 2; j > 0 && i != s.size();)
      {
        vec[j] += s[i];
        --j;
        ++i;
      }
    }
  }

  for (auto el: vec)
  {
    answer += el;
  }

  return answer;
}
