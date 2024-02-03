#include<iostream>
using namespace std;

void reverse(int arr[10],int i,int j){
    while(i<j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}

void printarr(int arr[10],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[10]={1,3,5,7,9,2,3,5,6,1};
    reverse(arr,0,9);
    printarr(arr,10);
    return 0;
}