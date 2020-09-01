/******************************************************************
** FindDisappearedNumbers.cpp
** @Author       : BanMing 
** @Date         : 2020/9/1 下午5:35:47
** @Description  : 
*******************************************************************/

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        // sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size(); i++)
        {
            for (size_t j = 0; j < nums.size(); j++)
            {
                if (nums[i] < nums[j])
                {
                    swap(nums[i], nums[j]);
                }
            }
        }
        vector<int> res;
        int index = 1;
        for (size_t i = 0; i < nums.size() - 1;)
        {
            if (index != nums[i])
            {
                res.push_back(index);
            }
            while (index == nums[i] && i < nums.size() - 1)
            {
                i++;
            }
            index++;
        }
        while (index <= nums.size() && nums[nums.size() - 1] != index)
        {
            res.push_back(index);
            index++;
        }
        return res;
    }
};
void Run()
{
    Solution solution;
    vector<int> test{1,1};
    auto res = solution.findDisappearedNumbers(test);
    for (size_t i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
}