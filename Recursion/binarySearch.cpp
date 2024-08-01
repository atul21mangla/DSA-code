#include<iostream>
using namespace std;

int binarySearchRecursive(int *arr , int s , int e , int target){
    // Base Case
    if(s>e)return -1;

    // Recursive Case
    int mid = s + (e-s)/2;
    if(arr[mid]==target)return mid;
    else if(arr[mid]>target)
    return binarySearchRecursive(arr,s,mid,target);
    else
    return binarySearchRecursive(arr,mid+1,e,target);
}

int main(){
    int arr[] = {10,20,30,40,50,60};
    int n = 6;
    int target = 20;
    cout<<binarySearchRecursive(arr,0,n-1,target);
    return 0;
}