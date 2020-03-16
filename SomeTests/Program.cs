
using System;

namespace SomeTests
{
    class Program
    {
        enum Color
        {
            Red = 1,
            Blue = 2,
            Yellow = 3,
            Green = 4
        }
        static void Main(string[] args)
        {
            // Console.WriteLine("Hello World!");
            // var obj = new DPTest();
            // obj.Test();
            // Color color = Color.Red | Color.Blue | Color.Yellow | Color.Green;
            // Color color1 = Color.Red | Color.Blue | Color.Yellow;
            // Color color2 = Color.Blue | Color.Yellow | Color.Red;
            // Color color3 = Color.Red & Color.Blue & Color.Yellow & Color.Green;
            // Console.WriteLine("Color:" + color);
            // Console.WriteLine("Color1:" + color1);
            // Console.WriteLine("Color2:" + color2);
            // Console.WriteLine("Color3:" + color3);
            // Console.WriteLine(string.Format("->{0,-4}-<:444", "iji"));
            // Console.WriteLine(string.Format("->{0,10}<-", "Hello"));
            // Console.WriteLine(string.Format("->{0,-10}<-", "Hello"));
            // Console.WriteLine("".CompareTo(""));
            // Console.WriteLine("".CompareTo("1"));
            // Console.WriteLine("2".CompareTo("1"));
            // Console.WriteLine("2".CompareTo("2"));
            // Console.WriteLine(2.644.ToString("F0"));
            // Console.WriteLine(2.344.ToString("p"));
            // Console.WriteLine(2.344.ToString("F2"));
            bool isReward = false;
            string blockid = "ss";
            Console.WriteLine(string.Format("{{\"reward\":{0},\"blockId\":{1}}}", isReward, blockid));
        }
    }
}
