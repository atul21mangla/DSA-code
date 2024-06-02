#include<iostream>
using namespace std;

void reverse(int arr[],int i,int j){
    while(i<j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}

void right_rotatearray(int arr[],int n,int d){
    reverse(arr,0,n-1);
    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
}

void left_rotatearray(int arr[],int n,int d){
    reverse(arr,0,n-1);
    reverse(arr,0,d);
    reverse(arr,d+1,n-1);
}

void printarr(int arr[10],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[100];
    int n;
    cout<<"enter size of array :";
    cin>>n;
    cout<<"enter "<<n<<" input for array :";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int d;
    cout<<"enter rotation value :";
    cin>>d;
    d%=n;

    // right_rotatearray(arr,n,d);
    // cout<<"after right rotation";
    // printarr(arr,n);

    // left_rotatearray(arr,n,d);
    // cout<<"after left rotation"<<endl;
    // printarr(arr,n);
}