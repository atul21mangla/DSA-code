#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
    int* arr;
    int size;
    int top;

    Stack(int capacity){
        arr = new int[capacity];
        size = capacity;
        top=-1;
    }

    void push(int val){
        if(top==size-1){
            cout<<"Stack Overflow...cannot push elements Stack is Full." << endl;
            cout<<"--------------------------------------------------------------"<<endl;
            return;
        }
        top++;
        arr[top] = val;
    }

    int pop(){
        if(top==-1){
            cout<<"Stack Underflow....Stack is empty."<<endl;
            cout<<"------------------------------------------------------"<<endl;
            return -1;
        }
        else{
            int ans = arr[top];
            top--;
            return ans;
        }
    }

    int getTop(){
        if(top==-1)return -1;
        return arr[top];
    }

    int getSize(){
        return top+1;
    }
    void print(){
        cout << "\nPrinting Stack." << endl;
        for(int i=top;i>=0;i--){
            cout << arr[i] << endl;
        }
        cout << "-----------------------------------------------------------------" << endl;
    }
};

int main(){
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.print();
    s.pop();
    cout<<s.getTop();
    s.push(10);
    s.print();
}