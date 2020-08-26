/******************************************************************
** MoveZeroes.cpp
** @Author       : BanMing 
** @Date         : 2020/8/26 下午5:12:13
** @Description  : 
*******************************************************************/

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        size_t r = nums.size() - 1;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                while (r > i)
                {
                    if (nums[r] != 0)
                    {
                        nums[i] = nums[r];
                        nums[r] = 0;
                        break;
                    }
                    else
                    {
                        r--;
                    }
                }
            }
        }
    }
};
void Run()
{
    Solution solution;
    vector<int> test = {2, 3, 0, 0, 4, 5, 0};
    solution.moveZeroes(test);
    for (size_t i = 0; i < test.size(); i++)
    {
        cout << test[i] << endl;
    }
}