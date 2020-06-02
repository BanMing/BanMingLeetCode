/******************************************************************
** 文件名: HammingWeight.cs.cpp
** 创建人: BanMing 
** 日  期: 6/2/2020, 9:49:50 PM
** 描  述:  

**************************** 修改记录 ******************************
** 修改人: 
** 日  期: 
** 描  述: 
*******************************************************************/
#include <iostream>
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int res = 0;
        while (n != 0)
        {
            if ((n & 1) == 1)
            {
                res++;
            }
            n = n >> 1;
        }
        return res;
    }
};

void Run()
{
    Solution solution;
    // printf("n = 11111111111111111111111111111101 x = %d \n", solution.hammingWeight(11111111111111111111111111111101));
    printf("n = 00000000000000000000000000001011 x = %d \n", solution.hammingWeight(00000000000000000000000000001011));
}