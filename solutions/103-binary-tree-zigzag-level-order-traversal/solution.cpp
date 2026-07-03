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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;

        vector<vector<int>> ans;

        bool rtl = 1;

        if(root) q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> t;
            while(size--){
                TreeNode* temp = q.front();q.pop();
                t.push_back(temp->val);

                // if(rtl){
                //     if(temp->right) q.push(temp->right);
                //     if(temp->left) q.push(temp->left);
                // }
                // else{
                //     if(temp->left) q.push(temp->left);
                //     if(temp->right) q.push(temp->right);
                // }
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);

            }
            if(!rtl) reverse(t.begin(), t.end());
            ans.push_back(t);
            rtl = 1 - rtl;


        }

        return ans;
    }
};


