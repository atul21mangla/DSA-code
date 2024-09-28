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

void morrisInorder(TreeNode* root , vector<int>& inorder){
    TreeNode* curr = root;
    while(curr!=NULL){
        // 1. if curr->left is null then print curr node and move to left
        if(curr->left==NULL){
            inorder.push_back(curr->val);
            curr = curr->right;
        }
        else{   // curr->left is not null then //! 1st check whether curr ka left is already visited or not , if not visited 
            TreeNode* pred = curr->left;   //!then firstly link connection to curr from rightmost node in LST then move curr to left, if visited then
            while(pred->right && pred->right!=curr){   //?   delete the link and print curr node and move right.. 
                pred = pred->right;
            }                
            if(pred->right==NULL){
                pred->right = curr;
                curr = curr->left;
            }
            else{
                pred->right=NULL;
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
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
    vector<int>inorder;
    morrisInorder(root,inorder);
    cout<<"Morris Inorder Traversal is : "<<endl;
    for(auto x:inorder)cout<<x<<" ";
    cout<<endl;
    return 0;
}  
    /*                                            2
                                                /   \
                                               7     6
                                              / \   / \
                                             3   3 4   5
                                            / \
                                           1   8
    */