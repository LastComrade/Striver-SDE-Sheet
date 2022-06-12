// Problem Link - https://leetcode.com/problems/rotate-image/submissions/

class Solution
{
public:
  void rotate(vector<vector<int>> &matrix)
  {
    // Transpose Matrix -> Rows are reversed = Rotated Matrix
    
    // Transpose the matrix
    for (int i = 0; i < matrix[0].size(); i++)
    {
      for (int j = i + 1; j < matrix.size(); j++)
      {
        int temp = matrix[j][i];
        matrix[j][i] = matrix[i][j];
        matrix[i][j] = temp;
      }
    }

    // Reverse the rows
    for (int i = 0; i < matrix.size(); i++)
    {
      reverse(matrix[i].begin(), matrix[i].end());
    }
  }
};

// Time Complexity: O(M * N)
// Space Complexity: O(1)