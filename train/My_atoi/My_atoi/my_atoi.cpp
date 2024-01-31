#include "my_atoi.h"
#include <vector>
#include <limits.h>

int myAtoi(std::string s) {
  std::vector<int> v;
  bool sign = false;

  for (auto el: s)
  {
    if ((isdigit(el) == false) && (el != ' ') && (el != '-') && (el != '+'))
    {
      break;
    }

    if (isdigit(el) != false)
    {
      v.push_back(el - '0');
    }

    if ((el == '-') || (el != '+'))
    {
      if (el == '-')
      {
        sign = true;
      }
    }
  }

  if (v.empty()) return 0;


  long long zeros = 1;
  long answer     = 0;

  for (int i = 0; i < v.size() - 1; ++i) zeros = zeros * 10;

  for (int i = 0; i < v.size(); ++i)
  {
    if (v[i] * zeros >= INT_MAX)
    {
      answer = INT_MAX;
      break;
    }
    answer += v[i] * zeros;
    zeros   = zeros / 10;
  }

  if (sign == true)
  {
    if (answer == INT_MAX) answer = -INT_MAX - 1;
    answer = -answer;
  }

  return answer;
}
