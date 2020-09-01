/******************************************************************
** HeightChecker.cpp
** @Author       : BanMing 
** @Date         : 2020/9/1 下午2:38:30
** @Description  : 
*******************************************************************/

#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        int res = 0;
        vector<int> sortHeights(heights.begin(), heights.end());
        // sort(sortHeights.begin(), sortHeights.end());
        for (size_t i = 0; i < heights.size(); i++)
        {
            if (heights[i] != sortHeights[i])
            {
                res++;
            }
        }
        return res;
    }
    int heightCheckerSelf(vector<int> &heights)
    {
        int res = 0;
        map<int, bool> memoryMap;
        int curSwap = 200;
        size_t index = 0;

        for (size_t i = 0; i < heights.size(); i++)
        {
            for (size_t j = i; j < heights.size(); j++)
            {
                if (heights[i] > heights[j] && curSwap >= heights[j])
                {
                    index = j;
                    curSwap = curSwap > heights[j] ? heights[j] : curSwap;
                }
            }
            if (curSwap != 200)
            {
                std::swap(heights[i], heights[index]);
                curSwap = 200;

                memoryMap[heights[i]] = true;
                memoryMap[heights[index]] = true;
            }
        }

        for (auto &&i : memoryMap)
        {
            cout << "map:" << i.first << endl;
            if (i.second)
            {
                res++;
            }
        }

        return res;
    }
};
void Run()
{

    Solution solution;
    vector<int> test{56, 2, 3, 4, 53};
    int count = solution.heightChecker(test);
    cout << count << endl;

    for (size_t i = 0; i < test.size(); i++)
    {
        cout << test[i] << endl;
    }
}