#include<bits/stdc++.h>
using namespace std;

bool topDownFun(vector<int>& arr, int idx , int target , vector<vector<int>>& dp){
    int n = arr.size();
    // Base Case

    if(target == 0)return true;
    if(idx == 0)return (arr[idx]==target);

    if(dp[idx][target]!=-1) return dp[idx][target];

    bool take = false;
    if(arr[idx] <= target){
        take = topDownFun(arr,idx-1,target-arr[idx],dp);
    }

    bool not_take = topDownFun(arr,idx-1,target,dp);
    return dp[idx][target] = take || not_take;
}

int main(){
    vector<int>arr = {1,3,3,5,6};
    int n = arr.size();
    int k = accumulate(arr.begin(),arr.end(),0);
    if(k%2==1)cout << "Not possible " << endl;
    
    else{
        vector<vector<int>>dp(n,vector<int>((k/2)+1,-1));
        if(topDownFun(arr , n-1 , k/2 , dp)){
            cout << "Subset possible with half sum = " << k/2 <<endl;
        }
        else cout << "Not possible" << endl;
    } 
    return 0;
}