class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        int chosen=1;
        int i=1;
        int n = nums.size();
        sort(nums.rbegin(),nums.rend());
        vector<int>res;
        res.push_back(nums[0]);
        while(i<n && chosen<k){
            if(nums[i]==nums[i-1]){
                i++;
                continue;
            }
            chosen++;
            res.push_back(nums[i]);
            i++;
        }
        return res;
    }
};