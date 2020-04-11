/*
 * @lc app=leetcode.cn id=121 lang=csharp
 *
 * [121] 买卖股票的最佳时机
 */
// public class Solution
public class MaxProfitSolution
{
    // 动态规划
    public int MaxProfitDP(int[] prices)
    {
        if (prices.Length < 2)
        {
            return 0;
        }
        var f = new int[prices.Length];
        f[0] = 0;
        int max = 0;
        for (int i = 1; i < prices.Length; i++)
        {
            f[i] = 0;
            for (int j = 0; j < i; j++)
            {
                if (prices[i] - prices[j] > 0)
                {
                    f[i] = System.Math.Max(prices[i] - prices[j], f[i]);
                }
            }
            max = System.Math.Max(max, f[i]);
            // System.Console.WriteLine($"f[{i}]={f[i]}");
        }
        return max;
    }
    // 求出最小价格
    // 与每天价格相减
    // 以此求出最大利润
    public int MaxProfit(int[] prices)
    {
        int minPrice = int.MaxValue;
        int maxPro = 0;
        for (int i = 0; i < prices.Length; i++)
        {
            minPrice = System.Math.Min(minPrice, prices[i]);
            maxPro = System.Math.Max(prices[i] - minPrice, maxPro);
        }
        return maxPro;
    }
    public void Test()
    {
        // System.Console.WriteLine("7,1,5,3,6,4:" + MaxProfit(new int[] { 7, 1, 5, 3, 6, 4 }));
        System.Console.WriteLine("7,6,4,3,1:" + MaxProfit(new int[] { 7, 6, 4, 3, 1 }));
    }
}

