#include<iostream>
using namespace std;

int firstOcc(int *arr,int n,int i,int target){
    // Base case
    if(i==n)return -1;
    // Recursive Case
    if(arr[i]==target){
        return i;
    }
    return firstOcc(arr,n,i+1,target);
}

int main(){
    int arr[] = {2,4,7,3,2,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<firstOcc(arr,n,0,1);
    return 0;
}