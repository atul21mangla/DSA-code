#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int val){
        this->val=val;
        this->next=NULL;
    }
    Node(int val,Node* next){
        this->val=val;
        this->next=next;
    }
};

void printList(Node* head){
    if(head==NULL){
        cout << "List is empty.";
    }
    else{
        while(head!=NULL){
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
}

Node* reverseRecursive(Node* head){
    // Base case
    if(head->next==NULL){
        return head;
    }
    // Recursive case
    Node* headFromFriend = reverseRecursive(head->next);
    head->next->next = head;
    head->next=NULL;
    return headFromFriend;
}

Node* reverseIterative(Node* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    Node* prev = NULL;
    Node* curr = head;
    while(curr!=NULL){
        Node* temp = curr->next;
        curr->next = prev;
        prev=curr;
        curr=temp;
    }
    return prev;
}

int main(){
    int arr[] = {10,20,30,40,50};
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next = new Node(arr[4]);
    cout << "List before reversing" << endl;
    printList(head);
    cout << "List after reversing." << endl;
    // head = reverseIterative(head);
    head = reverseRecursive(head);
    printList(head);
    return 0;
}