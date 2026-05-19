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
    bool bal = true;
    int dfs(TreeNode* root) {
        if(!root)
            return 0;
        int left = dfs(root -> left);
        int right = dfs(root -> right);
        if(right > left && right - left > 1)
            bal = false;
        else if(left > right && left - right > 1)
            bal = false;
        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        dfs(root);
        return bal;
    }
};
