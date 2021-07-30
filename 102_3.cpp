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
    vector<vector<int>> res;
    void traverse(TreeNode* root, int num){
        if(root == nullptr){
            return;
        }
        res.push_back(vector<int>());
        res[num].push_back(root->val);
        traverse(root->left, num+1);
        traverse(root->right, num+1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        traverse(root, 0);
        for(int i = 0; i < res.size(); ++i){
            if(res[i].empty()){
                return vector<vector<int>>(res.begin(), res.begin()+i);
            }
        }
        return res;

    }
};
