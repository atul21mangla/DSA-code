#include<bits/stdc++.h>
using namespace std;

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

TreeNode* buildTree(vector<int>arr){
    if(arr[0]==-1)return NULL;
    int n = arr.size();
    queue<TreeNode*>q;
    TreeNode* root = new TreeNode(arr[0]);
    q.push(root);
    int i=1;
    while(!q.empty() and i<n){
        TreeNode* curr = q.front();
        q.pop();
        if(i<n and arr[i]!=-1){
            curr->left = new TreeNode(arr[i]);
            q.push(curr->left);
        }i++;
        if(i<n and arr[i]!=-1){
            curr->right = new TreeNode(arr[i]);
            q.push(curr->right);
        }i++;
    }
    return root;
}

void preOrderTraversal(TreeNode* root , vector<int>& preorder){
    // Base case
    if(!root)return;

    // Recursive Case
    preorder.push_back(root->val);
    preOrderTraversal(root->left,preorder);
    preOrderTraversal(root->right,preorder);
}


int main(){
    vector<int>arr = {1,2,3,10,4,7,5}; // level order array given
    TreeNode* root = buildTree(arr);              
    vector<int>preOrder;
    preOrderTraversal(root,preOrder);
    for(auto x:preOrder){
        cout<<x<<" ";
    }cout<<endl;
    return 0;
}
/*
            1
       2         3
   10      4   7     5

*/