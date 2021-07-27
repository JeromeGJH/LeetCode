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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        vector<int> lres;
        vector<int> rres;
        if(root == nullptr){
            return res;
        }
        res.push_back(root->val);
        if(root->left != nullptr){
            lres= preorderTraversal(root->left);
            res.insert(res.end(), lres.begin(), lres.end());
        }
        if(root->right != nullptr){
            rres= preorderTraversal(root->right);
            res.insert(res.end(), rres.begin(), rres.end());
        }
        return res;
        




    }
};
