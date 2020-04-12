/******************************************************************
** 文件名: Fib.cs
** 创建人: BanMing 
** 日  期: 4/12/2020, 4:52:53 PM
** 描  述:  斐波拉数

**************************** 修改记录 ******************************
** 修改人: 
** 日  期: 
** 描  述: 
*******************************************************************/

using System;
using System.Collections;
using System.Collections.Generic;

public class Fib
{

    /// <summary>
    /// 普通递归算法
    /// 时间复杂度O(2^n)
    /// </summary>
    /// <param name="N"></param>
    /// <returns></returns>
    private int normalRecursive(int N)
    {
        if (N == 2 || N == 1)
        {
            return N;
        }

        return normalRecursive(N - 1) + normalRecursive(N - 2);
    }


    /// <summary>
    /// 备忘录暴力
    /// 时间复杂度为O(n)
    /// </summary>
    /// <param name="N"></param>
    /// <returns></returns>
    private int memoCalendarFib(int N)
    {
        Dictionary<int, int> memo = new Dictionary<int, int>();

        return helperFunc(N, ref memo);
    }

    /// <summary>
    /// 自底向上求解
    /// 时间复杂度O(n)
    /// </summary>
    /// <param name="N"></param>
    /// <returns></returns>
    private int memoCalendarFibLoop(int N)
    {
        Dictionary<int, int> memo = new Dictionary<int, int>();
        memo.Add(1, 1);
        memo.Add(2, 2);
        for (int i = 3; i <= N; i++)
        {
            memo.Add(i, memo[i - 1] + memo[i - 2]);
        }
        return memo[N];
    }

    private int helperFunc(int N, ref Dictionary<int, int> memo)
    {

        if (memo.ContainsKey(N))
        {
            return memo[N];
        }
        if (N == 1 || N == 2)
        {
            memo.Add(N, N);
            return N;
        }
        memo.Add(N, helperFunc(N - 1, ref memo) + helperFunc(N - 2, ref memo));
        return memo[N];
    }


    /// <summary>
    /// 时间复杂度O(n)
    /// 空间复杂的O(1)
    /// </summary>
    /// <param name="N"></param>
    /// <returns></returns>
    private int bestFib(int N)
    {
        if (N == 1 || N == 2)
        {
            return N;
        }
        int pre = 1;
        int res = 2;
        for (int i = 3; i <= N; i++)
        {
            int temp = res;
            res = pre + res;
            pre = temp;
        }
        return res;
    }
    public static void Run()
    {
        Fib fib = new Fib();
        Console.WriteLine(fib.normalRecursive(5));
        Console.WriteLine(fib.memoCalendarFib(5));
        Console.WriteLine(fib.memoCalendarFibLoop(5));
        Console.WriteLine(fib.bestFib(5));
    }
}