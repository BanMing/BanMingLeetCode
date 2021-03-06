/*
 * @lc app=leetcode.cn id=2 lang=csharp
 *
 * [2] 两数相加
 */
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
// public class ListNode
// {
//     public int val;
//     public ListNode next;
//     public ListNode(int x) { val = x; }
// }
namespace In2019
{
    public class AddTwoNumbersSolution
    // public class Solution
    {
        // 莽夫法
        // public ListNode AddTwoNumbers(ListNode l1, ListNode l2)
        // {
        //     var l3 = new ListNode((l1.val + l2.val) % 10);

        //     var tempL3 = l3;

        //     var templ1 = l1.next;
        //     var templ2 = l2.next;
        //     var isAdd = l1.val + l2.val >= 10;
        //     while (templ1 != null && templ2 != null)
        //     {
        //         var addNum = (templ1.val + templ2.val + (isAdd ? 1 : 0));
        //         tempL3 = tempL3.next = new ListNode(addNum % 10);
        //         isAdd = false;
        //         isAdd = addNum >= 10;
        //         templ1 = templ1.next;
        //         templ2 = templ2.next;
        //     }
        //     while (templ1 != null)
        //     {
        //         var addNum = templ1.val + (isAdd ? 1 : 0);
        //         tempL3 = tempL3.next = new ListNode(addNum % 10);
        //         isAdd = false;
        //         isAdd = (addNum) >= 10;
        //         templ1 = templ1.next;
        //     }
        //     while (templ2 != null)
        //     {
        //         var addNum = templ2.val + (isAdd ? 1 : 0);
        //         tempL3 = tempL3.next = new ListNode(addNum % 10);
        //         isAdd = false;
        //         isAdd = (addNum) >= 10;
        //         templ2 = templ2.next;
        //     }
        //     if (isAdd)
        //     {
        //         tempL3 = tempL3.next = new ListNode(1);
        //     }
        //     return l3;
        // }
        public ListNode AddTwoNumbers(ListNode l1, ListNode l2)
        {
            var headNode = new ListNode(0);
            var currentNode = headNode;

            var x = l1;
            var y = l2;
            var carry = 0;

            while (x != null || y != null)
            {
                int a = (x != null) ? x.val : 0;
                int b = (y != null) ? y.val : 0;

                var sum = carry + a + b;
                carry = sum / 10;
                currentNode = currentNode.next = new ListNode(sum % 10);

                if (x != null) { x = x.next; }
                if (y != null) { y = y.next; }
            }

            // Check if there is still a value to carry over after finishing the loop
            if (carry == 1)
            { currentNode.next = new ListNode(1); }

            return headNode.next;
        }
    }
}

