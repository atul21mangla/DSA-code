class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        for(auto x:nums){
            mpp[x]++;
        }

        int sum=0;
        for(int i=0;i<n;i++){
            sum+= nums[i];
        }

        int avg = sum/n;
        int res=(avg<0)?1:avg+1;
        while(true){
            if(mpp.count(res)){
                res++;
            }
            else return res;
        }
        return -1;
    }
};