#include<bits/stdc++.h>
using namespace std;

int brutefun(int* arr , int n , int target){
    int minSize = n+1;
    for(int i=0;i<n;i++){
        int sum = 0;
        bool value = false;
        for(int j=i;j<n;j++){
            sum += arr[j];
            if(sum >= target){
                minSize = min(minSize,j-i+1);
                value = true;
            }
            if(value)break;
        }
    }
    return (minSize==n+1)?0:minSize;
}

int optimalfun(int* arr , int n , int target){
    int minSize = n+1;
    int i=0,j=0;
    int sum = 0;
    while(j<n){
        sum += arr[j];
        while(sum>=target){
            minSize = min(minSize,j-i+1);
            sum -= arr[i];
            i++;
        }
        j++;
    }
    return (minSize==n+1)?0:minSize;
}

int main(){
    int arr[] = {2,3,1,2,4,3};
    int n = 6;
    int target = 7;
    // cout<<brutefun(arr,n,target); 
    cout << optimalfun(arr,n,target);
    return 0;
}