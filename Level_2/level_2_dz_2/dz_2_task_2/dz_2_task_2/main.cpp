#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector<int> result;
    vector<int> nums = {1,3, 1,2,2,7};

    int a = 0;
    int b = 0;
    int c = 0;

    for (int i = 0; i <nums.size(); ++i)
    {
        a = a^nums[i];
    }
     for (int i = 0; i <nums.size(); ++i)
    {
     b = a^nums[i];
    }

    for (int i = 0; i <nums.size(); ++i)
    {
         if (nums [i] == b)
         {
            nums.erase(nums.begin()+i); break;
         }
     }

   for (int i = 0; i <nums.size(); ++i)
    {
        c = c^nums[i];
    }

    result.push_back(b);
    result.push_back(c);

 //   cout << a << endl;
    cout <<"FIRST ELEM = "<< b << endl;
    cout <<"SECOND ELEM = "<< c << endl;
    cout <<"RESULT = " <<result[0] << " "<< result[1] << " "<< endl;

    return 0;
}
