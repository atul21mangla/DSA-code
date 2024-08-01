#include<iostream>
using namespace std;

bool arraySortedIterative(int *arr , int n){
    for(int i=0;i<n-1;i++){
        if(arr[i+1]<arr[i])
            return false;
    }
    return true;
}

bool arraySortedRecursive(int *arr , int n , int i){
    // Base case
    if(i==n-1)return true;

    // Recursive case
    if(arr[i]<arr[i+1]){
        return arraySortedRecursive(arr,n,i+1);
    }
    return false;
}

int main(){
    int arr[] = {10,2,30,40,50};
    int n = 5;
    // if(arraySortedIterative(arr,n)){
    //     cout<<"Array is sorted"<<endl;
    // }
    // else{
    //     cout<<"Array is not sorted"<<endl;
    // }
    arraySortedRecursive(arr,n,0) ? 
        cout<<"Array is sorted"<<endl :
        cout<<"Array is not sorted"<<endl;   
    return 0;
}