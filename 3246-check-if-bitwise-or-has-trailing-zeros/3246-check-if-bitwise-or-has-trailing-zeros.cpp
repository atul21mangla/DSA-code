class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int countEven=0;
        for(int x:nums){
            countEven += !(x&1);
        }
        return countEven>=2;
    }
};