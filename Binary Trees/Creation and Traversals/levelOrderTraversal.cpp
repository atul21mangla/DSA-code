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

void levelOrderTraversal(TreeNode* root , vector<int>& lvlOrder){
    if(!root)return;

    queue<TreeNode*>q;
    q.push(root);
    TreeNode* temp;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        lvlOrder.push_back(temp->val);
        if(temp->left)q.push(temp->left);
        if(temp->right)q.push(temp->right);
    }
}

int main(){
    vector<int>arr = {10,20,40,-1,-1,50,70,-1,-1,-1,30,-1,60,-1,-1}; // preorder array
    int idx=0;
    TreeNode* root = buildTree(arr,idx);

    vector<int>lvlOrder;
    levelOrderTraversal(root,lvlOrder);
    for(auto x:lvlOrder){
        cout<<x<<" ";
    }cout<<endl;
    return 0;
}