//* Insertion at Tail

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

ListNode* getTail(ListNode* head){
    ListNode* current = head;
    while(current->next != NULL){
        current = current->next;
    }
    return current;
}

void insertAtHead(ListNode*& head , int val){  //! O(1) constant time
    ListNode* n = new ListNode(val);
    n->next = head;
    head = n;
}

void insertAtTail(ListNode*& head , int val){  //! O(n) due to getTAil()
    // if list is empty
    if(head == NULL){
        insertAtHead(head,val);
        return;
    }

    ListNode* n = new ListNode(val);
    ListNode* tail = getTail(head);
    tail->next = n;
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
    ListNode* head = NULL;
    insertAtHead(head,40);
    insertAtHead(head,30);
    insertAtHead(head,20);
    insertAtHead(head,10);

    insertAtTail(head,60);
    printList(head);
    return 0;
}