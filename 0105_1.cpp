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
    unordered_map<int, int> index;
    TreeNode* build(vector<int>& preorder, 
                    vector<int>& inorder,
                    int preS,
                    int preE,
                    int inS,
                    int inE){
        if(preS > preE){
            return nullptr;
        }
        int root_index_p = preS;
        int root_index_i = index[preorder[preS]];
        TreeNode * root = new TreeNode(preorder[root_index_p]);
        int sizeL = root_index_i - inS;
        root->left = build(preorder, inorder, preS+1, preS + sizeL, inS, root_index_i-1);
        root->right = build(preorder, inorder, preS+sizeL+1, preE, root_index_i+1, inE);

        return root;


    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len =  preorder.size();
        TreeNode * root = new TreeNode(preorder[0]);
        if(len == 1){
            return root;
        }
        for(int i = 0; i < len; ++i){
            index[inorder[i]] = i;
        }
        return root = build(preorder, inorder, 0, len-1, 0, len-1);

    }
};
