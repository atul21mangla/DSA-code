#include<bits/stdc++.h>
using namespace std;

vector<int>preOrder;
vector<int>inOrder;
vector<int>postOrder;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        this->val = x;
        this->left = NULL;
        this->right = NULL;
    }
};
TreeNode* buildTree(vector<int>arr , int& i){
    int n = arr.size();
    if(i>=n or arr[i]==-1){
        i++;
        return NULL;
    } 

    TreeNode* root = new TreeNode(arr[i]);
    i++;
    root->left = buildTree(arr,i);
    root->right = buildTree(arr,i);
    return root;
}

void preOrderTraversal(TreeNode* root){
    // Base case
    if(!root)return;

    // Recursive Case
    preOrder.push_back(root->val);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(TreeNode* root){
    // Base case
    if(!root)return;

    // Recursive Case
    inOrderTraversal(root->left);
    inOrder.push_back(root->val);
    inOrderTraversal(root->right);
}

void postOrderTraversal(TreeNode* root){
    // Base case
    if(!root)return;

    // Recursive Case
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    postOrder.push_back(root->val);
}

int main(){
    vector<int>arr = {10,20,40,-1,-1,50,70,-1,-1,-1,30,-1,60,-1,-1}; // preorder array
    int idx=0;
    TreeNode* root = buildTree(arr,idx);

    preOrderTraversal(root);
    cout<<"PreOrder Traversal"<<endl;
    for(auto x: preOrder){
        cout<<x<<" ";
    }cout<<endl;


    inOrderTraversal(root);
    cout<<"InOrder Traversal"<<endl;
    for(auto x: inOrder){
        cout<<x<<" ";
    }cout<<endl;


    postOrderTraversal(root);
    cout<<"PostOrder Traversal"<<endl;
    for(auto x: postOrder){
        cout<<x<<" ";
    }cout<<endl;

    return 0;
}