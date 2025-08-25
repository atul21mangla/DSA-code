class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>nums[(i+1)%n])count++;
        }
        return count<=1;
    }
};


// Brute Force: Check all rotations - simple but inefficient 

// Optimal Single Pass: Count violations where nums[i] > nums[(i+1) % n]

// Pivot Approach: Explicitly finds the rotation point (if not found then already sorted otherwise now check if elements after pivot point are increasing or not and at last check whether arr last element should be smaller than first element)....