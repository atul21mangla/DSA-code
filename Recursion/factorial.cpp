#include<iostream>
using namespace std;

int fact(int n){
    //* base case
    if(n==1)return 1;

    return n*fact(n-1);
}

int pow(int n){      //! 2^n calculate kr rhe hai
    //* Base case
    if(n==0)return 1;;

    return 2* pow(n-1);
}

// void print(int n){      //? tail recursion
//     //* base case
//     if(n==0)return;

//     cout << n << " ";
//     print(n-1);
// }

void print(int n){      //? Head recursion
    //* base case
    if(n==0)return;

    print(n-1);
    cout << n << " ";
}

int main(){
    int n;
    cin>>n;
    // cout<<fact(n);
    // print(n);
    cout << pow(n);
    return 0;
}