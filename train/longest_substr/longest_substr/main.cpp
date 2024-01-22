#include <iostream>
#include <string>
#include <unordered_map>

/*
 * Given a string s, find the length of the longest substring
   without repeating characters.

   Example 1:
   Input: s = "abcabcbb"
   Output: 3
   Explanation: The answer is "abc", with the length of 3.
 */
int func(std::string s)
{
  std::unordered_map<char, int> m;
  int count      = 0;
  int best_count = 0;
  int inner_i    = 0;

  for (int i = 0; i < s.size();)
  {
    if (m[s[i]] == 0)
    {
      ++m[s[i]];
      ++count;
      ++i;

      if (count > best_count) best_count = count;
    }
    else {
      count = 0;
      ++inner_i;
      i = inner_i;
      m.clear();
    }
  }
  return best_count;
}

int main()
{
  std::string s = "abcabcbb";

  int answer = func(s);
  std::cout << answer << std::endl;
  return 0;
}
