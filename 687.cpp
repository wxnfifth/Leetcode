/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int helper(TreeNode* t, int v) {
        if (t != nullptr && t->val == v) {
            int len_left = helper(t->left, v);
            int len_right = helper(t->right, v);
            return max(len_left, len_right) + 1;
        } else {
            return 0;
        }
    }
    
public:
    int longestUnivaluePath(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int len_left = helper(root->left, root->val);
        int len_right = helper(root->right, root->val);
        int len = len_left + len_right;
        int longest_left = longestUnivaluePath(root->left);
        int longest_right = longestUnivaluePath(root->right);
        return max(len, max(longest_left, longest_right));
    }
};
