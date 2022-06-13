// Problem Link - https://leetcode.com/problems/maximum-subarray/

class Solution
{
public:
  int maxSubArray(vector<int> &nums)
  {
    int curr = nums[0], ans = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
      // Variable to store the current contigous sum of elements
      // There are two cases i.e
      // 1. Current element will added to the contigous subarray sum
      // 2. OR the subarray sum is resetted to the current element
      curr = max(curr + nums[i], nums[i]);

      // We pick the maximum subarray sum
      ans = max(ans, curr);
    }

    return ans;
  }
};

// Time Complexity - O(n)
// Space Complexity - O(1)