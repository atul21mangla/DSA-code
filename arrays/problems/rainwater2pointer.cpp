#include<bits/stdc++.h>
using namespace std;
int main(){                                             //! 2 pointer approach
    int arr[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i = 0;
    int j = n-1;
    int l = 0;        //? maximum building in range [0,i-1]
    int r = 0;        //* maximum building in range [j+1,n-1]
    int w = 0;       // stores total water on top of all buildings
    while(i<=j){
        l = max(l,arr[i]);
        r = max(r,arr[j]);
        
        if(l>r){
            int w_j = r-arr[j];
            w+= w_j;
            j--;
        }
        else{
            int w_i = l-arr[i];
            w+=w_i;
            i++;
        }
    }
    cout<<w;
}
    