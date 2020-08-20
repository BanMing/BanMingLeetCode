
#include <iostream>
#include <vector>
class Solution
{
public:
    std::vector<int> sortedSquaresSlef(std::vector<int> &A)
    {
        int negativeCount = 0;
        for (size_t i = 0; i < A.size(); i++)
        {
            if (A[i] < 0)
            {
                negativeCount++;
                int num = -A[i];
                size_t n = i + 1;
                while (n < A.size() && num > A[n])
                {
                    n++;
                }
                A.insert(A.begin() + n, num);
            }
            else
            {
                break;
            }
        }

        while (negativeCount > 0)
        {
            A.erase(A.begin());
            negativeCount--;
        }

        for (size_t i = 0; i < A.size(); i++)
        {
            A[i] = A[i] * A[i];
        }
        return A;
    }

    std::vector<int> sortedSquares(std::vector<int> &A)
    {
        int negativeCount = 0;
        for (size_t i = 0; i < A.size(); i++)
        {
            if (A[i] < 0)
            {
                negativeCount++;
            }
            else
            {
                break;
            }
        }

        int l = 0;
        size_t r = A.size() - 1;
        size_t p = A.size() - 1;
        std::vector<int> res(A.size());
        while (r > l)
        {
            int a = A[l] * A[l];
            int b = A[r] * A[r];
            if (a > b)
            {
                res[p] = a;
                l++;
            }
            else
            {
                res[p] = b;
                r--;
            }
            p--;
        }
        return res;
    }
};

void Run()
{
    Solution solution;
    std::vector<int> res = solution.sortedSquares(std::vector<int>{-4, -1, 0, 3, 10});
    for (size_t i = 0; i < res.size(); i++)
    {
        std::cout << res[i] << std::endl;
    }
}