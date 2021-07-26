class Solution {
public:
    int findSubLength(string s){
        return (s+s).find(s, 1);
    }

    int findNumLength(int num){
        int res = 0;
        while(num > 0){
            num /= 10;
            ++res;
        }
        return res;
    }

    string encode(string s) {
        int l = s.length();
        vector<vector<string>> dp(l, vector<string>(l));
        int i = 0, j = 0, len, k, sublen, rep;
        for(i = 0; i < l; ++i){
            for(len = 1; i+len <= l && len <= 4; ++len){
                dp[i][i+len-1] = s.substr(i, len);
            }
        }

        for(len = 5; len <= l; ++len){
            for(i = 0; i + len <= l; ++i){
                j = i+len-1;
                sublen = findSubLength(s.substr(i, len));
                if(sublen < len){
                    rep = len/sublen;
                    if(findNumLength(rep) + 2 + dp[i][i+sublen-1].length() < len){
                        dp[i][j] = to_string(len/sublen) +"[" + dp[i][i+sublen-1] + "]";
                    }else{
                        dp[i][j] = s.substr(i, len);
                    }
                }else{
                    dp[i][j] = dp[i][i] + dp[i+1][j];
                    for(k = i; k < j; ++k){
                        if(dp[i][j].length() > dp[i][k].length() + dp[k+1][j].length())
                            dp[i][j] = dp[i][k] + dp[k+1][j];
                    }
                }
            }
        }
        return dp[0][l-1];
    }
};
