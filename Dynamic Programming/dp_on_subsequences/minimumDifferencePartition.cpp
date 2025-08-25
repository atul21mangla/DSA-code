#include<bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totalSum = accumulate(arr.begin(),arr.end(),0);
	vector<vector<bool>>dp(n,vector<bool>(totalSum+1,false));
	int k = totalSum;
	for(int i=0;i<n;i++){
		dp[i][0] = true;
	}
	if(arr[0]<=k)dp[0][arr[0]]=true;
	for(int i=1;i<n;i++){
		for(int target = 1;target<=k;target++){
			bool not_take = dp[i-1][target];
			bool take = false;
			if(arr[i]<=target){
				take = dp[i-1][target-arr[i]];
			}
			dp[i][target] = take || not_take;
		}
	}

	int mini = INT_MAX;
	for(int i=0;i<=totalSum/2;i++){
		
		if(dp[n-1][i]==true){
			int s1 = i;
			int s2 = totalSum-i;
			mini = min(mini,abs(s2-s1));
		}
	}
	return mini;
}


int main(){
    vector<int>arr = {3,1,5,2,8};
    int n = 5;
    cout << minSubsetSumDifference(arr,n);
    return 0;
}
