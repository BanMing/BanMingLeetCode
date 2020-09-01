/******************************************************************
** ThirdMax.cpp
** @Author       : BanMing 
** @Date         : 2020/9/1 下午4:30:29
** @Description  : 
*******************************************************************/

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        vector<long> res(3, LONG_MIN);
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (res[0] < nums[i])
            {
                res[2] = res[1];
                res[1] = res[0];
                res[0] = nums[i];
            }
            else if (res[1] < nums[i])
            {
                res[2] = res[1];
                res[1] = nums[i];
            }
            else if (res[2] < nums[i])
            {
                res[2] = nums[i];
            }
        }
        for (size_t i = 0; i < res.size(); i++)
        {
            cout << res[i] << endl;
        }
        return res[2] == LONG_MIN ? res[0] : res[2];
    }
};
void Run()
{
    Solution solution;
    vector<int> test{2, 2, 2, 1};
    int res = solution.thirdMax(test);
    cout << "max : " << res << endl;
}