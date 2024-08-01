#include<bits/stdc++.h>
using namespace std;

void printName(int count , string name){
    if(count==0)return;
    cout << name << endl;
    count--;
    printName(count,name);
}

int main(){
    int n;
    cin>>n;
    cin.ignore();  // prevents getline to read newline character
    string name;
    getline(cin,name);
    cout << "---------------------------------------------" << endl;
    printName(n,name);
    return 0;
}