#include <Subsets.h>
#include <bitset>

/*
   Given an integer array nums of unique elements, return all possible  subsets
      (the power set).
   The solution set must not contain duplicate subsets. Return the solution in
      any order.

   Example 1:
   Input: nums = [1,2,3]
   Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

   Example 2:

   Input: nums = [0]
   Output: [[],[0]]
 */
std::vector<std::vector<int> >subsets(std::vector<int>& nums)
{
  std::vector<std::vector<int> > v;
  std::vector<int> temp;
  v.push_back(temp);

  if (nums.size() == 1)
  {
    v.push_back(nums);
    return v;
  }

  std::bitset<10> b;
  b.reset();

  for (int i = 0; i < nums.size(); ++i)
  {
    b.set(i, true);
  }
  int d = 0;

  for (int i = 0; i < b.count(); ++i)
  {
    d = (d << 1) ^  b[i];
  }

  while (d)
  {
    for (int j = 0; j < nums.size(); ++j)
    {
      if (b[j] == 1)
      {
        temp.push_back(nums[j]);
      }
    }
    b.reset();
    d -= 1;
    std::bitset<10> c(d);
    b = c ^ b;
    v.push_back(temp);
    temp.clear();
  }

  return v;
}
