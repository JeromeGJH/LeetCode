class Solution {
public:
    int longestValidParentheses(string s) {
        int  l = s.length();
        if(l <= 1)
            return 0;
        int i = 0, ans =0;
        vector<int> dp(l, 0);
        if(s[0] == '(' && s[1] == ')'){
            dp[1] = 2;
        }else{
            dp[1] = 0;
        }
        ans = max(ans, dp[1]);
        for(i =2; i<l; ++i){
                if(s[i] == ')'){
                    if(s[i-1] == '('){
                        dp[i] = dp[i-2] + 2;
                    }else{
                        if(i - dp[i-1] > 0 && s[i - dp[i-1] - 1] == '('){
                            dp[i] = dp[i-1] + 2;
                            if(i - dp[i] > 0){
                                dp[i] += dp[i-dp[i]];
                            }
                        }
                        
                    }
                }
                ans = max(ans, dp[i]);
        }
        return ans;
    }
};
