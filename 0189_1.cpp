class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        int loop = k % len;
        int i = 0;
        nums.insert(nums.end(), nums.begin(), nums.end()-loop);
        nums.erase(nums.begin(), nums.begin() + len - loop);



    }
};
