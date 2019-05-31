using System;

namespace LeetCode
{
    class Program
    {
        static void Main(string[] args)
        {
            // Console.WriteLine("Hello World!");
            AddTwoNumbersSolution add = new AddTwoNumbersSolution();
            ListNode l1 = new ListNode(0);
            // l1.next = new ListNode(9);
            // l1.next.next = new ListNode(3);

            ListNode l2 = new ListNode(7);
            l2.next = new ListNode(3);
            // l2.next.next = new ListNode(4);
            add.AddTwoNumbers(l1, l2);
        }
    }
}
