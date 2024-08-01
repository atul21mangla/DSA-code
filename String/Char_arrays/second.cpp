#include <bits/stdc++.h>
using namespace std;

void replaceChar(char arr[] , int n , char ori , char rep){
    for(int i=0; i<n; i++){
        if(arr[i] == ori){
            arr[i] = rep;
        }
    }
}
int  main(){
    char arr[100];
    cin>>arr;
    replaceChar(arr,100,'@','!');
    cout<<arr<<endl;
}