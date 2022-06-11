// Problem Link - https://leetcode.com/problems/sort-colors/

class Solution
{
public:
  void sortColors(vector<int> &nums)
  {
    // lo  is responsible for the handling of the 0s
    // mid is responsible for the handling of the 1s
    // hi  is responsible for the handling of the 2s

    // For example,
    // Initialization is as follows -
    // 2 0 2 1 1 0
    // l -> (lo)
    // m -> (mid)
    //           h -> (hi)
    int lo = 0, mid = 0, hi = nums.size() - 1;

    while (mid <= hi)
    {
      // If the mid element is 0,
      // then we swap the lo and mid elements
      // because lo is responsible for the 0s.
      if (nums[mid] == 0)
        swap(nums[lo++], nums[mid++]);

      // mid will be incremented as the number is already 1
      else if (nums[mid] == 1)
        mid++;

      // If the mid element is 2,
      // then we swap the hi and mid elements
      // because hi is responsible for the 2s.
      else
        swap(nums[mid], nums[hi--]);
    }
  }
};

// Time Complexity - O(n)
// Space Complexity - O(1)