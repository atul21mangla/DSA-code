#include<iostream>
using namespace std;

void printarr(int arr[10],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void dnfSort(int a[],int n){
    int low = -1;  // for region of 0s     >>> (0 - low)
    int mid = 0;   // for region of 1s     >>> (low+1 - mid-1)   and   region of unknows  >>(mid - high-1)
    int high = n;  // for region of 2s     >>  (high - n-1)

    while(mid<high){
        if(a[mid] == 0){
            low++;
            swap(a[mid],a[low]);
            mid++;
        }else if(a[mid] == 1){
            mid++;
        }else{
            high--;
            swap(a[mid],a[high]);
        }
    }
}

int main(){
    int a[20] ;
    int n;
    cout<<"enter size of array :";
    cin>>n;
    cout<<"enter elements for array only 0s,1s,and 2s:";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dnfSort(a,n);
    printarr(a,n);
}

