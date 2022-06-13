// Problem Link - https://leetcode.com/problems/powx-n/

class Solution
{
public:
  double myPow(double x, int n)
  {
    if (n == 0)
      return 1;

    if (n == INT_MIN)
    {
      x = x * x;
      n /= 2;
    }

    if (n < 0)
    {
      n = -1 * n;
      x = 1 / x;
    }

    return (n % 2 == 0) ? myPow(x * x, n / 2) : x * myPow(x * x, n / 2);
  }
};

// Time Complexity - O(log(N))
// Space Complexity - O(1)