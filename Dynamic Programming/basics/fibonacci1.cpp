#include<bits/stdc++.h>
using namespace std;

int fib(int n){
    // Base Case
    if(n==0 || n==1)return n;

    // Recursive Case
    return fib(n-1) + fib(n-2);

}

int fibTopDown(int n , vector<int>& dp){
    if(dp[n] != -1)return dp[n];
    
    // Base Case
    if(n==0 || n==1)return dp[n] = n;

    return dp[n] = (fibTopDown(n-1,dp) + fibTopDown(n-2,dp));
}

int bottomUp(int n){
    vector<int>dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int bottomUpOptimal(int n){
    int a = 0;
    int b = 1;
    for(int i=2;i<=n;i++){
        int c = a+b;
        a=b;
        b=c;
    }
    return b;
}

int main(){
    int n = 30;
    //! TC - O(2^n)
    cout << fib(n) << endl;

    // Top - Down DP approach
    //! TC - O(n) SC - O(n)

    vector<int>dp(n+1,-1);
    cout << fibTopDown(n,dp) << endl;
    for(int x:dp)cout<<x<<" ";
    cout << endl;

    // Bottom - Up approach 
    //! TC - O(n) SC - O(n)
    cout << bottomUp(n) << endl;

    // spcae optimized bottom - up
    cout << bottomUpOptimal(n);
    return 0;
}