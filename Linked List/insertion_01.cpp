//* Insertion at Head

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

void insertAtHead(ListNode*& head , int val){
    ListNode* n = new ListNode(val);
    n->next = head;
    head = n;
}
/*
ListNode* insertAtHead(ListNode* head , int val){  //! alternate way
    ListNode* n = new ListNode(val);
    n->next = head;
    head = n;
    return head;
}
*/
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
    insertAtHead(head,50);
    //! head = insertAtHead(head,50);  alternate way as head should be updated after insertion at beggining
    insertAtHead(head,40);
    insertAtHead(head,30);
    insertAtHead(head,20);
    insertAtHead(head,10);
    printList(head);
    return 0;
}