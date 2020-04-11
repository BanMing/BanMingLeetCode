/*
 * @lc app=leetcode.cn id=26 lang=csharp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
//public class Solution 
public class RemoveDuplicatesSolution 
{
    public int RemoveDuplicates(int[] nums) {
        int count = nums.Length<2?nums.Length:0;
        int j = 1;
        int m =0;
        for (int i = 0; i < nums.Length; i++)
        {
            while (nums[m]==nums[j]&&j<nums.Length)
            {
                j++;
            }
            if (nums[m]!=nums[j]&&j<nums.Length&&i+1<nums.Length)
            {
                nums[i+1]=nums[j];
                m=j;
                j++;
                count++;
            }
        }
        return count;
    }
    public void Test ()
    {
       System.Console.WriteLine("1,1,2:"+RemoveDuplicates(new  int []{1,1,2} ));
    }
}
// @lc code=end

