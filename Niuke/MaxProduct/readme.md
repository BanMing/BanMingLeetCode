[网络地址](https://www.nowcoder.com/practice/5f29c72b1ae14d92b9c3fa03a037ac5f?tpId=90&tqId=30776&tPage=1&rp=1&ru=/ta/2018test&qru=/ta/2018test/question-ranking
)

题目描述:

>给定一个无序数组，包含正数、负数和0，要求从中找出3个数的乘积，使得乘积最大，要求时间复杂度：O(n)，空间复杂度：O(1)

输入描述:

>无序整数数组A[n]

输出描述:

>满足条件的最大乘积

示例:

输入

>3 4 1 2

输出

>24

解题思路：

>1.三个最大的数相乘最大

>2.两个最小的值与最大的值（最小为负数，最大为正数）

求得最大的三个数和最小的三个数，用上面两个公司计算出最大值比较，谁大就是最终结果。**值得注意的是这里需要使用long，否则会越界**
