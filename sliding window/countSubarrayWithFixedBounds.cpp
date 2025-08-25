
// https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/

#include<bits/stdc++.h>
using namespace std;

int bruteFun(int* arr , int n , int minK , int maxK){
    int currMax = 0 , currMin = INT_MAX;
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            currMin = min(currMin,arr[j]);
            currMax = max(currMax,arr[j]);
            if(currMin==minK and currMax==maxK)count++;
        }
    }
    return count;
}

int main(){
    int arr[] = {1,3,5,2,7,5};
    int n = 6;
    int minK = 1;
    int maxK = 5;
    cout<<bruteFun(arr,n,minK,maxK);
    return 0;
}