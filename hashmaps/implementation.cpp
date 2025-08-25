#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int key;
    int val;
    Node* next;

    Node(int key,int val){
        this->key = key;
        this->val = val;
        this->next = NULL;
    }
};

class hashMap{
    int m;
    int n;
    double l;  // threshold for Load Factor
    Node** t;

    int hashfun(int k){
        return k%n;
    }

    void transfer(Node* head){
        // 1. rehash (k,v) pairs present in LL represented by "head"
        // pointer to updated hashMap
        Node* temp = head;
        while(temp){
            insert(temp->key,temp->val);
            temp = temp->next;
        }

        // 2. release memory allocated for the LL represented by "head" pointer
        while(head){
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void rehash(){
        // 1. save pointer to current hashmap and its capacity
        Node** oldT = t;
        int oldN = n;

        // 2. create a hashMap with doublemcapacity
        n = 2*n;
        t = new Node*[n];
        for(int i=0;i<n;i++){
            t[i] = NULL;
        }
        m = 0;
        // 3. transfer (k,v) from old hashMap to updated hashMap
        for(int i=0;i<oldN;i++){
            transfer(oldT[i]);
        }

        // 4. release the memory allocated to old hashMap 
        delete [] oldT;
    }

    public:
    hashMap(int n = 5 , double l = 0.7){
        this->n = n;
        this->m = 0;
        this->l = l;
        t = new Node*[n];
        for(int i=0;i<n;i++){
            t[i] = NULL;
        }
    }

    void insert(int k , int v){
        // 1. transform the key into hash index using hash function
        int hashIndex = hashfun(k);
        // 2. create a node with given(k,v) and insert it at head
        // of Linked List stored at hash index
        Node* node = new Node(k,v);

        // 3. update the pointer to head of LL such that it holds
        // address of newly created node
        node->next = t[hashIndex];
        t[hashIndex] = node;
        m++;

        // 4. rehash , if load factor exceeds the threshold.
        double LF = (double)m/n;
        if(LF>l){
            // rehash ....
            cout<<"Rehashing due to Load Factor = "<<LF<<endl;
            rehash();
        }


    }

    Node* find(int k){
        int hashIndex = hashfun(k);
        Node* temp = t[hashIndex];
        while(temp!=NULL){
            if(temp->key==k)break;
            temp = temp->next;
        }
        return temp;
    }

    void erase(int k){
        int hashIndex = hashfun(k);
        Node* temp = t[hashIndex];
        Node* prev = NULL;
        if(temp==NULL)return;

        // check if we have to delete head node
        if(temp->key==k){
            t[hashIndex] = temp->next;
            delete(temp);
            m--;
            return;
        }
        while(temp){
            if(temp->key==k){
                prev->next = temp->next;
                delete(temp);
                m--;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
    }

    void printLinkedList(Node* head){
        Node* temp = head;
        while(temp){
            cout<<"("<<temp->key<<" , "<<temp->val<<")"<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    void printHashMap(){
        cout<<"Printing hash map : "<<endl;;
        for(int i=0;i<n;i++){
            cout<<i<<" : ";
            printLinkedList(t[i]);
        }
        cout<<endl;
    }

    int& operator[](int k){
        Node* temp = find(k);
        if(temp==NULL){
            // matlab key nhi mila hai
            int v; // garbage hai abhi isme
            insert(k,v);
            temp = find(k);
        }
        return temp->val;
    }

};
int main(){
    hashMap hm;
    hm.insert(2,4);
    hm.insert(3,9);
    hm.insert(7,49);
    hm.printHashMap();

    int key = 7;
    Node* temp = hm.find(key);
    if(temp){
        cout<<temp->val<<endl;
    }
    else{
        cout<<key<<" not found."<<endl;
    }

    hm.erase(7);
    hm.printHashMap();
    cout<<hm[2]<<endl;

    hm.insert(8,64);
    hm.printHashMap();
    hm.insert(4,16);
    hm.printHashMap();

    //! update the value of key 8 from 64 to 0
    hm[8] = 0; // iske liye mene return by reference kiya hai
    // bcuz kya hota .. (49=0) but ye syntax wrong ho jata
    hm.printHashMap();

    hm[12] = 144;
    hm.printHashMap();
    return 0;
}