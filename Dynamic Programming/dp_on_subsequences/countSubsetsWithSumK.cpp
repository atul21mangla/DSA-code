#include<bits/stdc++.h>
using namespace std;

int f(vector<int>& arr , int k , int idx){
    int n = arr.size();
    // Base Case
    if(idx==0) {
        if(arr[0]==0 && k==0)return 2;
        if(k==0 || arr[0]==k) return 1;
        return 0;
    }

    int not_take = f(arr,k,idx-1);
    int take = 0;
    if(arr[idx]<=k){
        take = f(arr,k-arr[idx],idx-1);
    }
    return not_take+take;
}

int topDown(vector<int>& arr, int k, int idx , vector<vector<int>>& dp){
    int n =  arr.size();
    if(idx==0) {
        if(arr[0]==0 && k==0)return 2;
        if(k==0 || arr[0]==k) return 1;
        return 0;
    }

    if(dp[idx][k]!=-1)return dp[idx][k];

    int not_take = topDown(arr,k,idx-1,dp);
    int take = 0;
    if(arr[idx]<=k){
        take = topDown(arr,k-arr[idx],idx-1,dp);
    }
    return dp[idx][k] = not_take+take;

}

int bottomUp(vector<int>& arr, int k){
    int n =  arr.size();
    vector<vector<int>>dp(n,vector<int>(k+1,0));
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
    return dp[n-1][k];
}

int main(){
    vector<int>arr = {3,1,0,5,2,7};
    int k = 9;
    int n = arr.size();
    // cout << f(arr,k,n-1); 


    // vector<vector<int>>dp(n,vector<int>(k+1,-1));
    // cout << topDown(arr,k,n-1,dp);

    cout << bottomUp(arr,k);
    return 0;
}