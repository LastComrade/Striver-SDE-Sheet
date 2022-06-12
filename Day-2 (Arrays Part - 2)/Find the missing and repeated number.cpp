// Problem Link - https://bit.ly/3Gs6wZu

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    unordered_map<int, int> mp;
    int missing;
    int repeated;
    
    for (int i=0; i<n; i++) {
        mp[arr[i]]++;
        if (mp[arr[i]] == 2)
            repeated = arr[i];
    }
    
    missing =  ((arr.size() * (arr.size() + 1)) / 2) - (accumulate(arr.begin(), arr.end(), 0) - repeated);
    
    return {missing, repeated};
}


// Time Complexity: O(N)
// Space Complexity: O(N)