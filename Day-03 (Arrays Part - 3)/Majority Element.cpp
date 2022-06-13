// Problem Link - https://leetcode.com/problems/majority-element/

class Solution
{
public:
  int majorityElement(vector<int> &nums)
  {
    unordered_map<int, int> mp;
    int ans = 0;

    for (int itt : nums)
    {
      mp[itt]++;
      if (mp[itt] > nums.size() / 2)
        return itt;
    }

    return -1;
  }
};

// Time Complexity - O(N)
// Space Complexity - O(N)