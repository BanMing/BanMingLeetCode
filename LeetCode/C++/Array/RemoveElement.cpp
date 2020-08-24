/******************************************************************
** 文件名: RemoveElement.cpp
** 创建人: BanMing
** 日  期: 8/23/2020, 4:42:05 PM
** 描  述:

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
    int removeElement(vector<int>& nums, int val) {
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] == val)
            {
                nums.erase(nums.begin() + i);
                i--;
            }
        }
        return nums.size();
    }
};

void Run() {

}
