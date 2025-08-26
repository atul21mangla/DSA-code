class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[0];
        int ans = nums[0];
        for(int i=1;i<n;i++){
            // calculating max sum of subarray ending at index i
            maxSum = max(maxSum+nums[i] , nums[i]);
            ans = max(ans,maxSum);
        }

        return ans;
    }
};