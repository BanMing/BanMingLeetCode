/******************************************************************
** ContainsNearbyAlmostDuplicate.cpp
** @Author       : BanMing 
** @Date         : 2020/9/3 上午9:30:02
** @Description  : 
*******************************************************************/

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {

        if (nums.empty())
        {
            return false;
        }
        
        for (size_t i = 0; i < nums.size() - 1; i++)
        {
            for (size_t j = i + 1; j < nums.size(); j++)
            {
                int subVal = abs(nums[i] - nums[j]);
                size_t subIndex = (j - i);
                if (subVal <= t && subIndex <= k)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
void Run()
{
    Solution solution;
    vector<int> nums{};
    bool res = solution.containsNearbyAlmostDuplicate(nums, 0, 0);
    cout << res << endl;
}