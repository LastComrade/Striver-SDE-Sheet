// Problem Link - https://leetcode.com/problems/pascals-triangle/

class Solution
{
public:
  vector<vector<int>> generate(int numRows)
  {
    vector<vector<int>> ans;

    for (int i = 0; i < numRows; i++)
    {
      // Initializing the row with 1s
      vector<int> row(i + 1, 1);

      for (int j = 1; j < i; j++)
      {
        // Taking the sum of the previous row and previous column elements
        row[j] = (ans[i - 1][j] + ans[i - 1][j - 1]);
      }

      ans.push_back(row);
    }

    return ans;
  }
};

// Time Complexity - O(n^2) (n is the number of rows)
// Space Complexity - O(n^2) (n is the number of rows)