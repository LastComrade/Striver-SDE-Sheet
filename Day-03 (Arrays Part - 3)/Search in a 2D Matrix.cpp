// Problem Link - https://leetcode.com/problems/search-a-2d-matrix/submissions/

class Solution
{
public:
  bool binarySearch(vector<int> vec, int target)
  {
    int mid, l = 0, r = vec.size() - 1;
    while (l <= r)
    {
      mid = (l + r) / 2;
      if (vec[mid] == target)
        return true;
      else if (vec[mid] < target)
        l = mid + 1;
      else
        r = mid - 1;
    }
    return false;
  }
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    if (matrix.size() == 1 && matrix[0].size() == 1)
      return target == matrix[0][0];
    else if (target >= matrix[0][0] && matrix.size() == 1)
      return binarySearch(matrix[0], target);
    else if (target >= matrix[0][0] && target < matrix[1][0])
      return binarySearch(matrix[0], target);
    else
    {
      for (int i = 1; i < matrix.size() - 1; i++)
      {
        if (target == matrix[i][0])
          return true;
        else if (target > matrix[i][0] && target < matrix[i + 1][0])
        {
          return binarySearch(matrix[i], target);
        }
      }
      return binarySearch(matrix[matrix.size() - 1], target);
    }
    return false;
  }
};

// Time Complexity - O(N)
// Space Complexity - O(1)