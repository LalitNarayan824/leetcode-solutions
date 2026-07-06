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


    unordered_map<long long, int> mp;

    void f(TreeNode* root , long long sum , int &target, int &ans){
        if(!root) return ;

        sum+= root->val;
        if(mp.count(sum-target)) ans+=mp[sum-target];
        mp[sum]++;

        f(root->left , sum , target , ans);
        f(root->right , sum , target , ans);

        if(mp[sum]==1) mp.erase(sum);
        else mp[sum]--;



    }


    int pathSum(TreeNode* root, int targetSum) {
        mp[0]=1;
        int ans=0;
        long long sum=0;
        f(root , sum , targetSum , ans );

        return ans;
    }
};