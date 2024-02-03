#include<iostream>
using namespace std;

void printarr(int arr[10],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[] = {2,4,3,1,2};
    int n = 5;
    int ans[5];

    //* APPROACH ->1  : TIME - o(n^2)  BRUTE FORCE
    // for(int i=0;i<n;i++){
    //     //! answer = li * ri
    //     int li = 1;
    //     for(int j=0;j<=i-1;j++){
    //         li*=arr[j];
    //     }

    //     int ri = 1;
    //     for(int j=i+1;j<n;j++){
    //         ri*=arr[j];
    //     }
    //     ans[i] = li * ri;
    // }
    // printarr(ans,5);

    //* APPROACH ->2  : TIME - O(N)
    int l[20], r[20];
    l[0] = 1;
    for(int i=1;i<n;i++){           // l[i] means product of all from 0-(i-1)
        l[i] = l[i-1] * arr[i-1];   // l[i-1] means product of all from 0-(i-2)
    }
    r[n-1] = 1;
    for(int i=n-2;i>=0;i--){           
        r[i] = r[i+1] * arr[i+1];   
    }

    for(int i=0;i<n;i++){
        ans[i] = l[i] * r[i];
    }
    printarr(ans,5);
}

//? ANOTHER APPROACH CAN BE
//* using / operator
//! first calculate product of whole array
// then ans[i] = product/arr[i]

