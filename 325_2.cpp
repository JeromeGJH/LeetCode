class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int l = nums.size();
        int i = 0, j = 0;
        vector<int> dp(l , 0);
        unordered_map<int, int> mp;
        dp[0] = nums[0];
        mp[dp[0]] = 0;
        for( i= 1; i <l;++i){
            dp[i] = dp[i-1] + nums[i];
            if(mp.count(dp[i]) == 0){
                mp[dp[i]] = i;
            }
        }
        int ans = 0;
        for( i = l-1; i >= ans; --i){
            if(dp[i] == k){
                ans = max(ans, i+1);
            }else{
                if(mp.count(dp[i] - k) != 0){
                    ans = max(ans, i - mp[dp[i]-k]);
                }
            }
        }
        return ans;

    }
};
