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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int small  = min(p->val, q->val);
        int large  = max(p->val, q->val);

        while(root!=nullptr){
            // p, q belong to the left subtree
            if(  root->val > large) root = root->left;
            // p, q belong to the right subtree
            else if(  root->val < small) root = root->right;
            // Now, small <= root.val <= large -> This root is the LCA between p and q
            else return root;
        }

        return nullptr;
    }
};