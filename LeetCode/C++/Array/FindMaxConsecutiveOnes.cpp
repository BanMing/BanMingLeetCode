

// https://leetcode.com/explore/featured/card/fun-with-arrays/521/introduction/3238/

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int maxConsecutiveOnes = 0;
        int currentCount = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                currentCount++;
            }
            else
            {
                maxConsecutiveOnes = maxConsecutiveOnes < currentCount ? currentCount : maxConsecutiveOnes;
                currentCount = 0;
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

#pragma region 讲解
// 这个还是英文不好，看成最大连续数
#pragma endregion