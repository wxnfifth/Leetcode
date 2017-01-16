/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    
private:
    TreeNode* deserializeHelper(const string& data, int& pos) {
        if (data[pos] == 'n') {
            pos += 2;
            return NULL;
        }
        string root_val;
        
        for (; pos < data.length() && data[pos] != 'n' && data[pos] != ',';++pos) {
            root_val += data[pos];
        }
        pos++;
        TreeNode* t = new TreeNode(stoi(root_val));
        t->left = deserializeHelper(data, pos);
        t->right = deserializeHelper(data, pos);
        return t;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) {
            return "n";
        }
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout << data << "\n";
        if (data.length() == 0) {
            return NULL;
        }
        int pos = 0;
        return deserializeHelper(data, pos);

    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));