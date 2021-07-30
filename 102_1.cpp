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
    vector<TreeNode*> ls1;   
    vector<TreeNode*> ls2;
    vector<vector<int>> res;
    void traverse(int num){
        if(ls1.empty()){
            return;
        }
        res.push_back(vector<int>());
        int l = ls1.size();
        for(int i = 0; i <l; ++i){
            res[num].push_back(ls1[i]->val);
            if(ls1[i]->left != nullptr){
                ls2.push_back(ls1[i]->left);
            }
            if(ls1[i]->right != nullptr){
                ls2.push_back(ls1[i]->right);
            }
        }
        ls1 = ls2;
        ls2.clear();
        traverse(num+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr){
            return res;
        }
        ls1.push_back(root);
        traverse(0);
        return res;

    }
};
