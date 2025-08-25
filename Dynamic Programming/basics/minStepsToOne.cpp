#include<bits/stdc++.h>
using namespace std;

int funBasic(int n){
    // Base Case
    if(n==1)return 0;

    // pehla choice n-1 wala => frnd ko baki ka kaam de do ki you find minimum steps to reach 1 if chosen this path
    int x = funBasic(n-1);

    // choice 2 => n/2 wala but only be used if (n%2==0)
    int y = INT_MAX;
    if(n%2==0){
        y = funBasic(n/2);
    }

    // choice 3 => n/3 wala but only be used if (n%3==0)
    int z = INT_MAX;
    if(n%3==0){
        z = funBasic(n/3);
    }
    return 1 + min(x,min(y,z));
}

int topDown(int n , vector<int>& dp){
    if(dp[n]!=-1)return dp[n];

    if(n==1)return dp[n]=0;

    // pehla choice n-1 wala => frnd ko baki ka kaam de do ki you find minimum steps to reach 1 if chosen this path
    int x = topDown(n-1,dp);

    // choice 2 => n/2 wala but only be used if (n%2==0)
    int y = INT_MAX;
    if(n%2==0){
        y = topDown(n/2,dp);
    }

    // choice 3 => n/3 wala but only be used if (n%3==0)
    int z = INT_MAX;
    if(n%3==0){
        z = topDown(n/3,dp);
    }
    return dp[n] = 1 + min(x,min(y,z));

}

int bottomUp(int n){
    vector<int>dp(n+1);
    dp[1] = 0;
    for(int i=2;i<=n;i++){
        int x = dp[i-1];

        int y = INT_MAX;
        if(i%2==0){
            y = dp[i/2];
        }

        int z = INT_MAX;
        if(i%3==0){
            z = dp[i/3];
        }
        dp[i] = 1 + min(x,min(y,z));
    }
    return dp[n];
}

int main(){
    int n = 10;
    //! Time Complexity: 𝑂(3^𝑛)(exponential, due to overlapping subproblems)
    cout << funBasic(n) << endl; 
    
    // top - Down approach
    //!  Use recursion with memoization to avoid redundant calculations.
    //? TC - O(n) and SC - O(n) for the recursion stack and dp array.
    vector<int>dp(n+1,-1);
    cout << topDown(n,dp) << endl;
    for(int x:dp)cout << x << " ";
    cout << endl;

    // Bottom - Up 
    //! Iteratively compute the minimum steps for all numbers from 1 to n.
    cout << bottomUp(n) << endl;
    return 0;
}