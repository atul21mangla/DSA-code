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

TreeNode* buildTree(){
    int n;
    cin>>n;
    if(n==-1)return NULL;

    TreeNode* node = new TreeNode(n);
    cout<<"Enter the left child for node "<<n<<" : "<<endl;
    node->left = buildTree();
    cout<<"Enter the right child for node "<<n<<" : "<<endl;
    node->right = buildTree();
}

int main(){
    cout<<"Enter the root node : "<<endl;
    TreeNode* root = buildTree();
    return 0;
}