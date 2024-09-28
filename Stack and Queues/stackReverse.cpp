#include<bits/stdc++.h>
using namespace std;

void print(stack<int>st){
    while(!st.empty()){
        cout << st.top() <<endl;
        st.pop();
    }
}

void insertAtBottom(stack<int>& st , int x){   
    // Base Case
    if(st.empty()){
        st.push(x);
        return;
    }

    // Recursive Case
    int top_ele = st.top();
    st.pop();
    insertAtBottom(st,x);
    st.push(top_ele);
}

void reverse(stack<int>& st){
    // Base Case
    if(st.empty())return;

    // Recursive Case
    int top_ele = st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st,top_ele);
}

int main(){
   stack<int>st;
   st.push(10); 
   st.push(20); 
   st.push(30); 
   st.push(40); 
   st.push(50); 
   cout << "Before reversing : "<<endl;
   print(st);
   reverse(st);
   cout << "After reversing : "<<endl;
   print(st);
    return 0;
}