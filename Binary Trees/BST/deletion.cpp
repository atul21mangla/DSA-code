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


TreeNode* findMinimum(TreeNode* root){
    while(root->left!=NULL){
        root = root->left;
    }
    return root;
}

TreeNode* deleteFromBST(TreeNode* root , int val){
    if(!root)return root;

    if(root->val==val){
        // if leaf node
        if(root->left==NULL and root->right==NULL){
            delete root;
            root = NULL;
        }
        // one child either left or right
        else if(root->left==NULL and root->right!=NULL){
            TreeNode* temp = root->right;
            delete root;
            root = temp;
        }
        else if(root->left!=NULL and root->right==NULL){
            TreeNode* temp = root->left;
            delete root;
            root = temp;
        }
        // two childs
        else{
            TreeNode* rightMin = findMinimum(root->right);
            swap(root->val,rightMin->val);
            root->right = deleteFromBST(root->right,val);
        }
    }
    else if(root->val>val){
        root->left = deleteFromBST(root->left,val);
    }
    else
    root->right = deleteFromBST(root->right,val);

    return root;
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
    cout<<"\nInorder Traversal\n";
    inorder(root);
    cout<<"\nLevel order Traversal \n";
    levelOrder(root);

    root = deleteFromBST(root,6);
    cout<<"\nInorder Traversal\n";
    inorder(root);

    root = deleteFromBST(root,13);
    cout<<"\nInorder Traversal\n";
    inorder(root);

    root = deleteFromBST(root,15);
    cout<<"\nInorder Traversal\n";
    inorder(root);
    return 0;
}