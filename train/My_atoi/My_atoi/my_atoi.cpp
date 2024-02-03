#include "my_atoi.h"
#include <vector>
#include <limits.h>

int myAtoi(std::string s) {
  int positive = false;
  int negative = false;
  long long b  = 0;

  long long j = 1;
  int size    = 0;

  for (int i = 0; i < s.size(); ++i)
  {
    if ((s[i] == '0') || (s[i] == '+') || (s[i] == '-') || (s[i] == ' '))
    {
      ++size;
    }

    if (s[i] == '+') ++positive;

    if (s[i] == '-') ++negative;

    if ((s[i] == '+') && (i > 0) && ((std::isdigit(s[i - 1]) == true) ||
                                     (std::isdigit(s[i + 1]) ==
                                      false))) return 0;

    if ((s[i] == '-') && (i > 0) && ((std::isdigit(s[i - 1]) == true) ||
                                     (std::isdigit(s[i + 1]) ==
                                      false))) return 0;

    if ((s[i] == ' ') && (i > 0) && (std::isdigit(s[i - 1]) == true)) return 0;

    if ((isdigit(s[i]) == true) && (s[i] != '0')) break;
  }


  for (int i = s.size() - 1; i >= size;)
  {
    if (isdigit(s[i]) == true)
    {
      if ((b + (s[i] - '0') * j) >= 2147483648)
      {
        b = 2147483648;
      }
      else
      {
        b += (s[i] - '0') * j;

        if (j < 100000000000) j = j * 10;
      }
    }

    if ((s[i] == '.') && (b != 0))
    {
      b = 0;
      j = 1;
    }

    if ((isdigit(s[i]) == false)) // && (b != 0)) // && (s[i] != '.'))
    {
      b = 0;
      j = 1;
    }
    --i;
  }

  if (negative == true)
  {
    if (b >= 2147483648) b = INT_MIN;
    else b = -b;
  }

  if (negative == false)
  {
    if (b > INT_MAX) b = INT_MAX;
  }

  if ((negative == true) && (positive == true))
  {
    b = 0;
  }

  int c = static_cast<int>(b);

  return c;
}
