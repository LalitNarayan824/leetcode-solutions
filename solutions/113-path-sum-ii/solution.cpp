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

    // vector<vector<int>> temp;

    bool f(TreeNode* root , int &sum , int &target , vector<int>& t , vector<vector<int>> &ans){
        sum+= root->val;
        t.push_back(root->val);
        if(!root->left && !root->right && sum==target){
            ans.push_back(t);
            t.pop_back();
            sum-= root->val;
            return true;
        }

        bool left = 0 , right =0;

        if(root->left) left = f(root->left , sum , target , t, ans);
        if(root->right) left = f(root->right , sum , target , t , ans);

        t.pop_back();
        sum-= root->val;
        return left || right;
    }



    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};


        vector<vector<int>> ans;
        int sum=0;
        vector<int> t;

        bool lalit = f(root,  sum , targetSum , t, ans);

        // ans = temp;
        return ans;
    }
};