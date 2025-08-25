#include<bits/stdc++.h>
using namespace std;
int countPartitions(vector<int>& arr, int d) {
        int n = arr.size();
        int totalSum = accumulate(arr.begin(),arr.end(),0);
    	vector<vector<int>>dp(n,vector<int>(totalSum+1,0));
    	int k = totalSum;
    	
    	dp[0][0]=1;
        if(arr[0]==0) dp[0][0]=2;
        else if(arr[0]<=k) dp[0][arr[0]]=1;
    
        // filling dp table
        for(int i=1;i<n;i++){
            for(int target=0;target<=k;target++){
                int not_take = dp[i-1][target];
                int take = 0;
                if(arr[i]<=target){
                    take = dp[i-1][target-arr[i]];
                }
                dp[i][target] = not_take+take;
            }
        }
        
        // iterating over last row in dp table
        int ans = 0;
        for(int i=0;i<=k;i++){
            if(dp[n-1][i]!=0){
                if(d==2*i-k){
                    ans =  dp[n-1][i];
                }
            }
        }
        return ans;
    }

// other preferred way

int countPartitions(vector<int>& arr, int d) {
        // s1 + s2 = sum
        // s1 - s2 = d
        // 2s1 = sum + d
        // s1 = (sum + d)/2
        // s1 should be always be integer and find all subsets having sum as s1
        // This will be our answer
        int sum = 0;
        for(auto &e : arr){
            sum += e;
        }
        if((sum + d)%2){
            return 0;
        }
        int target = (sum + d)/2;
        vector<int> prev (target + 1, 0);
        int n = arr.size();
        prev[0] = 1;
        if(arr[0] <= target){
            prev[arr[0]] += 1;
        }
        unordered_map<int, int> mp;
        for(int i = 1; i < n; i++){
            vector<int> curr (target + 1, 0);
            curr[0] = 1;
            for(int j = 0; j <= target; j++){
                curr[j] = prev[j];
                if(arr[i] <= j){
                    curr[j] += prev[j - arr[i]];
                }
                
            }
            prev = curr;
        }
        return prev[target];
    }

int main(){
    
    return 0;
}


