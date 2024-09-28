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

int countSumI(TreeNode* root){
    if(!root)return 0;

    return root->val + countSumI(root->left)+countSumI(root->right);
}
void countSumII(TreeNode* root , int& sum){
    if(!root)return;

    sum += root->val;
    countSumII(root->left,sum);
    countSumII(root->right,sum);
}

int main(){
    vector<int>arr = {10,20,40,-1,-1,50,70,-1,-1,-1,30,-1,60,-1,-1}; // preorder array
    int idx=0;
    TreeNode* root = buildTree(arr,idx);
    cout<<"Method I : "<<endl;
    cout<<"Total sum of all nodes in tree = "<<countSumI(root);
    cout<<"\nMethod II : "<<endl;
    int sum = 0;
    countSumII(root,sum);
    cout<<"Total sum of all nodes in tree = "<<sum;
}