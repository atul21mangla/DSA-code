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

TreeNode* insert(TreeNode* root , int val){
    if(!root){
        TreeNode* node = new TreeNode(val);
        return node;
    }

    if(val>root->val){  // move to RST
        root->right = insert(root->right,val);
    }
    else 
    root->left = insert(root->left,val);

    return root;
}

void inorder(TreeNode* root)
{
    if(!root)return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
void levelOrder(TreeNode* root){
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        while(size--){
            TreeNode* temp = q.front();
            q.pop();
            cout<<temp->val<<" ";
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
        cout<<endl; 
    }
}

bool search(TreeNode* root , int key){
    if(!root)return false;

    if(key==root->val)return true;
    else if(key>root->val){
        return search(root->right,key);
    }
    else 
    return search(root->left,key);
}

int main(){
    TreeNode* root = NULL ;
    root = insert(root,10);
    root = insert(root,5);
    root = insert(root,15);
    root = insert(root,3);
    root = insert(root,7);
    root = insert(root,13);
    root = insert(root,17);
    root = insert(root,6);
    root = insert(root,14);
    cout<<"Inorder Traversal\n";
    inorder(root);
    cout<<"\nLevel order Traversal \n";
    levelOrder(root);

    //! searching operation
    int key = 17;
    if(search(root,key))
    cout<<"Key is found";
    else
    cout<<"Key is not found";
    return 0;
}