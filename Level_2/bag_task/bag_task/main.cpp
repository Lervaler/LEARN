#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Things
{
    int weight = 0;
    int value = 0;
};

int main()
{
    vector<Things > things {{1, 1}, {2, 1}, {2, 4}, {1, 3}, {4, 6}, {3, 2}};
    unordered_map <int, int> bag;
    constexpr int size = 5;

    for(int i = 0; i <= size; ++i)
    {
        bag[i] = 0;
        for(auto element: things)
        {
            if(element.weight <= i)
            {
                bag[i] = max(element.value + bag[i - element.weight],
                             bag[i]);
            }
        }
    }
    cout << bag[size] << endl;
    return 0;
}
