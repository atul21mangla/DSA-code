#include<bits/stdc++.h>
using namespace std;

void merge(int arr[] , int start , int mid , int end){
    vector<int>temp(end-start+1);
    int i = start , j = mid+1 , k = 0;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }

    while(i<=mid){
        temp[k++] = arr[i++];
    }

    while(j<=end){
        temp[k++] = arr[j++];
    }
    k = 0;
    for(int i = start ; i<=end ; i++){
        arr[i] = temp[k++];
    }
}

void mergeSort(int arr[] , int start , int end){
    //! base case
    if(start >= end) return;

    int mid = start + (end-start)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,start,mid,end);
}

int main(){
    int arr[] = {2,6,2,1,9,4,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}