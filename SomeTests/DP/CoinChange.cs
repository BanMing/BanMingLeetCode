/******************************************************************
** 文件名: CoinChange.cs
** 创建人: BanMing 
** 日  期: 4/12/2020, 5:44:18 PM
** 描  述:  凑数
https://labuladong.gitbook.io/algo/di-ling-zhang-bi-du-xi-lie/dong-tai-gui-hua-xiang-jie-jin-jie

**************************** 修改记录 ******************************
** 修改人: 
** 日  期: 
** 描  述: 
*******************************************************************/

using System;
using System.Collections;
using System.Collections.Generic;

public class CoinChange
{

    /// <summary>
    /// 暴力递归
    /// </summary>
    /// <param name="conins"></param>
    /// <param name="amount"></param>
    /// <returns></returns>
    private int forceConinChange(int[] conins, int amount)
    {
        if (amount < 0)
        {
            return -1;
        }
        if (amount == 0)
        {
            return 0;
        }
        int res = int.MaxValue;
        for (int i = 0; i < conins.Length; i++)
        {
            int subproblem = forceConinChange(conins, amount - conins[i]);
            if (subproblem == -1)
            {
                continue;
            }
            res = Math.Min(subproblem + 1, res);
        }
        return res;
    }

    public static void Run()
    {
        CoinChange coinChange = new CoinChange();
        Console.WriteLine(coinChange.forceConinChange(new int[] { 1, 2, 5 }, 11));
    }

}