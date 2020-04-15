/******************************************************************
** 文件名:  Bag0-1.cs
** 创建人:  BanMing 
** 日  期:  4/15/2020, 7:54:41 PM
** 描  述:  https://labuladong.gitbook.io/algo/dong-tai-gui-hua-xi-lie/bei-bao-wen-ti

**************************** 修改记录 ******************************
** 修改人: 
** 日  期: 
** 描  述: 
*******************************************************************/

public class Bag01
{

    //错误点：这个是不可重复的
    public int GetMaxValue(int W, int[] w, int[] v)
    {
        int[] dp = new int[W + 1];
        dp[0] = 0;
        for (int i = 1; i <= W; i++)
        {
            int max = dp[i - 1];
            for (int j = 0; j < w.Length; j++)
            {
                if (i - w[j] >= 0 && i + w[j] <= W)
                {
                    max = System.Math.Max(dp[i - w[j]] + v[j], max);
                }
            }
            dp[i] = max;
        }
        return dp[W];
    }

    //标答 
    private int GetMaxValueAns(int N, int W, int[] wt, int[] val)
    {
        int[][] dp = new int[N + 1][];
        dp[0] = new int[W + 1];
        //  状态1 取前几个数存放
        for (int i = 1; i <= N; i++)
        {
            dp[i] = new int[W + 1];
            // 状态2 当前是多大的背包大小
            for (int j = 1; j <= W; j++)
            {
                // 选择 是否要放入背包
                if (j - wt[i - 1] < 0)
                {
                    // 不放入的话，就以当前个数减一，背包可放j重量下的值
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    // 放入的话，就需要找前一个个数并且把当前背包容量减去当前放入的重量
                    // 这里需要与前一个个数，背包重量为j的取最大值
                    
                    dp[i][j] = System.Math.Max(dp[i - 1][j - wt[i - 1]] + val[i - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[N][W];
    }
    public static void Run()
    {
        Bag01 bag = new Bag01();
        System.Console.WriteLine(bag.GetMaxValue(4, new int[] { 2, 1, 3 }, new int[] { 4, 2, 3 }));
        System.Console.WriteLine(bag.GetMaxValueAns(3, 4, new int[] { 2, 1, 3 }, new int[] { 4, 2, 3 }));
    }
}