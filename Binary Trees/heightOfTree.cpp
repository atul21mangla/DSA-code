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

int getHeight(TreeNode* root){
    // Base Case
    if(!root)return 0;   // return -1 if counting edges
    // Recursive Case
    return (1 + max(getHeight(root->left) , getHeight(root->right)));
}

int main(){
    vector<int>arr = {10,20,40,-1,-1,50,70,-1,-1,-1,30,80,-1,-1,60,-1,90,100,-1,-1,-1}; // preorder array
    int idx=0;
    TreeNode* root = buildTree(arr,idx);
    cout<<"Height of tree is = "<<getHeight(root);
}