#include<bits/stdc++.h>
using namespace std;

int check1(int *arr,int mid,int x){
    if(arr[mid]>=x)return 1;
    else return 0;
}

int check2(int *arr,int mid,int x){
    if(arr[mid]>x)return 1;
    else return 0;
}

int lowerBound(int *arr , int n , int x){
    int l = 0;
    int h = n-1;
    int ans = -1;   // default answer
    while(l<=h){
        int mid = l + (h-l)/2;
        if(check1(arr,mid,x)==1){
            ans = mid;
            h = mid-1;
        }   
        else{
            l = mid+1;
        }
    }
    return ans;
}

int upperBound(int *arr , int n , int x){
    int l = 0;
    int h = n-1;
    int ans = -1;   // default answer
    while(l<=h){
        int mid = l + (h-l)/2;
        if(check2(arr,mid,x)==1){
            ans = mid;
            h = mid-1;
        }   
        else{
            l = mid+1;
        }
    }
    return ans;
}

int main(){
    int arr[] = {1,3,3,5,5,5,6,8,9,9};
    int n = 10;
    int x = 3;
    int lower_bound = lowerBound(arr,n,x);
    int upper_bound = upperBound(arr,n,x);
    cout << lower_bound <<" " << upper_bound<<endl;
}