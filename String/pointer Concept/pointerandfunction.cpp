#include<bits/stdc++.h>
using namespace std;

// void increment(int x){
//     x++;
//     cout<<"inside function call "<<endl;             //! pasas by value
//     cout<<"x = "<<x<<endl;
// }
// int  main(){
//     int x = 2;
//     increment(x);
//     cout<<"outside function call"<<endl;
//     cout<<"x = "<<x<<endl;
// }

// void increment(int& a){
//     a++;                                          //! pass by reference
//     cout<<"inside function call "<<endl;
//     cout<<"a = "<<a<<endl;
// }
// int main(){
//     int a = 2;
//     increment(a);
//     cout<<"outside function call"<<endl;
//     cout<<"a = "<<a<<endl;
// }

void increment(int* a){
    (*a)++;
}

int main(){
    int a = 2;
    increment(&a);
    cout<<a<<endl;
}