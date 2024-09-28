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

bool parent(TreeNode* root , int a , int b){
    if(!root) return false;

    if(root->left!=NULL and root->right!=NULL){
        if((root->left->val==a && root->right->val==b) or (root->left->val==b && root->right->val==a))
        return true;
    }
    
    return parent(root->left,a,b) || parent(root->right,a,b);
}

bool cousinsOrNot(TreeNode* root , int a , int b){
    queue<TreeNode*>q;
    q.push(root);
    int level=0;
    int l1 = -1 , l2 = -1;
    while(!q.empty()){
        int size = q.size();
        for(int i=0;i<size;i++){
            TreeNode* temp = q.front();
            q.pop();
            if(temp->val==a){
                l1 = level;
            }
            if(temp->val==b)l2 = level;
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
        level++;
        if(l1!=l2)return false;
        if(l1!=-1)break;
    }
    return !parent(root,a,b);
}

int main(){
    vector<int>arr = {10,20,40,-1,-1,50,70,-1,-1,-1,30,-1,60,-1,-1}; // preorder array
    int idx=0;
    TreeNode* root = buildTree(arr,idx);
    if(cousinsOrNot(root,40,60))cout<<"YES";
    else cout<<"NO";
}