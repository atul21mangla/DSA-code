#include<bits/stdc++.h>
using namespace std;

class Queue{
    public:
    int* arr;
    int currSize;
    int n;
    int front;
    int rear;

    Queue(int size){
        arr = new int[size];
        n = size;
        currSize = 0;
        front = -1;
        rear = -1;
    }

    void push(int x){
        if(currSize==n){
            cout<<"Overflow"<<endl;
            return;
        }
        else if(front==-1 && rear==-1){
            rear++;
            front++;
        }
        else{
            rear = (rear+1)%n;
        }
        arr[rear]=x;
        currSize++;
    }

    void pop(){
        if(front==-1 && rear==-1){
            cout<<"underflow"<<endl;
            return;
        }
        else if(front==rear){
            front=rear=-1;
        }
        else{
            front = (front+1)%n;
        }
        currSize--;
    }
    int getfront(){
        if(front==-1 && rear==-1){
            return -1;
        }
        else return arr[front];
    }
    int getrear(){
        if(front==-1 && rear==-1){
            return -1;
        }
        else return arr[rear];
    }
    int getsize(){
        return currSize;
    }
};

int main(){
    Queue q(5);
    q.push(1);
    q.push(10);
    q.push(11);
    cout<<"Front of queue is = "<<q.getfront()<<endl;
    q.pop();
    cout<<"Front of queue is = "<<q.getfront()<<endl;
    cout<<"size of queue is = "<<q.getsize()<<endl;
    q.pop();
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(42);
    cout<<"Front of queue is = "<<q.getfront()<<endl;
    cout<<"rear of queue is = "<<q.getrear()<<endl;
    cout<<"size of queue is = "<<q.getsize()<<endl;
    return 0;
}