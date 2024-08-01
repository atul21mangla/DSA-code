#include<iostream>
#include<limits.h>
using namespace std;

void printArr(int* arr , int n , int index){  //? Recursively Printing array elements
    if(index>=n){
        return;
    }
    cout << arr[index] << " ";
    printArr(arr,n,index+1);
}

void findMin(int* arr , int n , int index , int &mini){
    if(index>=n){
        return;
    }
    
    mini = min(mini , arr[index]);
    findMin(arr,n,index+1,mini);
}

int main(){
    int arr[] = {10,20,0,-4,5};
    int n = 5;
    int index=0;
    printArr(arr,n,index);
    cout<<endl;
    int mini = INT_MAX;
    findMin(arr,n,index,mini);
    cout << mini <<endl;
    return 0;
}