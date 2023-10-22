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
    TreeNode * res = nullptr;
    int check(TreeNode* root, int p, int q){
        int self = 0;
        if(root->val == p || root->val == q){
            self += 1;
        }
        if(root->left){
            if(root->right){
                self += check(root->left, p, q) + check(root->right, p, q);
            }else{
                self += check(root->left, p, q);
            }
        }else{
            if(root->right){
                self += check(root->right, p, q);
            }
        }
        // cout << root->val << " "<<self <<endl;
        if(self == 2 && res == nullptr){
            res = root;
        }
        return self;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        check(root, p->val, q->val);
        return res;
    }
};
