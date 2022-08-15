// Problem Link - https://www.interviewbit.com/problems/subarray-with-given-xor/

int Solution::solve(vector<int> &A, int B)
{
    int currPrefXor = 0, count = 0;
    unordered_map<int, int> subArray;

    for (int i = 0; i < A.size(); i++)
    {
        currPrefXor ^= A[i];
        int prevPrefXor = currPrefXor ^ B;

        if (currPrefXor == B)
            count++;

        count += subArray[prevPrefXor];
        subArray[currPrefXor]++;
    }

    return count;
}

// Time Complexity - O(n)
// Space Complexity - O(n)