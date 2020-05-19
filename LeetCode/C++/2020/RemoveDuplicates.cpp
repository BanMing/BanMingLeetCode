/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int removeDuplicates(std::vector<int> &nums)
    {
        int cout = 0;
        int len = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (i + 1 < nums.size() && nums[i] == nums[i + 1])
            {
                nums.erase(nums.begin() + i);
            }
        }
        return (int)nums.size();
    }
};
// @lc code=end
void Run()
{
    Solution solution;
    int test[] = {11, 23, 4, 44};
    vector<int> test1(test, test + 4);
    cout << solution.removeDuplicates(test1) << endl;
    for (size_t i = 0; i < test1.size(); i++)
    {
        cout << test1[i] << endl;
    }
}
