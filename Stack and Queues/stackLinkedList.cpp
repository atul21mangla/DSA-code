#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(int val){
        this->val = val;
        this->next = NULL;
    }
};

class Stack{
    public:

    int size;
    ListNode* top;

    Stack(){
        size=0;
        top=NULL;
    }
    void push(int val){
        ListNode* node = new ListNode(val);
        if(top==NULL){
            top = node;
        }
        else{
            node->next = top;
            top = node;
        }
        size++;
    }

    int pop(){
        if(top==NULL){
            cout<<"\n Stack empty..\n";
            return -1;
        }
        ListNode* temp = top;
        int ans = top->val;
        top = top->next;
        delete temp;
        size--;
        return ans;
    }
    int getTop(){
        if(top==NULL)return -1;
        return top->val;
    }
    bool isEmpty(){
        return (top==NULL) ;
    }
    int getSize(){
        return size;
    }
    void print(){
        cout<<"\nPrinting Stack\n";
        ListNode* temp = top;
        while(temp!=NULL){
            cout<<temp->val<<endl;
            temp=temp->next;
        }
        cout<<"---------------------------------------------------------"<<endl;
    }
};

int main(){
    Stack s;
    s.push(1);
    s.push(4);
    s.push(7);
    s.push(-2);
    s.print();
    s.pop();
    s.print();
    cout<<"Top of Stack is = "<<s.getTop()<<endl;
    cout<<"Size of Stack is = "<<s.getSize()<<endl;
    (s.isEmpty()==0)?cout<<"Stack is not empty.":cout<<"Stack is empty."<<endl;
    s.push(100);
    s.push(99);
    s.print();
    cout<<"Size of Stack is = "<<s.getSize()<<endl;
}