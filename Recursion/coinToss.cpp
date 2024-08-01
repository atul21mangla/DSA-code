#include<iostream>
using namespace std;
// constraints n<=10

void f(int n , int i , char* ch , int j){
    if(i==n){
        ch[i]='\0';
        cout << ch << endl;
        return;
    }

    // 1. take heads
    ch[j]='H';
    f(n,i+1,ch,j+1);

    // 2. take tails
    ch[j]='T';
    f(n,i+1,ch,j+1);
}

void fModified(int n , int i , char* ch , int j){
    if(i==n){
        ch[i]='\0';
        cout << ch << endl;
        return;
    }

    // 1. take heads
    if(i==0 || ch[i-1]!='H'){
        ch[j]='H';
        fModified(n,i+1,ch,j+1);
    }

    // 2. take tails
    ch[j]='T';
    fModified(n,i+1,ch,j+1);
}

int main() {
    int n = 3;
    char ch[11];
    // f(n,0,ch,0);
    fModified(n,0,ch,0);
    return 0;
}