// Problem Link - https://leetcode.com/problems/longest-consecutive-sequence/

class Solution
{
public:
  int longestConsecutive(vector<int> &nums)
  {
    if (nums.size() <= 1)
      return nums.size();

    // Removing the duplicates ans sorting the nums array
    unordered_set<int> numSet;

    for (int num : nums)
      numSet.insert(num);

    nums.assign(numSet.begin(), numSet.end());

    // Initializing variables len and ans with 1 because minimum length of the
    // sequence could be 1 i.e a single number and ans will be atleast 1,
    // if not zero :p
    int len = 1, ans = 0;

    for (int i = 0; i < nums.size(); i++)
    {
      if (numSet.find(nums[i] - 1) == numSet.end())
      {
        int currNum = nums[i];
        len = 1;

        while (numSet.find(currNum + 1) != numSet.end())
        {
          currNum += 1;
          len++;
        }

        ans = max(len, ans);
      }
    }

    return ans;
  }
};

// Time Complexity - O(N)
// Space Complexity - O(N)