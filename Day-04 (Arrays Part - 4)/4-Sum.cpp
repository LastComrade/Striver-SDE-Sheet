// Problem Link - https://leetcode.com/problems/4sum

class Solution
{
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target)
  {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
      for (int j = i + 1; j < nums.size(); j++)
      {
        long long reqNum = (long long)target - ((long long)nums[i] + (long long)nums[j]);

        // 2 - Pointers search
        int lo = j + 1, hi = nums.size() - 1;
        while (lo < hi)
        {
          int check = nums[lo] + nums[hi];
          if (check == reqNum)
          {
            vector<int> quad = {nums[i], nums[j], nums[lo], nums[hi]};
            ans.push_back(quad);

            // Avoiding processing on the processed combinations of quads
            while (lo < hi && nums[lo] == quad[2])
              lo++;
            while (lo < hi && nums[hi] == quad[3])
              hi--;
          }
          else if (check < reqNum)
            lo++;
          else
            hi--;
        }

        // Avoiding processing on the processed combinations of quads
        while (j + 1 < nums.size() && nums[j] == nums[j + 1])
          j++;
      }

      // Avoiding processing on the processed combinations of quads
      while (i + 1 < nums.size() && nums[i] == nums[i + 1])
        i++;
    }

    return ans;
  }
};

// Time Complexity - O(N^3)
// Space Complexity - O(1)