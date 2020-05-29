
using System;

namespace SomeTests
{
    class Program
    {
        enum SSSS
        {
            A,
            B,
            C
        }

        static void Main(string[] args)
        {
            // Bag01.Run();
            SSSS s = SSSS.A | SSSS.B;
            SSSS m = SSSS.A & SSSS.B & SSSS.C;
            // SSSS m = SSSS.A | SSSS.B | SSSS.C;
            SSSS a = SSSS.A;
            if (s == a)
            {
                Console.WriteLine("@@@@@@@@@@");
            }
            if ((s & SSSS.B) != 0)
            {
                Console.WriteLine("%##########");
            }
            if (m.HasFlag(SSSS.C))
            {
                Console.WriteLine("C##########");
            }

            Console.WriteLine("s:" + s.ToString() + " a:" + a.ToString() + " m:" + m.ToString());
        }
    }
}
