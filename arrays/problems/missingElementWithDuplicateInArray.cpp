#include<bits/stdc++.h>
using namespace std;

void func1(int arr[] , int n){
    sort(arr , arr+n);
    for(int i = 0 ; i < n-1 ; i++){
        int diff = arr[i+1] - arr[i];
        if(diff > 1)
        cout<<"Missing number found : "<<arr[i]+1;
    }
}

int findMissingNo(int arr[] , int n){
    //! using visiting method here
    int ans = -1;
    for(int i = 0; i < n; i++){
        int index = abs(arr[i])-1;
        //* ab mujhe is index position par jake visited krna hai 
        //? aur agar already visited hai to skip it
        if(arr[index] > 0) //! mark visited
        arr[index] = -arr[index];
    }

    // now search for positive number in array
    for(int i=0;i<n;i++){
        if(arr[i]>0)
        ans = i+1;
    }
    return ans;
}

int main(){
    int arr[] = {5,2,3,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);

    // using sorting
    // func1(arr , n);
    int ans = findMissingNo(arr,n);
    cout<<"The missing number is : "<<ans;
    return 0;
}