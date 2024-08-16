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

ListNode* getSum(ListNode* head1 , ListNode* head2){
    ListNode* dummyNode = new ListNode(-1);
    ListNode* current = dummyNode;
    ListNode* t1 = head1;
    ListNode* t2 = head2;
    int carry=0;
    while(t1!=NULL || t2!=NULL || carry){
        int sum = carry;
        if(t1)sum += t1->val;
        if(t2)sum += t2->val;
        ListNode* newNode = new ListNode(sum%10);
        carry = sum/10;
        current->next = newNode;
        current = current->next;
        if(t1)t1 = t1->next;
        if(t2)t2 = t2->next;
    }
    return dummyNode->next;
}

int main(){
    int arr1[] = {2,5,8};
    int arr2[] = {4,6,1,9,9,2};

    ListNode* head1 = new ListNode(arr1[0]);
    head1->next = new ListNode(arr1[1]);
    head1->next->next = new ListNode(arr1[2]);

    ListNode* head2 = new ListNode(arr2[0]);
    head2->next = new ListNode(arr2[1]);
    head2->next->next = new ListNode(arr2[2]);
    head2->next->next->next = new ListNode(arr2[3]);
    head2->next->next->next->next = new ListNode(arr2[4]);
    head2->next->next->next->next->next = new ListNode(arr2[5]);

    ListNode* ansHead = getSum(head1,head2);
    printList(ansHead);
}