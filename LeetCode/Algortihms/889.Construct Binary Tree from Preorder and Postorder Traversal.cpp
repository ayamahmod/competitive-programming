/*
Return any binary tree that matches the given preorder and postorder traversals.

Values in the traversals pre and post are distinct positive integers.
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
private:
    TreeNode* buildTree(const vector<int>& pre, int& pre_idx, const vector<int>& post, int l, int h) {
        if(l > h || pre_idx >= pre.size())  return NULL;
        TreeNode* root = new TreeNode(pre[pre_idx++]);
        if(pre_idx >= pre.size() || l==h)   return root;
        int i;
        for(i = l; i <= h; ++i) {
            if(pre[pre_idx] == post[i])    break;
        }
        root->left = buildTree(pre, pre_idx, post, l, i);
        root->right = buildTree(pre, pre_idx, post, i+1, h-1);
        return root;
    }

public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = post.size();
        int pre_idx = 0;
        return buildTree(pre, pre_idx, post, 0, n-1);
    }
};
