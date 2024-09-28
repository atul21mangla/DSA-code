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

bool pathSum(TreeNode* root , int target){
    // Base Case
    if(!root)return 0;
    if(root->left==NULL and root->right==NULL){
        return (root->val==target);
    }

    // Recursive Case
    pathSum(root->left,target-root->val) || pathSum(root->right,target-root->val);
}

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);
    int target = 22;
    if(pathSum(root,target))cout<<"Path Found"<<endl;
    else cout<<"Not found.";
    return 0;
}