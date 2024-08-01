#include<iostream>
using namespace std;

int partition(int* arr, int s , int e){
    int pivot = arr[e];
    int j=s;
    int i=s-1;
    while(j<=e-1){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
        j++;
    }
    swap(arr[i+1],pivot);
    return i+1;
}

void quickSort(int* arr , int s , int e){
    // Base Case
    if(s>=e)return;

    // Recursive Case
    int pivot  =arr[e];
    int pivotIndex = partition(arr,s,e);
    quickSort(arr,s,pivotIndex-1);
    quickSort(arr,pivotIndex+1,e);
}

int main(){
    int arr[] = {2,6,2,1,9,4,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}