class Solution {
public:
    bool isGood(vector<int>& nums ,int x , int i , int n,int k){
        int left = INT_MIN;
        int right = INT_MIN;
        if(i-k>=0)left = nums[i-k];
        if(i+k<n)right = nums[i+k];
        if(x>left && x>right)return true;
        return false;
    }


    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            if(isGood(nums,nums[i],i,n,k))sum += nums[i];
        }
        return sum;
    }
};