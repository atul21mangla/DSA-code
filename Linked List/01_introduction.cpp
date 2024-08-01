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

int main(){
    ListNode* node = new ListNode(50);
    cout << node->val << endl;
    cout << (*node).val;
    return 0;
}