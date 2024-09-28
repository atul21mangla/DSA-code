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

class Queue{
    public:
    ListNode* front;
    ListNode* rear;
    int currSize;
    int n;

    Queue(int size){
        n = size;
        currSize = 0;
        front = rear = NULL;
    }
    void push(int x){
        if(currSize==n){
            cout<<"Overflow"<<endl;
            return;
        }
        ListNode* node = new ListNode(x);
        if(front==NULL && rear==NULL){
            front = rear = node;
        }
        else{
            rear->next = node;
            rear = node;
        }
        currSize++;
    }
    void pop(){
        if(front==NULL && rear==NULL){
            cout<<"Underflow"<<endl;
            return;
        }
        ListNode* temp = front;
        if(front==rear){
            front = rear = NULL;
        }
        else{
            front = front->next;
        }
        delete(temp);
        currSize--;
    }
    int getFront(){
        if(front==NULL){
            return -1;
        }
        else{
            return front->val;
        }
    }
    int getRear(){
        if(rear==NULL){
            return -1;
        }
        else{
            return rear->val;
        }
    }
};

int main(){
    Queue q(3);

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.getFront() << endl;  // Should print 10
    cout << "Rear: " << q.getRear() << endl;   // Should print 30

    q.pop();
    cout << "Front after pop: " << q.getFront() << endl;  // Should print 20
    cout << "Rear after pop: " << q.getRear() << endl;
    q.pop();
    cout << "Front after pop: " << q.getFront() << endl;
    cout << "Rear after pop: " << q.getRear() << endl;
    q.pop();
    cout << "Front after pop: " << q.getFront() << endl;
    cout << "Rear after pop: " << q.getRear() << endl;
    q.pop();  // Should print "Underflow" since the queue is empty
    return 0;
}