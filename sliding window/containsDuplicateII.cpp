
// https://leetcode.com/problems/contains-duplicate-ii/

#include<bits/stdc++.h>
using namespace std;

bool bruteFun(int* arr , int n , int k){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]==arr[j] and abs(i-j)<=k) return true;
        }
    }
    return false;
}

bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            if(mpp.find(nums[i]) != mpp.end() && abs(mpp[nums[i]]-i)<=k){// pehle bhi present tha map me
               return true; 
            }
            mpp[nums[i]] = i;
        }
        return false;
}

int main(){
    int arr[] = {1,2,3,1,2,3};
    int n = 6;
    int k = 2;
    // cout<<bruteFun(arr,n,k);
    return 0;
}