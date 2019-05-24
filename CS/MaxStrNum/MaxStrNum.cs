//////////////////////////////////////////////////////////////////////////////////////////
//// MaxStrNum.cs
//// time:5/23/2019, 11:58:17 PM	
//// author:BanMing	   
//// des:https://www.nowcoder.com/practice/0f0badf5f2204a6bb968b0955a82779e?tpId=90&tqId=30777&tPage=1&rp=1&ru=/ta/2018test&qru=/ta/2018test/question-ranking
////////////////////////////////////////////////////////////////////////////////////////////
using System;
using System.Collections;
using System.Collections.Generic;

public class MaxStrNum
{
    // 两个字符串相加
    private static string strAdd(string left, string right)
    {
        var leftChars = left.ToCharArray();
        var rightChars = right.ToCharArray();
        var len = left.Length > right.Length ? left.Length : right.Length;
        for (int i = 1; i < len; i++)
        {
            var leftNum = int.Parse(leftChars[left.Length - i].ToString());
            var rightNum = int.Parse(rightChars[right.Length - i].ToString());
            // leftNum+rightNum
        }
        return "";
    }
    public static void Func(string left, string right)
    {
        var leftChars = left.ToCharArray();
        var rightChars = right.ToCharArray();
        int res = 0, num = 0;
        for (int i = right.Length - 1; i > -1; i--)
        {
            int data = 0;
            int index = 0;
            var rightNum = int.Parse(rightChars[i].ToString());
            for (int j = left.Length - 1; j > -1; j--)
            {
                // 计算出每个子位与乘数相乘所得的值
                var leftNum = int.Parse(leftChars[j].ToString());
                // 这里不能用指数计算，会越界
                data += rightNum * leftNum * (int)Math.Pow(10, index);
                // (rightNum * leftNum).ToString();
                index++;
            }
            res += data * (int)Math.Pow(10, num);
            num++;
        }


        Console.WriteLine("Res:" + res);
    }


}