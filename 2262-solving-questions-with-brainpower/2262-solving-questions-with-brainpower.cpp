#define ll long long int
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        ll n = questions.size();
        vector<ll>dp(n+1,0);
        dp[n-1] = questions[n-1][0];

        for(int i=n-2;i>=0;i--){
            ll solveThis = questions[i][0];
            ll skips = questions[i][1];
            solveThis += (i+skips+1<=n-1)?dp[i+skips+1]:0;

            ll notSolve = dp[i+1];

            dp[i] = max(solveThis , notSolve);
        }

        return dp[0];
    }
};