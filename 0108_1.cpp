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
    TreeNode * build(vector<int>& nums, int l, int r){
        if(l > r){
            return nullptr;
        }
        TreeNode * root = new TreeNode();
        if(l == r){
            root->val = nums[l];
        }else{
            int mid = (l + r)/2;
            root->val = nums[mid];
            root->left = build(nums, l, mid-1);
            root->right = build(nums, mid+1, r);
        }
        //cout << root->val <<endl;
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        int i = 0;
        TreeNode * root = new TreeNode(nums[len/2]);
        if(len == 1){
            return root;
        }
        //cout << "here1"<<endl;
        root->left = build(nums, 0, len/2-1);
        root->right = build(nums, len/2+1, len-1);
        //cout << "here2"<<endl;
        return root;
    }
};
