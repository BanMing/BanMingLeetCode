
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        vector<int> pows{10, 100, 1000, 10000, 100000};
        int res = 0;
        for (size_t m = 0; m < nums.size(); m++)
        {
            for (size_t i = 0; i < pows.size(); i++)
            {
                if (nums[m] < pows[i])
                {
                    res += ((i + 1) % 2 == 0) ? 1 : 0;
                    break;
                }
                if (nums[m] == 100000)
                {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};

void Run()
{

    Solution solution;
    cout << solution.findNumbers(vector<int>{100000}) << endl;
}