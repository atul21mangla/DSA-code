#include<iostream>
using namespace std;

int search(int a[10],int t){
    for(int i=9;i>=0;i--){
        if(a[i]==t){
            return i;
            break;
        }
    }
    return -1;
}
int main(){
    int arr[10]={1,3,5,7,9,2,3,5,6,1};
    int t;
    cout<<"enter target to be searched :";
    cin>>t;
    int index=search(arr,t);
    if(index==-1){
        cout<<"Target not present";
        return 0;
    }
    cout<<"Target found at "<<index<<"th index";
    return 0;
}