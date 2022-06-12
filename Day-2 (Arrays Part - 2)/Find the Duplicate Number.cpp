// Problem Link - https://leetcode.com/problems/find-the-duplicate-number/

class Solution
{
public:
  int findDuplicate(vector<int> &nums)
  {
    // We make the swaps until we have found the element
    // i.e a duplicate of the current element (nums[0])

    // For example - [1, 3, 4, 2, 2]

    // 1 Iteration
    // [1, 3, 4, 2, 2]
    // nums[0] = 1 & nums[nums[0]] = 3
    // [3, 1, 4, 2, 2]

    // 2 Iteration
    // [3, 1, 4, 2, 2]
    // nums[0] = 3 & nums[nums[0]] = 2
    // [2, 1, 4, 3, 2]

    // 3 Iteration
    // [2, 1, 4, 3, 2]
    // nums[0] = 2 & nums[nums[0]] = 4
    // [4, 1, 2, 3, 2]

    // 4 Iteration
    // [4, 1, 2, 3, 2]
    // nums[0] = 4 & nums[nums[0]] = 2
    // [2, 1, 2, 3, 4]

    // 5 Iteration
    // [2, 1, 2, 3, 4]
    // nums[0] = 2 & nums[nums[0]] = 2
    // NOW, the nums[0] and nums[nums[0]] are equal,
    // Therefore, we have found the unique elements
    while (nums[0] != nums[nums[0]])
      swap(nums[0], nums[nums[0]]);

    return nums[0];
  }
};

// Time Complexity: O(N)
// Space Complexity: O(1)