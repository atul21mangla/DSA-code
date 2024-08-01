//* Insertion at given Index

#include<iostream>
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

ListNode* getNode(ListNode* head , int j){
    //! return the address of the node present at the jth index of the given LinkedList
    while(head != NULL && j--){
        head = head->next;
    }
    return head;
}

void insertAtHead(ListNode*& head , int val){  //! O(1) constant time
    ListNode* n = new ListNode(val);
    n->next = head;
    head = n;
}

void insertAtIndex(ListNode*& head , int index , int val){

    if(index == 0){
        insertAtHead(head,val);
        return;
    }

    ListNode* n = new ListNode(val);
    ListNode* prev = getNode(head,index-1);

    if(prev == NULL){
        cout<<"Index out of bounds"<<endl;
        return;
    }

    n->next = prev->next;
    prev->next = n;
}

void printList(ListNode* head){

    if(head == NULL){
        cout << "List is empty." << endl;
    }

    while(head!=NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    ListNode* head = NULL; //* initially List is empty

    insertAtHead(head,40);
    insertAtHead(head,30);
    insertAtHead(head,20);
    insertAtHead(head,10);
    printList(head);

    insertAtIndex(head,2,90);  //* desired list 10 -> 20 -> 90 -> 30 -> 40
    printList(head);
    return 0;
}