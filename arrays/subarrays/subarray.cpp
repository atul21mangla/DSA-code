#include<iostream>
using namespace std;

void subarray(int arr[] , int n){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++){
                cout<<arr[k]<<" ";              // total subarrays for array of size n is >>> n*n+1)2
            }
            cout<<endl;
        }
        cout<<endl;
    }
}


int main(){
    int arr[100];
    int n;
    cout<<"enter size of array";
    cin>>n;
    cout<<"enter elements for array";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"subarrays are :"<<endl;
    subarray(arr , n);
}