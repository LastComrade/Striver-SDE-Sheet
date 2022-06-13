// Problem Link - https://leetcode.com/problems/majority-element-ii/

class Solution
{
public:
  vector<int> majorityElement(vector<int> &nums)
  {
    unordered_map<int, int> freq;
    int check = nums.size() / 3;
    vector<int> ans;

    for (int num : nums)
    {
      if (freq[num] != -1)
        freq[num]++;

      if (freq[num] > check)
      {
        freq[num] = -1;
        ans.push_back(num);
      }
    }

    return ans;
  }
};

// Time Complexity - O(N)
// Space Complexity - O(N)