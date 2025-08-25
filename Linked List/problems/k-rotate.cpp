//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/*

*/

class Solution {
  public:
  
    int getLength(Node* head){
        int res=0;
        while(head){
            res++;
            head = head->next;
        }
        return res;
    }
  
    Node* rotate(Node* head, int k) {
        // Your code here
        int len = getLength(head);
        k = k%len;
        if(k==len || k==0)return head;
        
        int i=1;
        Node* curr = head;
        while(i<k){
            i++;
            curr = curr->next;
        }
        Node* next = curr->next;
        curr->next=NULL;
        
        // ab next part par iterate krunga aur uske end ko first ke 
        //  head se jood dunga
        
        Node* temp = next;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = head;
        
        return next;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        Node* head = nullptr;

        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
        cout << "~\n";
    }
    return 1;
}

// } Driver Code Ends