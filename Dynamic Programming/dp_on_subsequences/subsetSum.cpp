#include<bits/stdc++.h>
using namespace std;

bool recursiveFun(vector<int>& arr, int idx , int target){
    int n = arr.size();
    // Base Case

    if(target == 0)return true;
    if(idx == 0)return (arr[idx]==target);

    bool take = false;
    if(arr[idx] <= target){
        take = recursiveFun(arr,idx-1,target-arr[idx]);
    }

    bool not_take = recursiveFun(arr,idx-1,target);
    return take || not_take;
}

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

bool tabulationFun(vector<int>& arr, int idx , int target){
    int n = arr.size();
    vector<vector<bool>>dp(n,vector<bool>(target+1,false));

    //Base case
    // 1. jab target == 0 yani 0th column me true fill krdo
    // 2. jab idx == 0 fill true where target = arr[0] //? but check ki if arr[0] <= target then only
    for(int i=0;i<n;i++){
        dp[i][0] = true;
    }
    if(arr[0]<=target)dp[0][arr[0]] = true;

    for(int i = 1;i<n;i++){
        for(int k=1;k<=target;k++){
            bool take = false;
            if(arr[i] <= k){
                take = dp[i-1][k-arr[i]];
            }

            bool not_take = dp[i-1][k];
            return dp[i][k] = take || not_take;
        }
    }
    return dp[n-1][target];
}

int main(){
    vector<int>arr = {1,2,3,5,6};
    int n = arr.size();
    int target =  12;
    // if(recursiveFun(arr, n-1 , target))cout << "Subset exists with target = " << target << endl;
    // else cout << "Subset doesn't exists with target = " << target << endl;

    //! top down
    // vector<vector<int>>dp(n,vector<int>(target+1,-1));
    // if(topDownFun(arr, n-1 , target,dp))cout << "Subset exists with target = " << target << endl;
    // else cout << "Subset doesn't exists with target = " << target << endl;

    //! bottom - Up approach ( tabulation )
    if(tabulationFun(arr, n-1 , target))cout << "Subset exists with target = " << target << endl;
    else cout << "Subset doesn't exists with target = " << target << endl;
    return 0;
}