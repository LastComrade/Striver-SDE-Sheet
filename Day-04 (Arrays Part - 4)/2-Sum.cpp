// Problem Link - https://leetcode.com/problems/two-sum/

class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    map<int, int> mp;

    for (int i = 0; i < nums.size(); i++)
    {
      // If the curr element does not exist in the array
      if (mp.find(nums[i]) == mp.end())
        mp[nums[i]] = i; // mp[2] = 0

      // 9 - 2 = 7
      // mp[7] = ?
      // No - continue
      // Yes - return the indexes
      if (mp.find(target - nums[i]) != mp.end() &&
          i != mp[target - nums[i]])
        return {i, mp[target - nums[i]]};
    }

    return {-1, -1};
  }
};

// Time Complexity - O(n)
// Space Complexity - O(n)