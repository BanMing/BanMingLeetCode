/*
 * @lc app=leetcode.cn id=15 lang=csharp
 *
 * [15] 三数之和
 */
using System.Collections.Generic;
public class ThreeSumSolution
// public class Solution
{
    public IList<IList<int>> ThreeSum(int[] nums)
    {
        IList<IList<int>> res = new List<IList<int>>();
        List<int> numList = new List<int>(nums);

        numList.Sort();
        for (int i = 0; i < numList.Count; i++)
        {
            var target = numList[i];
            var front = i + 1;
            var back = numList.Count - 1;
            while (front < back)
            {
                int sum = numList[front] + numList[back];
                if (sum + target < 0)
                {
                    front++;
                }
                else if (sum + target > 0)
                {
                    back--;
                }
                else
                {
                    var addNums = new List<int>() { target, numList[front], numList[back] };
                    res.Add(addNums);
                    while (front < back && addNums[1] == numList[front])
                    {
                        front++;
                    }
                    while (front < back && addNums[2] == numList[back])
                    {
                        back--;
                    }
                }

            }
            // 排除后面起始数字一样的数字
            while (i + 1 < nums.Length && numList[i + 1] == numList[i])
            {
                i++;
            }
        }

        return res;
    }
    public void Test()
    {
        System.Console.WriteLine("[-1, 0, 1, 2, -1, -4]:" + ThreeSum(new int[] { -1, 0, 1, 2, -1, -4 }));
    }
}

