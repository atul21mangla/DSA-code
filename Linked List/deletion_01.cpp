#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

void insertAtHead(Node*& head , int val)
{
    Node* n = new Node(val);
    n->next = head;
    head = n;
}

void printList(Node* head){
    while(head != NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void deleteAtHead(Node*& head){

    if(head==NULL){ // list is empty..
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

int main(){
    Node* head = NULL;
    insertAtHead(head,40);
    insertAtHead(head,30);
    insertAtHead(head,20);
    insertAtHead(head,10);
    printList(head);

    deleteAtHead(head);
    printList(head);

    deleteAtHead(head);
    printList(head);
    return 0;
}