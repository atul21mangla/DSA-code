#include<iostream>
using namespace std;

void goodSubarray(int arr[] ,int n, int d){
    int arr_sum = 0;
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++){
                cout<<arr[k]<<"";
                arr_sum += arr[k];
            }
            if(arr_sum%d==0){
                count++;
            }
            cout<<endl;
        }
        cout<<endl;
    }
    cout<<count;
}
int main(){
    int arr[] = {1,6,5,2,4,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int d = 6;
    goodSubarray(arr,n,d);
}