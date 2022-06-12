// Problem Link - https://bit.ly/339fFb7

#include <bits/stdc++.h>
long long merge(long long arr[], long long temp[], long long left, long long mid, long long right)
{
  long long invs = 0;
  long long i = left;
  long long j = mid;
  long long k = left;

  while ((i <= mid - 1) && (j <= right))
  {
    if (arr[i] <= arr[j])
      temp[k++] = arr[i++];
    else
    {
      temp[k++] = arr[j++];
      invs += mid - i;
    }
  }

  while (i <= mid - 1)
    temp[k++] = arr[i++];

  while (j <= right)
    temp[k++] = arr[j++];

  for (i = left; i <= right; i++)
    arr[i] = temp[i];

  return invs;
}

long long mergeSort(long long arr[], long long temp[], long long left, long long right)
{
  long long mid;
  long long invs = 0;

  if (right > left)
  {
    mid = (left + right) / 2;

    invs += mergeSort(arr, temp, left, mid);
    invs += mergeSort(arr, temp, mid + 1, right);

    invs += merge(arr, temp, left, mid + 1, right);
  }

  return invs;
}

long long getInversions(long long *arr, int n)
{
  // We basically find the inversion pairs while merging the subarrays
  // and store the inversion count in invs.
  long long temp[n];
  long long ans = mergeSort(arr, temp, 0, n - 1);

  return ans;
}

// Time Complexity: O(N * log(N))
// Space Complexity: O(N)