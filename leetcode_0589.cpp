/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res_vec;
        if (!root) {
            return res_vec;
        }

        stack<Node*> node_stack;
        node_stack.push(root);
        while (!node_stack.empty()) {
            Node* cur_node = node_stack.top();
            res_vec.emplace_back(cur_node->val);
            node_stack.pop();
            for (auto iter = cur_node->children.rbegin(); iter != cur_node->children.rend(); ++iter) {
                node_stack.push(*iter);
            }
        }
        return res_vec;
    }
};
