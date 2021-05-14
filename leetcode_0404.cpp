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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int sum = 0;
        stack<TreeNode*> node_stack;
        stack<bool> bool_stack;
        node_stack.push(root);
        bool_stack.push(false);     // left -> true, right -> false;
        while (!node_stack.empty()) {
            TreeNode* cur_node = node_stack.top();
            node_stack.pop();
            bool cur_bool = bool_stack.top();
            bool_stack.pop();
            if (!cur_node->left && !cur_node->right && cur_bool) {
                sum += cur_node->val;
            }
            if (cur_node->left) {
                node_stack.push(cur_node->left);
                bool_stack.push(true);
            }
            if (cur_node->right) {
                node_stack.push(cur_node->right);
                bool_stack.push(false);
            }
        }
        return sum;
    }
};
