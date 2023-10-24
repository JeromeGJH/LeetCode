class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
        vector<int> dp(len, -1);
        int i;
        for(auto e : wordDict){
            if(s.substr(0, e.length()) == e){
                dp[e.length()-1] = 1;
            }
        }
        for(i = 0; i < len; ++i){
            if(dp[i] < 0){
                continue;
            }
            for(auto e : wordDict){
                if(i+1 + e.length() > len){
                    continue;
                }
                if(s.substr(i+1, e.length()) == e){
                    dp[i + e.length()] = 1;
                }
            }
        }
        return dp[len-1] > 0;
    }
};
