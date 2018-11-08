// Given an integer n, generate all structurally unique BST's
// (binary search trees) that store values 1 ... n.

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
    vector<TreeNode*> constructTrees(int st, int end) {
        vector<TreeNode*> v;
        if(st > end) v.push_back(NULL);
        for(int i = st; i <= end; ++i) {
            vector<TreeNode*> leftSubTrees = constructTrees(st, i-1);
            vector<TreeNode*> rightSubTrees = constructTrees(i+1, end);
            for(int l = 0; l < leftSubTrees.size(); ++l) {
                for(int r = 0; r < rightSubTrees.size(); ++r) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftSubTrees[l];
                    root->right = rightSubTrees[r];
                    v.push_back(root);
                }
            }
        }
        return v;
    }

    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> v;
        if(n < 1) return v;
        v = constructTrees(1, n);
        return v;
    }
};
