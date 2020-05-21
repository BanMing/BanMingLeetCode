/* 


替换空格
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

 

示例 1：

输入：s = "We are happy."
输出："We%20are%20happy."
 

限制：

0 <= s 的长度 <= 10000
 */

#include <iostream>
using namespace std;
class Solution
{
public:
    string replaceSpace(string s)
    {
        if (s.empty())
        {
            return s;
        }

        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                s[i] = '%';
                s.insert(i + 1, "20");
            }
        }
        return s;
    }
};

void Run()
{
    Solution solution;
    cout << solution.replaceSpace("We are happy.") << endl;
}