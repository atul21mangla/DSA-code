class Solution {
public:
    void updateBit(int x , int val , vector<int>& bit){
        for(int i=0;i<32;i++){
            if(x&(1<<i))bit[i]+= val;
        }
    }

    int getVal(vector<int>& bit){
        long long sum = 0;
        for(int i=0;i<32;i++){
            if(bit[i])sum += 1<<i;
        }
        return sum;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>bit(32,0);
        int left = 0 , right = 0 , minLen = INT_MAX;
        while(right<n){
            updateBit(nums[right],1,bit);
            while(getVal(bit)>=k && left<=right){
                minLen = min(minLen,right-left+1);
                updateBit(nums[left],-1,bit);
                left++;
            }
            right++;
        }
        return (minLen!=INT_MAX)? minLen:-1;
    }
};