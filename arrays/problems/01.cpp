#include<iostream>
using namespace std;
int main(){
    int arr[6]={1,2,3,4,5,6} ;
    int brr[5]={6,3,9,3,7};         // alternate swapping
    for(int i=0;i<6;i=i+2){
        swap(arr[i],arr[i+1]);
    }
    for(int i=0;i<5;i=i+2){
        if((i+1)<5){
            swap(brr[i],brr[i+1]);
        }
    }
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<5;i++){
        cout<<brr[i]<<" ";
    }
    return 0;
}