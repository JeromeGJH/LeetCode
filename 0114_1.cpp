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
    TreeNode * p;
    void Traverse(TreeNode* node){
        if(node->left){
            p->right = new TreeNode(node->left->val);
            p = p->right;
            
            Traverse(node->left);
        }
        
        if(node->right){
            p->right = new TreeNode(node->right->val);
            p = p->right;
           
            Traverse(node->right);
        }
        return;
    }

    void flatten(TreeNode* root) {
        if(root == nullptr){
            return;
        }
        TreeNode * tmp = new TreeNode(root->val);
        p = tmp;
        Traverse(root);
        root->left = nullptr;
        root->right = tmp->right;
        

        return;


    }
};
