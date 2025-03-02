class Solution {
public:

    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums1.size();i++){
            mpp[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            if(mpp.count(nums2[i]))return nums2[i];
        }
        return -1;
    }
};