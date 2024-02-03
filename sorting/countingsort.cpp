#include<iostream>
using namespace std;

void printarr(int arr[10],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void countingSort(int arr[] ,int n,int k){                    // TIME COMPLEXITY >> O(N+K)
    int freq[k+1] = {0};                                      //? SPACE COMPLEXITY >> O(N+K)
    for(int i=0;i<n;i++){
        freq[arr[i]]++;           
    }                                                        //* STABLE VERSION OF COUNTING SORT
    
//! cummulative frequency
    for(int i=1;i<=k;i++){
        freq[i]+= freq[i-1];
    }

    for(int i=k;i>0;i--){      //! shifting freq array to right to get starting index of every unique element
        freq[i] = freq[i-1];
    }
    freq[0] = 0;

    //! new output array
    int out[n];
    for(int i=0;i<n;i++){
        out[freq[arr[i]]++] = arr[i];
    }
    printarr(out,n);
    cout<<endl;
}

int main(){
    int arr[] = {1,3,2,0,1,0,3,2,1,3};
    int k = 3;
    cout<<"before sorting :";
    printarr(arr,10);
    cout<<endl;
    cout<<"after sorting :";
    countingSort(arr,10,k);
}
