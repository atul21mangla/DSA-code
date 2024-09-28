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

void printPath(const vector<int>& path){
    for(auto x:path)cout<<x<<" ";
    cout<<endl;
}

void pathSumII(TreeNode* root , int target , vector<int>& path){
    // Base Case
    if(!root)return;
    if(root->left==NULL and root->right==NULL){
        if(root->val==target){
            path.push_back(root->val);
            printPath(path);
            path.pop_back();
        }
        return;
    }

    // Recursive Case
    path.push_back(root->val);
    pathSumII(root->left,target-root->val,path);
    pathSumII(root->right,target-root->val,path);
    path.pop_back();
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
    vector<int>path;
    pathSumII(root,target,path);
    
    return 0;
}