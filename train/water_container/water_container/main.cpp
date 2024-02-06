#include <iostream>
#include <vector>

/*
   You are given an integer array height of length n.
   There are n vertical lines drawn such that the two endpoints of the ith line
      are (i, 0) and (i, height[i]).
   Find two lines that together with the x-axis form a container, such that the
      container contains the most water.
   Return the maximum amount of water a container can store.
   Notice that you may not slant the container.

   Constraints:
   n == height.length
   2 <= n <= 105
   0 <= height[i] <= 104
 */
int func(std::vector<int>& height) // при большом объеме time limit exeeded
{
  int a = 0;

  for (int i = 0; i < height.size() - 1; ++i)
  {
    for (int j = i + 1; j < height.size(); ++j)
    {
      if (height[i] >= height[j])
      {
        if (height[j] * (j - i) >= a) a = height[j] * (j - i);
      }

      if (height[i] < height[j])
      {
        if (height[i] * (j - i) >= a) a = height[i] * (j - i);
      }
    }
  }
  return a;
}

int maxArea(std::vector<int>& height) // рабочее решение
{
  int ans = 0;

  for (int i = 0, j = height.size() - 1; i < j || j > i;)
  {
    ans = std::max(ans, std::min(height[i], height[j]) * (j - i));

    if (height[j] > height[i]) ++i;
    else --j;
  }
  return ans;
}

int main()
{
  std::vector<int> f  = { 1, 2 };                      // 1
  std::vector<int> f1 = { 1, 8, 6, 2, 5, 4, 8, 3, 7 }; // 49
  std::vector<int> f2 = { 1, 8, 6, 2, 5, 4, 8, 3, 8 }; // 56
  std::vector<int> f3 = { 1, 2, 4, 3 };                // 4
  std::vector<int> f4 = { 2, 3, 10, 5, 7, 8, 9 };      // 36
  std::vector<int> f5 = { 2, 3, 4, 5, 18, 17, 6 };     // 17

  int s  = maxArea(f);
  int s1 = maxArea(f1);
  int s2 = maxArea(f2);
  int s3 = maxArea(f3);
  int s4 = maxArea(f4);
  int s5 = maxArea(f5);

  std::cout << s << std::endl;
  std::cout << s1 << std::endl;
  std::cout << s2 << std::endl;
  std::cout << s3 << std::endl;
  std::cout << s4 << std::endl;
  std::cout << s5 << std::endl;
  return 0;
}
