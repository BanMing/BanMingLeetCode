/******************************************************************
** 文件名: Exchange.cpp
** 创建人: BanMing 
** 日  期: 6/7/2020, 11:34:05 PM
** 描  述:  面试题21. 调整数组顺序使奇数位于偶数前面
https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/
**************************** 修改记录 ******************************
** 修改人: 
** 日  期: 
** 描  述: 
*******************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> exchangeSelf(vector<int> &nums)
    {
        vector<int> res;
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] % 2 == 1)
            {
                int num = nums[i];
                res.push_back(num);
                nums.erase(nums.begin() + i);
            }
            else
            {
                i++;
            }
        }

        res.insert(res.end(), nums.begin(), nums.end());
        return res;
    }

    vector<int> exchange(vector<int> &nums)
    {
        int temp = 0;
        int i = 0;
        int j = nums.size()-1;
        while (i < j)
        {
           while(i<j&&(nums[i]&1)==1){i++;}
           while(i<j&&(nums[j]&1)==0){j--;}
            temp = nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
        }
        return nums;
    }

};

void Run()
{
    int testA[] = {2, 16, 3, 5, 13, 1, 16, 1, 12, 18, 11, 8, 11, 11, 5, 1};
    vector<int> test(testA, testA + 16);
    Solution solution;
    solution.exchange(test);
}