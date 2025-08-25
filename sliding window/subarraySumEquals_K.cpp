#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        // O(N^2) Brute Force
        // int count = 0;
        // for(int i=0;i<nums.size();i++){
        //     int sum = 0;
        //     for(int j=i;j<nums.size();j++){
        //         sum+=nums[j];
        //         if(sum==k){
        //             count++;
        //         }
        //     }
        // }
        // return count;

//---------------------------------------------------------------------------------------------

        //! Optimal Sol.

        unordered_map<int,int>mpp;
        mpp[0]=1;
        int count = 0;
        long long sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(mpp.find(sum-k)!=mpp.end()){
                count += mpp[sum-k];
            }
            mpp[sum]++;
        }
        return count;
    }
};