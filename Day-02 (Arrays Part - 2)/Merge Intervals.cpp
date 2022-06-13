// Problem Link - https://leetcode.com/problems/merge-intervals/solution/

// <---------------------- ONLY SORTING SOLUTION ---------------------->
class Solution
{
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;

    for (auto interval : intervals)
    {
      if (merged.empty() || merged.back()[1] < interval[0])
        merged.push_back(interval);
      else
        merged.back()[1] = max(merged.back()[1], interval[1]);
    }

    return merged;
  }
};

// Time Complexity - O(N * log(N))
// Space Complexity - O(N)



// <---------------------- STACK SOLUTION ---------------------->
class Solution
{
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {
    stack<pair<int, int>> st;
    sort(intervals.begin(), intervals.end());

    for (int i = 0; i < intervals.size(); i++)
    {
      if (st.empty() == false)
      {
        pair<int, int> curr = st.top();
        if (curr.second >= intervals[i][0])
        {
          st.pop();
          curr.second = max(curr.second, intervals[i][1]);
          st.push(curr);
        }
        else
          st.push({intervals[i][0], intervals[i][1]});
      }
      else
        st.push({intervals[i][0], intervals[i][1]});
    }

    vector<vector<int>> ans;

    int i = 0;
    while (st.empty() == false)
    {
      ans.push_back({st.top().first, st.top().second});
      st.pop();
      i++;
    }

    reverse(ans.begin(), ans.end());

    return ans;
  }
};

// Time Complexity - O(N * log(N))
// Space Complexity - O(N)