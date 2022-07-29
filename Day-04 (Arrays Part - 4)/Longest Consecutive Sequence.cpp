// Problem Link - https://leetcode.com/problems/longest-consecutive-sequence/

class Solution
{
public:
  int longestConsecutive(vector<int> &nums)
  {
    if (nums.size() <= 1)
      return nums.size();

    // Removing the duplicates ans sorting the nums array
    set<int> s;

    for (int num : nums)
      s.insert(num);

    nums.assign(s.begin(), s.end());

    // Initializing variables len and ans with 1 because minimum length of the sequence could be 1 i.e a single number and ans will be atleast 1, if not zero :p
    int len = 1, ans = 1;

    for (int i = 1; i < nums.size(); i++)
    {
      if (nums[i] == nums[i - 1] + 1)
        len++;
      else
        len = 1;

      ans = max(len, ans);
    }

    return ans;
  }
};

// Time Complexity - O(N * log(N))
// Space Complexity - O(N)