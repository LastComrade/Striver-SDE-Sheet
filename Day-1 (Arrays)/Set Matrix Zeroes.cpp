// Problem link - https://leetcode.com/problems/set-matrix-zeroes/submissions/

class Solution
{
public:
  void setZeroes(vector<vector<int>> &matrix)
  {
    bool colZero = false;

    for (int i = 0; i < matrix.size(); i++)
    {
      // Checking if we have any 0 in the first column
      if (matrix[i][0] == 0)
        colZero = true;

      // Marking the fist cell of the row and column as 0
      for (int j = 1; j < matrix[0].size(); j++)
      {
        if (matrix[i][j] == 0)
        {
          matrix[0][j] = 0;
          matrix[i][0] = 0;
        }
      }
    }

    // Making cells 0 in values who have their starting row cell and column cell as 0
    for (int i = 1; i < matrix.size(); i++)
    {
      for (int j = 1; j < matrix[0].size(); j++)
      {
        if (matrix[i][0] == 0 || matrix[0][j] == 0)
          matrix[i][j] = 0;
      }
    }

    // Checking if the first cell is 0
    // So that we can make the first row filled with 0s
    if (matrix[0][0] == 0)
    {
      for (int i = 0; i < matrix[0].size(); i++)
      {
        matrix[0][i] = 0;
      }
    }

    // Checking if there is any cell that is 0 in value in the first column then
    // We will fill the first column with 0s
    if (colZero)
    {
      for (int i = 0; i < matrix.size(); i++)
      {
        matrix[i][0] = 0;
      }
    }
  }
};

// Time Complexity - O(m*n)
// Space Complexity - O(1)