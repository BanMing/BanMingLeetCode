//////////////////////////////////////////////////////////////////////////////////////////
//// MaxProduct.cs
//// time:5/22/2019, 1:45:11 PM	
//// author:BanMing	   
///  url:https://www.nowcoder.com/practice/5f29c72b1ae14d92b9c3fa03a037ac5f?tpId=90&tqId=30776&tPage=1&rp=1&ru=/ta/2018test&qru=/ta/2018test/question-ranking
////////////////////////////////////////////////////////////////////////////////////////////
using System;
using System.Collections;
using System.Collections.Generic;

public class MaxProduct
{
    // 这里用int可能会越界
    public static void Func(long[] arr)
    {
        long max1 = long.MinValue;
        long max2 = long.MinValue;
        long max3 = long.MinValue;
        long min1 = long.MaxValue;
        long min2 = long.MaxValue;
        long min3 = long.MaxValue;

        for (int i = 0; i < arr.Length; i++)
        {
            if (arr[i] > max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = arr[i];
            }
            else if (arr[i] > max2)
            {
                max3 = max2;
                max2 = arr[i];
            }
            else if (arr[i] > max3)
            {
                max3 = arr[i];
            }
            if (arr[i] < min1)
            {
                min3 = min2;
                min2 = min1;
                min1 = arr[i];
            }
            else if (arr[i] < min2)
            {
                min3 = min2;
                min2 = arr[i];
            }
            else if (arr[i] < max3)
            {
                min3 = arr[i];
            }
        }
        var max = max1 * max2 * max3;
        if (min1 != int.MaxValue && min2 != int.MaxValue)
        {
            max = max1 * min1 * min2 < max ? max : max1 * min1 * min2;
        }
        Console.WriteLine("max:" + max);
    }

}