

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int maxConsecutiveOnes = 1;
        int currentCount = 1;
        for (size_t i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
            {
                currentCount++;
            }
            else
            {
                maxConsecutiveOnes = maxConsecutiveOnes < currentCount ? currentCount : maxConsecutiveOnes;
                currentCount = 1;
            }
        }
        maxConsecutiveOnes = maxConsecutiveOnes < currentCount ? currentCount : maxConsecutiveOnes;
        return maxConsecutiveOnes;
    }
};

void Run()
{
    Solution solution;
    cout << (solution.findMaxConsecutiveOnes(vector<int>{1, 1, 0, 1, 1, 1})) << endl;
}