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

public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* t = root;
        TreeNode* ans = nullptr;
        while (t != nullptr) {
            if (t->val > p->val) {
                ans = t;
                t = t->left;
            } else {
                t = t->right;
            }
        }
        return ans;
    }
};
