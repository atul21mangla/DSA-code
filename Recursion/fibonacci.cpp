#include<iostream>
using namespace std;

//? fibonacci series 
//! 0 , 1 , 1 , 2 , 3 , 5 , 8 , 13 , 21 , 34 , .............

int fibo(int n){
    if(n==1)return 1;
    if(n==0)return 0;

    return fibo(n-1) + fibo(n-2);
}

int main(){
    int n;
    cin>>n;
    cout<<fibo(n);
}