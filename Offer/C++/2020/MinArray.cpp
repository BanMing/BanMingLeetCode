/******************************************************************
** 文件名: MinArray.cpp
** 创建人: BanMing 
** 日  期: 5/27/2020, 8:18:28 AM
** 描  述:  

**************************** 修改记录 ******************************
** 修改人: 
** 日  期: 
** 描  述: 
*******************************************************************/
#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    int minArray(vector<int> &numbers)
    {
        if (numbers.empty())
        {
            return 0;
        }

        queue<int> temp;
        int startIndex = 0;
        int minVal = numbers[0];
        temp.push(numbers[0]);
        for (size_t i = 1; i < numbers.size(); i++)
        {
            if (numbers[i] >= numbers[i - 1])
            {
                temp.push(numbers[i]);
            }
            else
            {
                startIndex = i;
                minVal = numbers[i];
                break;
            }
        }

        if (startIndex != 0)
        {
            numbers.erase(numbers.begin(), numbers.begin() + startIndex);
        }
        else
        {

            numbers.clear();
        }

        while (!temp.empty())
        {
            numbers.push_back(temp.front());
            temp.pop();
        }
        return minVal;
    }
};

void Run()
{
    int test[] = {3, 4, 5, 1, 2};
    Solution solution;
    vector<int> test1(test, test + 5);
    printf("%d \n", solution.minArray(test1));
    for (size_t i = 0; i < test1.size(); i++)
    {
        printf("%d ", test1[i]);
    }
    printf("\n");
}