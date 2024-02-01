#include "my_atoi.h"
#include <vector>
#include <limits.h>

int myAtoi(std::string s) {
  std::vector<long long> v;
  long long answer = 0;
  int positive     = false;
  int negative     = false;

  for (int i = 0; i < s.size();)
  {
    if ((s[i] == ' ') || (s[i] == '+') || (s[i] == '-') ||
        (isdigit(s[i]) == true))
    {
      if (s[i] == '+') ++positive;

      if (s[i] == '-') ++negative;

      if ((isdigit(s[i]) == true) && (s[i] != '0')) answer += (s[i] - '0');

      if ((isdigit(s[i]) == true) && (s[i] == '0') &&
          !v.empty()) v.push_back(s[i] - '0');

      if ((s[i] == '0') && (isdigit(s[i + 1]) == false)) break;

      ++i;
    }
    else break;
  }

  // if (v.empty()) return 0;
  //
  //
  // long long zeros  = 1;
  //
  //
  // for (int i = 0; i < v.size() - 1; ++i) zeros = zeros * 10;
  //
  // for (int i = 0; i < v.size(); ++i)
  // {
  //   if (answer * zeros >= 2147483648)
  //   {
  //     if (negative == true)
  //     {
  //       answer = INT_MIN;
  //       break;
  //     }
  //     else
  //     {
  //       answer = INT_MAX;
  //       break;
  //     }
  //   }
  //   answer += v[i] * zeros;
  //   zeros   = zeros / 10;
  // }
  //
  if ((negative == true) && (answer != INT_MIN))
  {
    answer = -answer;
  }

  if ((negative == true) && (positive == true))
  {
    answer = 0;
  }

  return answer;
}
