#include<iostream>
using namespace std;
int main(){
    int arr[] = {1,2,3,4};
    int n= sizeof(arr)/sizeof(int);
    for(int i=0;i<(1<<n);i++){
        for( int j=0 ; j<n ; j++){
            if((i>>j) & 1 ){
                cout<< arr[j]<<" ";
            }
        }
        cout<< endl;
    }
}