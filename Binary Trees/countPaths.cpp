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

int countPath(TreeNode* root , int target){
    // Base Case
    if(!root)return 0;
    if(root->val==target)return 1;

    // Recursive Case
    int cnt=0;
    cnt += countPath(root->left,target-root->val);
    cnt += countPath(root->right,target-root->val);
    return cnt;
}

int main(){
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(7);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(3);
    root->left->left->left = new TreeNode(1);
    root->left->left->right = new TreeNode(8);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    
    int target = 12;
    cout<<countPath(root,target);
    return 0;
}