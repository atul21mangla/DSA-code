class Solution {
public:
    int dp[1002][1002];

    bool solve(string s , int i , int j){
        if(i>=j)return 1;

        if(dp[i][j]!=-1)return dp[i][j];

        if(s[i]==s[j])return dp[i][j] = solve(s,i+1,j-1);
        
        return dp[i][j] = 0;
    }

    int countSubstrings(string s) {
        int count=0;
        int n = s.size();
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j))count++;
            }
        }
        return count;
    }
};