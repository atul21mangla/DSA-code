#include<bits/stdc++.h>
using namespace std;

void func1(int arr[] , int n){                //! brute force
    int size = n+1;  //* array size              
    for(int i=0;i<size-1;i++){                //? O(N^2)
        for(int j=i+1;j<size;j++){
            if(arr[i]==arr[j]){
                cout<<"Duplicate element found: "<<arr[i];
                return;
            }
        }
    }
}


void func2(int arr[] , int n){                //! using sorting
    int size = n+1;  //* array size 
    sort(arr,arr+size);             
    for(int i=0;i<size-1;i++){                //? O(N logN)
        if(arr[i]==arr[i+1]){
            cout<<"Duplicate element found: "<<arr[i];
            return;
        }
    }
}

int main(){
    int arr[] = {1,6,4,6,2,5,3};
    int n = 6;
    // func1(arr,n);  // brute force 
    // func2(arr,n);  // better method using sorting 

    func3(arr , n)    // optimal way 
    return 0;
}