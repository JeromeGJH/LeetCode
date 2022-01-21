class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int p1 = 1, p2 = 1;
        while (p2 < n) {
            if (nums[p2] != nums[p2 - 1]) {
                nums[p1] = nums[p2];
                ++p1;
            }
            ++p2;
        }
        return p1;
    }
};
