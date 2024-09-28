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

TreeNode* buildTree(vector<int>& arr , int& i){
    if(i>=arr.size() or arr[i]==-1){
        i++;
        return NULL;
        
    }
    
    TreeNode* root = new TreeNode(arr[i]);
    i++;
    root->left = buildTree(arr,i);
    root->right = buildTree(arr,i);
    return root;
}
void find(TreeNode* root , int& l ,int& r , int pos){
    if(!root)return;

    l = min(l,pos);
    r = max(r,pos);
    find(root->left,l,r,pos-1);
    find(root->right,l,r,pos+1);
}

vector<int> topViewBFS(TreeNode* root){
    int l=0,r=0;
    find(root,l,r,0);
    vector<int>ans(r-l+1);
    vector<bool>visited(r-l+1,0);
    queue<TreeNode*>q;
    queue<int>index;
    q.push(root);
    index.push(-1*l);
    while(!q.empty()){
        TreeNode* temp = q.front();
        int idx = index.front();
        q.pop();
        index.pop();
        if(visited[idx]==0){      //! just remove visited concept for bottom view
            visited[idx]=1;
            ans[idx] = temp->val;
        }
        if(temp->left){
            q.push(temp->left);
            index.push(idx-1);
        }
        if(temp->right){
            q.push(temp->right);
            index.push(idx+1);
        }
    }
    return ans;
}
vector<int> topViewSum(TreeNode* root){
    int l=0,r=0;
    find(root,l,r,0);
    vector<int>ans(r-l+1);
    // vector<bool>visited(r-l+1,0);
    queue<TreeNode*>q;
    queue<int>index;
    q.push(root);
    index.push(-1*l);
    while(!q.empty()){
        TreeNode* temp = q.front();
        int idx = index.front();
        q.pop();
        index.pop();
        ans[idx] += temp->val;
        if(temp->left){
            q.push(temp->left);
            index.push(idx-1);
        }
        if(temp->right){
            q.push(temp->right);
            index.push(idx+1);
        }
    }
    return ans;
}

int main(){
    vector<int>arr = {10,20,40,-1,-1,50,70,-1,-1,-1,30,-1,60,-1,-1}; // preorder array        10
    int idx=0;                                                                          // 20    30
    TreeNode* root = buildTree(arr,idx);                                              // 40   50    60
    vector<int>top_view = topViewBFS(root);                                          //    70
    for(int x:top_view){
        cout<<x<<" ";
    }cout<<endl;

    vector<int>top_view_sum = topViewSum(root);
    for(int x:top_view_sum){
        cout<<x<<" ";
    }cout<<endl;
    return 0;
}