
//! ye mera base problem hai 
//? try to convert Binary Search problem in this 0s and 1s pattern 
//* symptoms of Binary Search - monotonicity , Maximize the minimum or minimize the maximum

#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={0,0,1,1,1,1,1,1};
    int n = 8;
    // find first occurence of 1 or lowest index for 1

    int low = 0;
    int high = n-1;
    int ans = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]==1){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    cout << ans;
}