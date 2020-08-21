
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        size_t count = arr.size();
        for (size_t i = 0; i < count; i++)
        {
            if (arr[i] == 0)
            {
                arr.insert(arr.begin() + i, 0);
                i++;
            }
        }
        arr.erase(arr.begin() + count, arr.end());
    }
};

void Run()
{
    Solution solution;
    vector<int> arr = {1, 0, 2, 3, 0, 4, 5, 0};
    solution.duplicateZeros(arr);
    for (size_t i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
}