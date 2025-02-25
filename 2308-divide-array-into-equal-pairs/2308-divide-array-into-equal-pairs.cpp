class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(int x:nums)mpp[x]++;

        for(auto it:mpp){
            if(it.second%2 != 0)return false;
        }
        return true;
    }
};