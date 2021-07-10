class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int l = nums.size();
        int i = 0, j = 0, sum = 0, ans = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for( i= 0; i < l; ++i){
            sum += nums[i];
            if(mp.count(sum) == 0){
                mp[sum] = i;
            }
            if(mp.count(sum - k) == 1){
                ans = max(ans, i - mp[sum-k]);
            }
        }
        return ans;

    }
};
