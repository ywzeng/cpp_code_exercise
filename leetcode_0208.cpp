class TrieNode {
public:
    bool is_end;
    map<char, TrieNode*> char_map;      // Key is char, value is the corresponding node.
    TrieNode(): is_end(false) {};
};

class Trie {
public:
    TrieNode* root_node;
    /** Initialize your data structure here. */
    Trie() {
        root_node = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur_node = root_node;
        for (auto &c: word) {
            auto node_iter = cur_node->char_map.find(c);
            if (node_iter != cur_node->char_map.end()) {
                cur_node = node_iter->second;
            } else {
                TrieNode* temp_node = new TrieNode();
                cur_node->char_map.insert(make_pair(c, temp_node));
                cur_node = temp_node;
            }
        }
        cur_node->is_end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur_node = root_node;
        for (auto &c: word) {
            auto node_iter = cur_node->char_map.find(c);
            if (node_iter == cur_node->char_map.end()) {
                return false;
            } else {
                cur_node = node_iter->second;
            }
        }
        return cur_node->is_end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur_node = root_node;
        for (auto &c: prefix) {
            auto node_iter = cur_node->char_map.find(c);
            if (node_iter == cur_node->char_map.end()) {
                return false;
            } else {
                cur_node = node_iter->second;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
