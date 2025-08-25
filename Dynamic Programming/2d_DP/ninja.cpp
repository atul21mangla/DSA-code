// given 3 tasks to perform on n days
// we cannot perform similat tasks on 2 consecutive days
// find maximum points scored by ninja.

#include<bits/stdc++.h>
using namespace std;

int recursiveFun(int day , int last ,vector<vector<int>>& points){
    // Base Case
    if(day==0){
        int maxi=0;
        for(int task=0;task<3;task++){
            if(task!=last){
                maxi = max(maxi,points[0][task]);
            }
        }
        return maxi;
    }

    // Recursive case
    int maxi = 0;
    for(int task=0;task<3;task++){
        if(task!=last){
            int point = points[day][task] + recursiveFun(day-1,task,points);
            maxi = max(maxi,point);
        }
    }
    return maxi;
}

int topDown(int day , int last ,vector<vector<int>>& points , vector<vector<int>>& dp){
    // Base Case
    if(day==0){
        int maxi=0;
        for(int task=0;task<3;task++){
            if(task!=last){
                maxi = max(maxi,points[0][task]);
            }
        }
        return maxi;
    }

    if(dp[day][last]!=-1)return dp[day][last];
    // Recursive case
    int maxi = 0;
    for(int task=0;task<3;task++){
        if(task!=last){
            int point = points[day][task] + topDown(day-1,task,points,dp);
            maxi = max(maxi,point);
        }
    }
    return dp[day][last] = maxi;
}

int bottomUp(int days , vector<vector<int>>& points){
    vector<vector<int>>dp(days,vector<int>(4,0));
    dp[0][0] = max(points[0][1] , points[0][2]);
    dp[0][1] = max(points[0][0] , points[0][2]);
    dp[0][2] = max(points[0][0] , points[0][1]);
    dp[0][3] = max(points[0][0] , max(points[0][1] , points[0][2]));
    for(int day=1;day<days;day++){
        for(int last=0;last<4;last++){
            dp[day][last] = 0;
            for(int task=0;task<3;task++){
                if(task!=last){
                    int point = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last] , point);
                }
            }
        }
    }
    return dp[days-1][3];
}

int optimized(int days , vector<vector<int>>& points){
    vector<int>prev(4,0);
    prev[0] = max(points[0][1] , points[0][2]);
    prev[1] = max(points[0][0] , points[0][2]);
    prev[2] = max(points[0][0] , points[0][1]);
    prev[3] = max(points[0][0] , max(points[0][1] , points[0][2]));

    for(int day=1;day<days;day++){
        vector<int>temp(4);
        for(int last=0;last<4;last++){
            temp[last]=0;
            for(int task=0;task<3;task++){
                if(task!=last){
                    temp[last] = max(temp[last] , points[day][task] + temp[task]);
                }
            }
        }
        prev = temp;
    }
    return prev[3];
}

int main(){
    int days = 4;
    // input matrix of size 4x3
    vector<vector<int>>points = {{2,1,3},{3,4,6},{10,1,6},{8,3,7}};
    // int ans = recursiveFun(3,3,points);     //* passing parameters (day , task which is last done)


    //! top down approach
    // vector<vector<int>>dp(days,vector<int>(4,-1));
    // int ans = topDown(3,3,points,dp);


    //! bottom up Tabulation
    // int ans = bottomUp(days,points);

    //! space optimized solution
    int ans = optimized(days,points);
    cout<<ans<<endl;
    return 0;
}