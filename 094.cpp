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
    vector<int> inorderTraversal(TreeNode* root) {
        //recursive trivial
        //iterative
        //use stack, go until the most left, back a node, again go until the most left
        TreeNode* t = root;
        stack<TreeNode*> stk;
        vector<int> ans;
        while (!stk.empty() || t != nullptr) {
            while (t != nullptr) {
                stk.push(t);
                t = t->left;
            }
            t = stk.top();
            ans.push_back(t->val);
            stk.pop();
            t = t->right;
        }
        return ans;
    }
};
