class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        mpp[0]=-1;
        int currSum = 0;
        for(int i=0;i<n;i++){
            currSum += nums[i];
            if(mpp.find(currSum%k)!=mpp.end() && i-mpp[currSum%k] >=2){
                return true;
            }
            if(mpp.find(currSum%k)==mpp.end())
            mpp[currSum%k]=i;
        }
        return false;
    }
};