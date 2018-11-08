// Serialization is the process of converting a data structure or object into a
// sequence of bits so that it can be stored in a file or memory buffer, or
// transmitted across a network connection link to be reconstructed later in the
// same or another computer environment.
//
// Design an algorithm to serialize and deserialize a binary tree. There is no
// restriction on how your serialization/deserialization algorithm should work. You
// just need to ensure that a binary tree can be serialized to a string and this
// string can be deserialized to the original tree structure.

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
    queue<string> splitStr(const string& s) {
        string s_copy(s);
        smatch m;
        regex e ("([-]*[0-9]+|null)(,|$)");
        queue<string> q;
        while (std::regex_search (s_copy,m,e)) {
            q.push(m[1]);
            s_copy = m.suffix().str();
        }
        return q;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "null";
        string s = "";
        s += to_string(root->val);
        s += ","+serialize(root->left);
        s += ","+serialize(root->right);
        return s;
    }

    TreeNode* constructTree(queue<string>& q) {
        if(q.size() == 0) return NULL;
        string val = q.front(); q.pop();
        if(val == "null") return NULL;
        TreeNode* r = new TreeNode(stoi(val));
        r->left = constructTree(q);
        r->right = constructTree(q);
        return r;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q = splitStr(data);
        TreeNode* head = constructTree(q);
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
