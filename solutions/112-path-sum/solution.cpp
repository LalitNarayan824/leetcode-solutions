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


    bool f(TreeNode* root , int sum, int target){

        sum+=root->val;
        // if leaf check the sum and target
        if(!root->left && !root->right && sum==target) return true;

        bool left = false , right = false;

        if(root->left) left = f(root->left , sum , target);
        if(root->right) right = f(root->right , sum , target);

        return left || right;

    }


    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root){
            // if(targetSum==0) return true;
            return false;
        }
        int sum =0;
        return f(root ,  sum , targetSum);

    }
};