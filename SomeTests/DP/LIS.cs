/******************************************************************
** 文件名: LIS.cs
** 创建人: BanMing 
** 日  期: 4/13/2020, 10:01:21 PM
** 描  述:  

**************************** 修改记录 ******************************
** 修改人: 
** 日  期: 
** 描  述: 
*******************************************************************/

using System;
using System.Collections;
using System.Collections.Generic;

public class LIS
{

    private int dpTable(int[] arrary)
    {

        if (arrary.Length < 2)
        {
            return arrary.Length;
        }
        Dictionary<int, int> dp = new Dictionary<int, int>();
        dp[1] = 1;
        for (int i = 2; i < arrary.Length; i++)
        {
            if (arrary[i] >= arrary[i - 1])
            {
                dp[i] = dp[i - 1] + 1;
            }
            else
            {
                dp[i] = dp[i - 1];
            }
        }
        return dp[arrary.Length - 1];

    }

    public static void Run()
    {
        LIS lIS = new LIS();
        Console.WriteLine(lIS.dpTable(new int[] { 10, 9, 2, 5, 3, 7, 101, 18 }));
    }

}