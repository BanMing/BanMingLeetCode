/*
 * @lc app=leetcode.cn id=21 lang=csharp
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
// public class Solution 
public class MergeTwoListsSolution 
{
    public ListNode MergeTwoLists(ListNode l1, ListNode l2) {
       ListNode head=new ListNode(-1);
       ListNode next=head;
        while (l1!=null&&l2!=null)
        {
           if (l1.val<l2.val)
           {
               next= l1;
               l1=l1.next;
           }else
           {
               next = l2;
               l2=l2.next;
           }
           next =next.next;
        }
next.next = l1==null ? l2:l1;
        return head.next;
    }
    public void Test()
    {
ListNode head=new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(4)
ListNode end=new ListNode(1);
end.next = new ListNode(3);
end.next.next = new ListNode(4)
MergeTwoLists(head,end);
    }
}
// @lc code=end

