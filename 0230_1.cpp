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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> nodes;
        TreeNode * n = root;
        TreeNode * tmp;
        nodes.push(n);
        while(n->left){
            n = n->left;
            nodes.push(n);
        }
        int i = 0;
        while(i < k){
            n = nodes.top();
            nodes.pop();
            if(n->right){
                tmp = n->right;
                nodes.push(tmp);
                while(tmp->left){
                    tmp = tmp->left;
                    nodes.push(tmp);
                }
            }
            ++i;
        }
        return n->val;


    }
};
