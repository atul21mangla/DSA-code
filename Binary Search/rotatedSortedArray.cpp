#include<bits/stdc++.h>
using namespace std;

int pivotIndex2(int arr[] , int n){
    int start = 0;
    int end = n-1;
    int ans = n-1;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(arr[mid]<arr[0]){   // by designing check 
            ans=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return ans-1;
}

// int pivotIndex(int arr[] , int n){
//     int start = 0;
//     int end = n-1;
//     while(start<=end){
//         int mid = start + (end-start)/2;
//         if( mid+1<n && arr[mid] > arr[mid+1])return mid;
//         if( mid-1>0 && arr[mid] < arr[mid-1])return mid-1;
//         if(arr[mid] > arr[0])start = mid+1;
//         else{
//             end = mid-1;
//         }
//     }
//     return -1;
// }

int main(){
    int arr[] = {3,4,5,6,7,0,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    // int index = pivotIndex(arr,n);
    int index = pivotIndex2(arr,n);
    cout<<index<<" : "<<arr[index];
    return 0;
}