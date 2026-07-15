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
    vector<int> inOrder;
    void dfs(TreeNode* root) {
        if(!root)
            return;
        dfs(root -> left);
        inOrder.push_back(root -> val);
        dfs(root -> right);
        return;
    }
    bool isValidBST(TreeNode* root) {
        dfs(root);
        for(int i = 1; i < inOrder.size(); i++) {
            if(inOrder[i-1] >= inOrder[i])
                return false;
        }
        return true;
    }
};
