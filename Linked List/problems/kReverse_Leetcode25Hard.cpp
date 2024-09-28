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

int getlength(Node* temp){
    int len=0;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

Node* solve(Node* head , int k){
    //! calculate length of list i got in this function 
    //! if its less than k then simply return without doing anything
    // Base case
    if(head==NULL){
        return head;
    }
    if(getlength(head)<k){  //* this condition is present for some platforms 
        return head;
    }

    // Recursive case
    Node* prev = NULL;
    Node* curr = head;
    int i=1;
    while(i<=k and curr!=NULL){
        Node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        i++;
    }
    Node* hff = solve(curr,k);
    head->next = hff;
    return prev;
}

int main(){
    int arr[] = {10,20,30,40,50,60};
    int k=4;
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next = new Node(arr[4]);
    head->next->next->next->next->next = new Node(arr[5]);
    head = solve(head,k);
    printList(head);
    return 0;
}