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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        queue<TreeNode*> node_queue;
        node_queue.push(root);
        while (!node_queue.empty()) {
            queue<TreeNode*> temp_queue;
            while (!node_queue.empty()) {
                temp_queue.push(node_queue.front());
                node_queue.pop();
            }
            vector<int> cur_layer_vals;
            while (!temp_queue.empty()) {
                TreeNode* cur_node = temp_queue.front();
                cur_layer_vals.emplace_back(cur_node->val);
                temp_queue.pop();
                if (cur_node->left) {
                    node_queue.push(cur_node->left);
                }
                if (cur_node->right) {
                    node_queue.push(cur_node->right);
                }
            }
            res.emplace_back(cur_layer_vals);
        }
        return res;
    }
};
