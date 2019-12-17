/*
 * @lc app=leetcode.cn id=21 lang=csharp
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 */
// public class ListNode
// {
//     public int val;
//     public ListNode next;
//     public ListNode(int x) { val = x; }
// }

// public class Solution
public class MergeTwoListsSolution
{
    public ListNode MergeTwoLists(ListNode l1, ListNode l2)
    {
        ListNode res = null;
        while (l1 != null)
        {
            if (l1.val <= l2.val)
            {
                res = l1;//new ListNode(l1.val);
                res.next = l2;
                l1 = l1.next;
            }
            else
            {
                res = l2;//new ListNode(l2.val);
                l2 = l2.next;
                res.next = l1;

            }
            res = res.next;
            if (l2 == null)
            {
                break;
            }
        }
        while (l1 != null)
        {
            res = l1;//new ListNode(l1.val);
            l1 = l1.next;
            res = res.next;
        }
        while (l2 != null)
        {
            res = l2;//new ListNode(l2.val);
            l2 = l2.next;
            res = res.next;
        }
        return res;
    }
    public void Test()
    {
        MergeTwoLists(new ListNode(1), new ListNode(0));
    }
}
// @lc code=end

