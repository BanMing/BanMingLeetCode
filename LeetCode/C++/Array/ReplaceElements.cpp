/******************************************************************
** ReplaceElements.cpp
** @Author       : BanMing 
** @Date         : 2020/8/25 下午2:08:28
** @Description  : 
*******************************************************************/

#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution
{
public:
    int findMaxNum(const vector<int> &arr, int begin)
    {
        int maxNum = 0;
        for (size_t i = begin; i < arr.size(); i++)
        {
            maxNum = maxNum < arr[i] ? arr[i] : maxNum;
        }
        return maxNum;
    }

    vector<int> replaceElementsSelf(vector<int> &arr)
    {
        vector<int> res(arr.size());
        if (arr.size() == 1)
        {
            res[0] = -1;
            return res;
        }

        int curMaxNum = findMaxNum(arr, 1);
        for (size_t i = 0; i < arr.size(); i++)
        {
            if (i + 1 == arr.size())
            {
                curMaxNum = -1;
            }

            if (curMaxNum == arr[i])
            {
                curMaxNum = findMaxNum(arr, i + 1);
            }
            res[i] = curMaxNum;
        }
        return res;
    }
    vector<int> replaceElements(vector<int> &arr)
    {
        int l = arr.size();
        int maxNum = arr[l - 1];
        arr[l - 1] = -1;
        for (int i = l - 2; i > -1; i--)
        {
            int temp = arr[i];
            arr[i] = maxNum;
            maxNum = maxNum > temp ? maxNum : temp;
        }
        return arr;
    }
};
void Run()
{

    Solution solution;
    vector<int> testArr = {17, 18, 5, 4, 6, 1};
    vector<int> ans = solution.replaceElements(testArr);
    for (size_t i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}