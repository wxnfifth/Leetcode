class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
		return 0;
	}
        //check left and right sub node
        // if h_left == h_right, complete sub tree
        // if h_left < h_right, sum of left and right
        int h_left = 0;
	TreeNode* left = root;
	while (left != nullptr) {
		left = left->left;
		h_left++;
	}
	int h_right = 0;
	TreeNode* right = root;
	while (right != nullptr) {
		right = right->right;
		h_right++;
	}
	if (h_left == h_right) {
		return (1 << h_left) - 1;
	}
	return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
