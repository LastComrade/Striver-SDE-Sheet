// Problem Link - https://leetcode.com/problems/merge-sorted-array/

class Solution
{
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
  {
    int a = m - 1, b = n - 1, c = n + m - 1;
    // 1 2 3 0 0 0  2 5 6
    //     a     c      b

    // We start filling the element from the last of the first array
    while (a >= 0 && b >= 0)
    {
      // 1. When last element of nums2 is greater
      // 2. When last element of nums1 is greater or equal
      if (nums1[a] < nums2[b])
      {
        nums1[c] = nums2[b];
        b--;
      }
      else
      {
        nums1[c] = nums1[a];
        a--;
      }
      c--;
    }

    while (b >= 0)
    {
      nums1[c] = nums2[b];
      c--;
      b--;
    }
  }
};

// Time Complexity: O(M + N)
// Space Complexity: O(1)