//////////////////////////////////////////////////////////////////////////////////////////
//// Six_One.cs
//// time:5/24/2019, 9:40:12 PM	
//// author:BanMing	   
//// des:https://www.nowcoder.com/practice/d2dfc62bf1ba42679a0e358c57da9828?tpId=90&tqId=30778&tPage=1&rp=1&ru=/ta/2018test&qru=/ta/2018test/question-ranking
////////////////////////////////////////////////////////////////////////////////////////////
using System;
using System.Collections;
using System.Collections.Generic;

public class Six_One
{


    public static void Func(int[] h, int[] w, int hCount, int wCount)
    {
        List<int> H = new List<int>(h);
        List<int> W = new List<int>(w);
        H.Sort();
        W.Sort();
        int count = 0;
        int j = 0;
        for (int i = 0; i < hCount; i++)
        {
            for (; j < wCount; j++)
            {
                if (W[j] >= H[i])
                {
                    count++;
                    j++;
                    break;
                }
            }
        }
        Console.WriteLine("count:" + count);
    }


}