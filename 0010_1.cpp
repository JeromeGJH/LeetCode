class Solution {
public:
    bool isMatch(string s, string p) {
        int l1 = s.length(), l2 =p.length();
        if(l2 == 0){
            if(l1 == 0){
                return true;
            }
            return false;
        }
        if(l1 == 0){
            if(l2 == 1){
                return false;
            }
        }
        int i = 0 , j = 0, k = 0;
        vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));
        dp[0][0] = 1;
        for(j = 1; j <= l2; ++j){
            if(p[j-1] == '.'){
                for(i = 1; i <= l1; ++i){
                    dp[i][j] = dp[i-1][j-1];
                }
            }else if(p[j-1] == '*'){
                if(j != 1){
                    int flag = 0;
                    for(i = 0; i <= l1; ++i){
                        if(dp[i][j-2] == 1){
                            dp[i][j] = 1;
                            for(k = i+1; k <= l1; ++k){
                                if(s[k-1] == p[j-2] || p[j-2] == '.'){
                                    dp[k][j] = 1;
                                }else{
                                    break;
                                }
                            }
                            i = k-1;
                        }
                    }
                }
            }else{
                for(i = 1; i <= l1; ++i){
                    if(s[i-1] == p[j-1]){
                        dp[i][j] = dp[i-1][j-1];
                    }
                }
            }
        }
        // for( j = 0 ; j <= l2; ++j){
        //     for( i = 0 ; i <= l1; ++i){
        //         cout <<"i: "<<i <<" j: "<<j << "   "<<dp[i][j] << endl;
        //     }
        // }
        
        return dp[l1][l2] == 1;
    }
};
