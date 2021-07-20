class Solution {
public:
    int longestValidParentheses(string s) {
        const int l = s.length();
        if( l == 0)
            return 0;
        int  i = 0, j = 0;
        int ans = 0;
        int count = 0;
        int dp[l];
        int len = 0;
        for(i = 0; i < l; ++i){
            if(s[i] == '(')
                dp[i] = 1;
            else
                dp[i] = -1;
        }
        for(i = 0; i<l; ++i){
            if(count == 0){
                if(s[i] == '('){
                    count += 1;
                }else{
                    continue;
                }
            }else{
                if(s[i] == '('){
                    count += 1;
                }else{
                    count -= 1;
                    dp[i] = 0;
                    j = i - 1;
                    while(j >= 0){
                        if(dp[j] == 1){
                            dp[j] = 0;
                            break;
                        }
                        --j;
                    }
                }
            }
        }
        for(i = 0; i<l; ++i){
            if(dp[i] == 0){
                len += 1;
            }else{
                len = 0;
            }
            ans = max(ans, len);
        }
        return ans;
    }
};
 
