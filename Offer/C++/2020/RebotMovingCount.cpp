#include <iostream>
#include <vector>
class Solution
{
public:
    int movingCount(int m, int n, int k)
    {
        std::vector<int> res(k);

        if (n < 2 || m < 2 || k < 1)
        {
            return 1;
        }
        std::vector<std::vector<bool>> dp(m, std::vector<bool>(n));

        dp[0][0] = 0 <= k;
        dp[0][1] = 1 <= k;
        dp[1][0] = 1 <= k;
        int count = (0 <= k ? 1 : 0) + (1 <= k ? 2 : 0);
        for (size_t i = 1; i < m; i++)
        {
            for (size_t j = 1; j < n; j++)
            {
                dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]) && (i + j <= k);
                if (dp[i][j])
                {
                    count++;
                }
            }
        }
        return count;
    }
};

void Run()
{
    //     ：m = 2, n = 3, k = 1
    // 输出：3
    // 输入：m = 3, n = 1, k = 0
    // 输出：1
    Solution solution;
    printf("m = 2, n = 3, k = 1 ,res = %d \n", solution.movingCount(2, 3, 1));
    printf("m = 3, n = 1, k = 0 ,res = %d \n", solution.movingCount(3, 1, 0));
}