#include<bits/stdc++.h>
using namespace std;

int maximumSumSubarray(int* arr , int n , int k){
    int sum=0,maxSum=0;
    int i=0,j=0;
    while(j<n){
        sum += arr[j];
        if(j-i+1 < k){
            j++;
        }
        else{
            maxSum = max(maxSum,sum);
            sum -= arr[i];
            i++;
            j++;
        }
    }
    return maxSum;
}

int main(){
    int arr[] = {10,42,3,40,2,23};
    int n = 6;
    int k=3;
    cout << maximumSumSubarray(arr,n,k)<<endl;
    return 0;
}