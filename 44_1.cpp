class Solution {
public:
    bool isMatch(string s, string p) {
        int l1 = s.length(), l2 = p .length();
        if(l2 == 0 && l1 != 0){
            return false;
        }
        if(l1 == 0){
            if(l2 == 0){
                return true;
            }else{
                for(int n = 0; n < l2; ++n){
                    if(p[n] != '*')
                        return false;
                }
                return true;
            }
        }

        vector<vector<int>> dp(l1, vector<int>(l2, 0));
        int i = 0, j = 0, flag = 0;
        if(s[0] == p[0] || p[0] == '*' || p[0] == '?'){
            dp[0][0] = 1;
        }

        for(i = 1; i < l1; ++i){
            if(p[0] == '*'){
                dp[i][0] = 1;
            }
        }

        for(i = 1; i < l2; ++i){
            if(p[i] == '*' || p[i] == '?' || p[i] == s[0]){
                if(p[i-1] == '*'){
                    dp[0][i] = dp[0][i-1];
                }
            }else{
                dp[0][i] = 0;
            }
        }

        
        for(j = 1; j < l2; ++j){
            if(p[j] == '?'){
                for(i = 1; i < l1; ++i){
                    dp[i][j] = dp[i-1][j-1];
                }
            }else if(p[j] == '*'){
                flag = 0;
                for(i = 0; i < l1; ++i){
                    if(flag == 0){
                        if(dp[i][j-1] == 1){
                            dp[i][j] = 1;
                            flag = 1;
                        }
                    }else{
                        dp[i][j] = 1;
                    }
                }
            }else{
                for(i = 1; i < l1; ++i){
                    if(s[i] == p[j]){
                        dp[i][j] = dp[i-1][j-1];
                    }else{
                        dp[i][j] = 0;
                    }
                }
            }
        }
        // for( j = 0 ; j < l2; ++j){
        //     for( i = 0 ; i < l1; ++i){
        //         cout <<"i: "<<i <<" j: "<<j << "   "<<dp[i][j] << endl;
        //     }
        // }
        return dp[l1-1][l2-1] == 1;


    }
};
