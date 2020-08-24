/******************************************************************
** 文件名: RemoveDuplicates.cpp
** 创建人: BanMing
** 日  期: 8/24/2020, 11:58:38 PM
** 描  述:

**************************** 修改记录 ******************************
** 修改人:
** 日  期:
** 描  述:
*******************************************************************/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (size_t i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
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
