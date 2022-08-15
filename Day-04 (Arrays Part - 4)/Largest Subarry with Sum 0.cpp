// Problem Link - https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

class Solution
{
public:
    int maxLen(vector<int> &a, int n)
    {
        int len = 0;
        int sum = 0;
        unordered_map<int, int> sumTrack;

        for (int i = 0; i < a.size(); i++)
        {
            sum += a[i];

            if (sum == 0)
                len = i + 1;

            if (sumTrack.find(sum) != sumTrack.end())
                len = max(len, i - sumTrack[sum]);
            else
                sumTrack[sum] = i;
        }

        return len;
    }
};

// Time Complexity - O(N)
// Space Complexity - O(N)