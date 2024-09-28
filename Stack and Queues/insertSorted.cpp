#include <iostream>
#include<stack>
using namespace std;

void insertSorted(stack<int>& s , int val){
    //Base Case
    if(s.empty() || s.top()<val){
        s.push(val);
        return;
    }
    
    int topE = s.top();
    s.pop();
    if(topE > val){
        insertSorted(s,val);
        s.push(topE);
    }
}

void printStack(stack<int>& s){
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}

int main() {
    
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    insertSorted(s,15);
    printStack(s);
    return 0;
}