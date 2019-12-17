using System;

namespace Offer
{
    class Program
    {
        static void Main(string[] args)
        {
            // Console.WriteLine("Hello World!");x
            Console.WriteLine(RepeatNum.Test(new int[] { 2, 3, 1, 0, 2, 5, 3 }));
            int a = 0;
            RepeatNum.Best(new int[] { 2, 3, 1, 0, 2, 5, 3 }, ref a);
            Console.WriteLine($"{a}");
        }
    }
}
