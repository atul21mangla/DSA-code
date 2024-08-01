#include<bits/stdc++.h>
using namespace std;

int floorArray(int arr[] , int n , int x){    // x ya usse chota element dedo
    int start = 0;
    int end = n-1;
    int ans = -1;
    while(start<=end){
        int mid = start + (end-start)/2;

        if(x == arr[mid])return mid;

        else if(arr[mid] > x){
            end = mid-1;
        }
        else   // mid target se chota hai to ye mera answer ho bhi sakta hai but me isse bada dhundne ka try krunga right me
        {
            ans = arr[mid];
            start = mid+1;
        }
    }
    return ans;
}

int ceilArray(int arr[] , int n , int x){       // x ya usse bada element dedo
    int start = 0;
    int end = n-1;
    int ans = -1;
    while(start<=end){
        int mid = start + (end-start)/2;

        if(x == arr[mid])return mid;

        else if(arr[mid] < x){
            start = mid+1;
        }
        else   // mid target se bada hai to ye mera answer ho bhi sakta hai but me isse chota dhundne ka try krunga left me
        {
            ans = arr[mid];
            end = mid-1;
        }
    }
    return ans;     

}

int main(){
    int arr[] = {1,3,4,4,7,8,10};
    // int arr[] = {1,2,8,10,10,12,19};
    int x = 5;
    int n = sizeof(arr)/sizeof(arr[0]);
    int floor = floorArray(arr,n,x);         //! O(LOG N)
    int ceil = ceilArray(arr,n,x);
    cout<<"The floor value of "<<x<<" in array is : "<<floor<<endl;
    cout<<"The ceil value of "<<x<<" in array is : "<<ceil<<endl;
}
