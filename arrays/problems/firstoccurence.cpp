#include<iostream>
using namespace std;

int search(int a[10],int t){
    for(int i=0;i<10;i++){
        if(a[i]==t){
            return i;
            break;
        }
    }
    return -1;
}
int main(){
    int arr[10]={1,4,2,7,3,9,4,45,82,99};
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