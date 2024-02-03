#include <bits/stdc++.h>
using namespace std;
int maxSubarraySum(int arr[], int n, int k)
{
    int windowSum = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < k; i++)
    { // calculates first initial window sum of size K
        windowSum += arr[i];
    }

    maxSum = max(maxSum , windowSum);

    for (int i = k; i < n; i++)
    {
        windowSum = windowSum - arr[i-k] + arr[i];
        maxSum = max(maxSum , windowSum);
    }
    return maxSum;
}

int main()
{
    int arr[] = {2,9,31,-4,21,7};
    int k = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maxSubarraySum(arr, n, k);
}