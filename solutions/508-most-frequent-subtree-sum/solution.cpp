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
    unordered_map<int, int> freq;

    int sum(TreeNode* root){
        if(!root) return 0;

        int left = sum(root->left);
        int right = sum(root->right);

        freq[root->val+left+right]++;
        return root->val+left+right;

    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        int maxF = -1;
        vector<int> ans;
        int rootSum = sum(root);
        // freq[rootSum]++;
        for(auto it : freq){
            if(it.second > maxF){
                maxF = it.second;
                ans.clear();
                ans.push_back(it.first);
            }
            else if(it.second==maxF){
                ans.push_back(it.first);
            }
        }

        return ans;    
    }
};