#include<bits/stdc++.h>
using namespace std;

int funcBrute(int *arr , int n){
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum = 0;
            for(int k=i;k<=j;k++){
                sum += arr[k];
            }
            if(sum==0)count++;
        }
    }
    return count;
}

int funcBetter(int *arr , int n){
    int count = 0;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum += arr[j];
            if(sum==0)count++;
        }
    }
    return count;
}

int funcOptimal(int *arr , int n){    //! Prefix Sum Appproach
    long long ans = 0;
    unordered_map<int,int>mpp;
    long long sum=0;
    mpp[0]=1;  //? Edge case for prefix sum as ( 0 )
    for(int i=0;i<n;i++){
        sum += arr[i];
        if(mpp.find(sum)!=mpp.end()){
            ans += mpp[sum];
        }
        mpp[sum]++;
    }
    return ans;
}

int main(){
    int arr[] = {6,-1,-3,4,-2,2,4,6,-12,-2};
    int n = 10;
    // cout << funcBrute(arr,n) << endl;   //! TC - O(N^3)
    // cout << funcBetter(arr,n) << endl;  //! TC - O(N^2)
    cout << funcOptimal(arr,n) << endl;    //! TC - O(N) 
    return 0;
}