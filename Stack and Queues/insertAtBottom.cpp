#include<iostream>
#include<stack>
using namespace std;

void insertAtbottom(stack<int>& s , int val){
    //Base Case
    if(s.empty()){
        s.push(val);
        return;
    }
    int x = s.top();
    s.pop();
    insertAtbottom(s,val);
    s.push(x);
}

void print(stack<int>s){
    cout<<"Printing stack"<<endl;
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    cout<<"--------------------------------------------"<<endl;
}
int main(){
    stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(5);
    insertAtbottom(s,10);
    s.push(100);
    insertAtbottom(s,33);
    print(s);
}