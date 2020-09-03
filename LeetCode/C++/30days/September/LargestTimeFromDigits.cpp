/******************************************************************
** LargestTimeFromDigits.cpp
** @Author       : BanMing 
** @Date         : 2020/9/2 上午10:00:43
** @Description  : 
*******************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    string largestTimeFromDigits(vector<int> &A)
    {
        sort(A.begin(), A.end());

        string res = "";
        do
        {
            if ((A[0] == 2 && A[1] <= 3 || A[0] < 2) && A[2] < 6)
            {
                string temp = to_string(A[0]) + to_string(A[1]) + to_string(A[2]) + to_string(A[3]);
                if (temp > res)
                {
                    res = temp;
                }
            }

        } while (next_permutation(A.begin(), A.end()));
        if (!res.empty())
        {
            res.insert(res.begin() + 2, ':');
        }

        return res;
    }
};
void Run()
{

    Solution solution;
    vector<int> test{4,1,0,0};
    string res = solution.largestTimeFromDigits(test);
    cout << res << endl;
}