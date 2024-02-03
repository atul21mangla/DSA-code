#include<iostream>
using namespace std;

void search(int a[10],int t){
    bool flag=false;
    for(int i=0;i<10;i++){
        if(a[i]==t){
            cout<<i<<" ";
            flag=true;
        }
    }
    if(flag==false)cout<<"Element not found";
}
int main(){
    int arr[10]={1,3,5,7,9,2,3,5,6,1};
    int t;
    cout<<"enter target to be searched :";
    cin>>t;
    search(arr,t);
    return 0;
}