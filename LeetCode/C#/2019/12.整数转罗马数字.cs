/*
 * @lc app=leetcode.cn id=12 lang=csharp
 *
 * [12] 整数转罗马数字
 */
public class IntToRomanSolution
// public class Solution
{
    public string IntToRoman(int num)
    {
        var res = getNumStr(num);
        res = res.Replace("DCCCC", "CM");
        res = res.Replace("CCCC", "CD");
        res = res.Replace("LXXXX", "XC");
        res = res.Replace("XXXX", "XL");
        res = res.Replace("VIIII", "IX");
        res = res.Replace("IIII", "IV");
        return res;
    }
    public string getNumStr(int num)
    {
        if (num == 0)
        {
            return "";
        }
        string[] numStrs = new string[] { "I", "V", "X", "L", "C", "D", "M" };
        int[] nums = new int[] { 1, 5, 10, 50, 100, 500, 1000 };
        int leftNum = 0;
        string countStr = "";
        for (int i = 6; i >= 0; i--)
        {
            if (num / nums[i] > 0)
            {
                var count = num / nums[i];
                leftNum = num - count * nums[i];
                for (int j = 0; j < count; j++)
                {
                    countStr += numStrs[i];
                }
                break;
            }
        }
        return countStr + getNumStr(leftNum);
    }

    public void Test()
    {
        System.Console.WriteLine("3:" + IntToRoman(3));
        System.Console.WriteLine("4:" + IntToRoman(4));
        System.Console.WriteLine("9:" + IntToRoman(9));
        System.Console.WriteLine("58:" + IntToRoman(58));
        System.Console.WriteLine("1994:" + IntToRoman(1994));
    }
}

