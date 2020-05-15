using System;

namespace Offer
{
    class Program
    {
        static void Main(string[] args)
        {
            // Console.WriteLine("Hello World!");x
            // Console.WriteLine(RepeatNum.Test(new int[] { 2, 3, 1, 0, 2, 5, 3 }));
            // int a = 0;
            // RepeatNum.Best(new int[] { 2, 3, 1, 0, 2, 5, 3 }, ref a);
            // Console.WriteLine($"{a}");
            bool isHas = ArrayTest.FindNumIn2Array(new int[4][] { new int[] { 1, 2, 8, 9 }, new int[] { 2, 4, 9, 12 }, new int[] { 4, 7, 10, 13 }, new int[] { 6, 8, 11, 15 } }, 6);
            Console.WriteLine($"{isHas}");
        }
    }
}
