/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return {};

        queue<TreeNode*>q;
        q.push(root);
        // vector<bool>vis;
        vector<int>ans;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                
                TreeNode* temp = q.front();
                q.pop();

                if(temp!=NULL && i==0)ans.push_back(temp->val);

                // explore its childrens
                if(temp->right!=nullptr){
                    q.push(temp->right);
                }

                if(temp->left!=nullptr){
                    q.push(temp->left);
                }
            }
        }
        return ans;
    }
};