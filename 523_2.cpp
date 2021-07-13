class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int m = nums.size();
        if (m < 2) {
            return false;
        }
        unordered_map<int, int> mp;
        mp[0] = -1;
        int remainder = 0;
        for (int i = 0; i < m; i++) {
            remainder = (remainder + nums[i]) % k;
            if (mp.count(remainder)) {
                if (i - mp[remainder] >= 2) {
                    return true;
                }
            } else {
                mp[remainder] = i;
            }
        }
        return false;
    }
};
