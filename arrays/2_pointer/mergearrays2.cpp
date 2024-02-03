#include<iostream>
using namespace std;

void printarr(int arr[10],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void mergeArray(int a[],int n,int b[],int m){
    int i=n-1,j=m-1,k=m+n-1;                       // filling from last ...
    while(i>=0 && j>=0){
        if(a[i] < b[j]){
            a[k] = b[j];
            k--,j--;                                // THREE POINTER APPROACH 
        }
        else{
            a[k] = a[i];
            k--,i--;
        }
    }
    
    while(j>=0){
        a[k] = b[j];
        k--,j--;
    }
}

int main(){
    int a[9] = {2,4,5,7,0,0,0,0,0}; 
    int b[5] = {1,5,6,9,9};
    mergeArray(a,4,b,5);             // WE ARE NOT USING ANY EXTRA SPACE HERE 
    cout<<"merged array :";
    printarr(a,9);
}

