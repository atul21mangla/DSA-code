#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    //* BRUTE FORCE
    // int w = 0;
    // for(int i=0;i<n;i++){
    //     //* li = max height of buildings in range [0,i]
    //     //? ri = max height of buildings in range[i,n-1]
    //     int li = arr[i];
    //     for(int j=0;j<=i;j++){
    //         li = max(li,arr[j]);
    //     }
    //     int ri = arr[i];
    //     for(int j=i;j<n;j++){
    //         ri = max(ri,arr[j]);
    //     }
    //     int wi = min(li,ri) - arr[i];
    //     w+=wi;
    // }
    // cout<<w;

    //! time complexity -- O(3n)~ O(n)
    //* spcace complexity -- O(2n)  >>>> changes to O(n)
    int /*l[100] */r[100];  //? based on constrains

// further optimization , we can add this below loop in other one and save our one extra array space 
    // l[0] = arr[0];
    // for(int i=1;i<n;i++){
    //     l[i] = max(arr[i],l[i-1]);
    // }

    r[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--){
        r[i] = max(arr[i],r[i+1]);
    }

    int w = 0;
    int li = 0;
    for(int i=0;i<n;i++){
        li = max(li,arr[i]);
        w+=min(li,r[i]) - arr[i];
    }
    cout<<w;
}