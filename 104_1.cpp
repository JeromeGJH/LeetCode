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
    int d = 0;
    void traverse(TreeNode * root, int k){
        if(root == nullptr)
            return;
        if(k == d){
            ++d;
        }
        traverse(root->left, k+1);
        traverse(root->right, k+1);
    }
    int maxDepth(TreeNode* root) {
        traverse(root, 0);
        return d;


    }
};
