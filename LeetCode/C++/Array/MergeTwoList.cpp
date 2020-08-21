
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int l = n + m;
        int index1 = m - 1;
        int index2 = n - 1;
        size_t p = 0;
        for (size_t i = l - 1; i >= 0; i--)
        {
            if (index2 < 0 || index1 < 0)
            {
                p = i;
                break;
            }

            if (nums1[index1] > nums2[index2])
            {
                nums1[i] = nums1[index1];
                index1--;
            }
            else
            {
                nums1[i] = nums2[index2];
                index2--;
            }
        }
        if (p >= 0)
        {
            while (index2 >= 0)
            {
                nums1[p] = nums2[index2];
                p--;
                index2--;
            }
        }
    }
};

void Run()
{
    Solution solution;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {4, 5, 6};

    solution.merge(nums1, 3, nums2, 3);
    for (size_t i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << endl;
    }
}