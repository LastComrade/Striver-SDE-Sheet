// Problem Link - https://leetcode.com/problems/next-permutation/

class Solution
{
public:
  void nextPermutation(vector<int> &nums)
  {
    int i = nums.size() - 2;

    // Get the i pointer to point on the element,
    // which is disturbing the sequence from the end of the array
    // For example,
    // 1. 1 2 3
    //      i

    // 2. 1 1 5
    //    0 1 2
    //      i

    // 3.   3 2 1
    //   -1 0 1 2
    //    i (-1)
    while (i >= 0 && nums[i] >= nums[i + 1])
      i--;

    // So if we have a valid element, we will execute the below code
    if (i >= 0)
    {
      // Start our pointer from the last element of the array
      int j = nums.size() - 1;

      // We look for the element that is strictly greater,
      // than the element pointed by the ith pointer.
      while (nums[j] <= nums[i])
        j--;

      // Then we swap the ith and jth element
      // 1 1 5
      //   i j
      // After swapping
      // 1 5 1
      //   j i
      swap(nums[i], nums[j]);
    }

    // Then we reverse the remaining (i + 1)th numbers
    // Covering the edge case -> [1, 3, 2]
    // Here the first and last element needs to be swapped
    // i.e - [2, 3, 1]
    // BUT the next lexicographically greatest permutation
    // should be [2, 1, 3]
    // Therefore, we reverse the remaining (i + 1)th elements
    reverse(nums.begin() + i + 1, nums.end());
  }
};

// Time Complexity - O(n)
// Space Complexity - O(1)