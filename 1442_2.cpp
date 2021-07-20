class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int l = arr.size(), i = 0, j = 0;
        if(l == 1){
            return 0;
        }
        vector<int> dp(l, 0);
        unordered_map<int, int> mp, total;
        mp[0] = 1;
        total[0] = -1;
        int ans = 0;
        dp[0] = arr[0];
        mp[dp[0]] = 1;
        total[dp[0]] = 0;
        for( i = 1; i < l; ++i){
            dp[i] = dp[i-1] ^ arr[i];
            ans += mp[dp[i]] * i - total[dp[i]] - mp[dp[i]];
            mp[dp[i]] += 1;
            total[dp[i]] += i;
        }
        return ans;
    }
};
