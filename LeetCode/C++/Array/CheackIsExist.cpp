
#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        map<int, bool> doubleNumMap;
        for (size_t i = 0; i < arr.size(); i++)
        {
            if (doubleNumMap[arr[i]] == true)
            {
                return true;
            }

            if (arr[i] % 2 == 0)
            {
                doubleNumMap[arr[i] / 2] = true;
            }
            doubleNumMap[2 * arr[i]] = true;
        }
        return false;
    }
};
void Run() {}