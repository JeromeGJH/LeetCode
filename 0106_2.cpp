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
    TreeNode * build(   vector<int>& inorder, 
                        vector<int>& postorder,
                        int inS,
                        int inE,
                        int poS,
                        int poE){
        if(poS > poE){
            return nullptr;
        }
        int root_index_po = poE;
        TreeNode * root = new TreeNode(postorder[poE]);
        int root_index_in = index[postorder[poE]];
        int sizeL = root_index_in - inS;
        root->left = build(inorder, postorder, inS, root_index_in-1, poS, poS+sizeL-1);
        root->right = build(inorder, postorder, root_index_in+1, inE, poS+sizeL, poE-1);
        return root;


    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len = inorder.size();
        TreeNode * root = new TreeNode(postorder[len-1]);
        if(len == 1){
            return root;
        }
        for(int i = 0; i < len; ++i){
            index[inorder[i]] = i;
        }
        root = build(inorder, postorder, 0, len-1, 0, len-1);

        return root;

    }
};
