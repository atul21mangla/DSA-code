class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i=1;   // index to place diffrent element as compared to prev element
        int j=1;   // to traverse and find unique elements
        while(j<n){
            if(nums[j]!=nums[i-1]){
                nums[i] = nums[j];
                i++;
            }
            j++;
        }
        return i;
    }
};