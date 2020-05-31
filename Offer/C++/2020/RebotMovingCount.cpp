#include <iostream>
#include <vector>
class Solution
{
public:
    int sumAdd(int i)
    {
        int b = i / 100;
        int s = (i - b * 100) / 10;
        int g = i % 10;
        return b + s + g;
    }

    int movingCountSelf(int m, int n, int k)
    {
        std::vector<int> res(m > n ? m : n);

        if (n < 1 || m < 1 || k < 1)
        {
            return 1;
        }
        std::vector<std::vector<bool> > dp(m, std::vector<bool>(n));

        dp[0][0] = 0 <= k;
        dp[0][1] = 1 <= k;
        dp[1][0] = 1 <= k;
        int count = (0 <= k ? 1 : 0) + (1 <= k ? 2 : 0);
        for (size_t i = 1; i < m; i++)
        {
            for (size_t j = 1; j < n; j++)
            {
                if (res[i] == 0)
                {
                    res[i] = sumAdd(i);
                    /* code */
                }
                if (res[j] == 0)
                {
                    res[i] = sumAdd(j);
                    /* code */
                }

                dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]) && (res[i] + res[i] <= k);
                if (dp[i][j])
                {
                    count++;
                }
            }
        }
        return count;
    }

    std::vector<std::vector<bool> > visted;
    int n, m, k;
    int movingCount(int m, int n, int k)
    {
        this->n = n;
        this->m = m;
        this->k = k;
        std::vector<std::vector<bool> > vist(n, std::vector<bool>(m));
        visted = vist;
        // dfs(m, n, k)
        return dfs(0, 0);
    }

    int dfs(int i, int j)
    {
        if (i < 0 || j < 0 || m <= j || n <= i || sumAdd(i) + sumAdd(j) > k || visted[i][j])
        {
            return 0;
        }
        visted[i][j] = true;
        int left = dfs(i, j + 1);
        int up = dfs(i + 1, j);
        return left + up + 1;
    }
};

void Run()
{
    //     ：m = 2, n = 3, k = 1
    // 输出：3
    // 输入：m = 3, n = 1, k = 0
    // 输出：1
    Solution solution;
    // printf("m = 2, n = 3, k = 1 ,res = %d \n", solution.movingCount(2, 3, 1));
    // printf("m = 3, n = 1, k = 0 ,res = %d \n", solution.movingCount(3, 1, 0));
    printf("m = 1, n = 2, k = 1 ,res = %d \n", solution.movingCount(1, 2, 1));
    // solution.sum(123);
    // solution.sum(12);
}