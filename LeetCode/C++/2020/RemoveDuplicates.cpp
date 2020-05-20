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
        int index = 0;
        while (index + 1 < nums.size())
        {
            if (nums[index] == nums[index + 1])
            {
                nums.erase(nums.begin() + index);
            }
            else
            {
                index++;
            }
        }

        return (int)nums.size();
    }
};
// @lc code=end
void Run()
{
    Solution solution;
    int test[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    vector<int> test1(test, test + 10);
    printf("left count %d \n", solution.removeDuplicates(test1));
    // cout << "left count:" + solution.removeDuplicates(test1) << endl;
    for (size_t i = 0; i < test1.size(); i++)
    {
        cout << test1[i] << endl;
    }
}
