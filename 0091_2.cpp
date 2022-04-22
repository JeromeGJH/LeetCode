class Solution {
public:
    int numDecodings(string s) {
        int l  = s.length();
        if(s[0] == '0')
                return 0;
        if( l == 1){
            return 1;
        }
        vector<int> dp(l, 0);
        int i = 0, j = 0;
        dp[0] = 1;
        
        if(s[0] == '1'){
            if(s[1] > '0')
                dp[1] = 2;
            else
                dp[1] = 1;
        }else{
            if(s[0] == '2'){
                if(s[1] == '0'){
                    dp[1] = 1;
                }else{
                    if(s[1] > '6'){
                        dp[1] = 1;
                    }else{
                        dp[1] = 2;
                    }
                }
            }else{
                if(s[1] == '0'){
                    return 0;
                }else{
                    dp[1] = 1;
                }
            }
        }
        for(i = 2; i < l; ++i){
            if(s[i] > '0'){
                dp[i] = dp[i-1];
                if(s[i] < '7' ){
                    if(s[i-1] == '1' || s[i-1] == '2')
                        dp[i] += dp[i-2];
                }else{
                    if(s[i-1] == '1')
                        dp[i] += dp[i-2];
                }
            }else{
                if(s[i-1] == '1' || s[i-1] == '2'){
                    dp[i] = dp[i-2];
                }else{
                    return 0;
                }
            }
        }
        return dp[l-1];

    }
};
