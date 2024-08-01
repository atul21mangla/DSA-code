#include<bits/stdc++.h>
using namespace std;

void firstRepeating(int arr[] , int n){    // TC-> O(N) and SC -> O(N) 
    // using map 
    unordered_map<int, int>mpp;
    for(int i=0; i<n; i++){
        mpp[arr[i]]++;
    }
    // iterate over array and check freq of occurence of arr[i] , if more than 1 print its index
    for(int i=0;i<n;i++){
        if(mpp[arr[i]] > 1){
            cout << "First repeating element is " << arr[i] <<" and its first occuring index is "<<i << endl;
            break;
        }
    }
}

int main(){

    int arr[] = {1,5,3,4,3,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    firstRepeating(arr,n);
    return 0;
}