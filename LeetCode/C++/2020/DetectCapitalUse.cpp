// https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3409/
#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        if (word.empty())
        {
            return false;
        }
        // 65-90
        // cout << word[0] << (int)word[0] << endl;
        int firstIndex = (int)word[0];
        bool isFirstUpper = firstIndex >= 65 && firstIndex <= 90;
        bool isLower = true;
        bool isUpper = true;
        for (size_t i = 1; i < word.size(); i++)
        {
            int index = (int)word[i];
            isLower = isLower && index >= 97 && index <= 122;
            isUpper = isUpper && index >= 65 && index <= 90;
            // cout << word[i] << (int)word[i] << endl;
        }

        return (isFirstUpper && (isLower || isUpper)) || ((!isFirstUpper) && isLower);
    }
};

void Run()
{
    Solution solution;
    cout << solution.detectCapitalUse("USA") << endl;
    cout << solution.detectCapitalUse("FlaG") << endl;
    cout << solution.detectCapitalUse("leetcode") << endl;
}