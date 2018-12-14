/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
*/
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
    TreeNode* buildTree(const vector<int>& postorder, int& post_idx, const vector<int>& inorder, int l , int h) {
        if(post_idx < 0 || l > h)   return NULL;
        TreeNode* root = new TreeNode(postorder[post_idx--]);
        if(post_idx < 0 || l == h)  return root;
        int i;
        for(i = l; i <= h; ++i)
            if(inorder[i] == root->val)   break;
        root->right = buildTree(postorder, post_idx, inorder, i+1, h);
        root->left = buildTree(postorder, post_idx, inorder, l, i-1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int post_idx = postorder.size()-1;
        return buildTree(postorder, post_idx, inorder, 0, inorder.size()-1);
    }
};
