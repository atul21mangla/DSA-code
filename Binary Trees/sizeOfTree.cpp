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

int countI(TreeNode* root){
    if(!root)return 0;

    return 1+countI(root->left)+countI(root->right);
}
void countII(TreeNode* root , int& count){
    if(!root)return;
    count += 1;
    countII(root->left,count);
    countII(root->right,count);
}

void countLeaf(TreeNode* root , int& count){
    if(!root)return;
    if(root->left==NULL and root->right==NULL){
        count++;
        return;
    }
    else{
        countLeaf(root->left,count);
        countLeaf(root->right,count);
    }
}

int main(){
    vector<int>arr = {10,20,40,-1,-1,50,70,-1,-1,-1,30,-1,60,-1,-1}; // preorder array
    int idx=0;
    TreeNode* root = buildTree(arr,idx);
    cout<<"Method I : "<<endl;
    cout<<"Total nodes in tree = "<<countI(root);
    cout<<"\nMethod II : "<<endl;
    int count = 0;
    countII(root,count);
    cout<<"Total nodes in tree = "<<count;

    int c_leaf=0;
    countLeaf(root,c_leaf);
    cout<<"\nNumber of leaf nodes in tree = "<<c_leaf<<endl;
}