#include<bits/stdc++.h>
using namespace std;

int pivotIndex(int arr[] , int n){
    int start = 0;
    int end = n-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(start==end)return start;
        if( mid+1<n && arr[mid] > arr[mid+1])return mid;
        if( mid-1>0 && arr[mid] < arr[mid-1])return mid-1;
        if(arr[mid] >= arr[0])start = mid+1;
        else{
            end = mid-1;
        }
    }
    return -1;
}

int binarySearch(int arr[] , int n , int start , int end , int target){
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]==target)return mid;
        else if(arr[mid] > target)end = mid-1;
        else{
            start = mid+1;
        }
    }
    return -1;
}


int main(){
    int arr[] = {3,4,5,6,7,0,1,2};
    // int arr[] = {1,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 1;
    int pIndex = pivotIndex(arr,n);
    int ans = -1;
    if(target>=arr[0] && target<=arr[pIndex]){
        ans = binarySearch(arr , n , 0 , pIndex , target);
    }
    else{
        ans = binarySearch(arr , n , pIndex+1 , n-1 , target);
    }
    cout<<"Target found at index : "<<ans;
    return 0;
}