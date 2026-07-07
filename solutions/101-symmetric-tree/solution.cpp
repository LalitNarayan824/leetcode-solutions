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


    bool same(TreeNode* l , TreeNode* r){
        if(!l && !r) return true;
        if((!l && r) || (l && !r)) return false;
        if(l->val!=r->val) return false;

        bool out = 0 , in =0;

        out = same(l->left , r->right);
        in = same(l->right , r->left);

        return out && in;


    }


    bool isSymmetric(TreeNode* root) {
        // there will always be a root accn to quesiton 
        return same(root->left , root->right);
    }
};