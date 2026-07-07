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

    bool same(TreeNode* p , TreeNode* q){
        if(!p && !q) return true;
        if((!p && q) || (p && !q)) return false;
        if(p->val!=q->val) return false;

        bool left =0 , right =0;
        left = same(p->left , q->left);
        right = same(p->right , q->right);

        return left && right;

    }


    




    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(root->val==subRoot->val && same(root,  subRoot) ) return true;

        bool left = 0 , right =0;

        left = isSubtree(root->left , subRoot);            
        right = isSubtree(root->right , subRoot);            

        return left || right;
    }
};