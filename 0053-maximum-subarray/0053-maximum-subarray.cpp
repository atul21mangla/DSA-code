class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>maxSum(n,-1);
        maxSum[0]=nums[0];
        for(int i=1;i<n;i++){
            // calculating max sum of subarray ending at index i
            maxSum[i] = max(maxSum[i-1]+nums[i] , nums[i]);
        }

        int ans = INT_MIN;
        for(int x:maxSum){
            if(x>ans){
                ans = x;
            }
        }
        return ans;
    }
};