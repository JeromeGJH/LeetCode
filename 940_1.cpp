class Solution {
public:
    int distinctSubseqII(string s) {
        int l = s.length();
        int mod = pow(10, 9) + 7;
        int i = 0;
        unordered_map<char, int> mp;
        vector<long> dp(l, 0);
        dp[0] = 2;
        mp[s[0]] = 0;
        for(i = 1; i <l; ++i){
            if(mp.count(s[i]) == 0){
                dp[i] = dp[i-1]*2;
            }else{
                dp[i] = mp[s[i]] == 0? dp[i-1]*2 - 1:dp[i-1]*2 - dp[mp[s[i]] -1];
            }
            mp[s[i]] = i;
            dp[i] %= mod;
        }
        return dp[l-1] < 0?dp[l-1] + mod -1: dp[l-1] -1;
    }
};
