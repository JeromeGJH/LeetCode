class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        int  l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
        if(l1 + l2 != l3){
            return false;
        }
        if(l3 == 0){
            return true;
        }

        if(l1 == 0){
            if(s2 == s3)
                return true;
            return false;
        }
        if(l2 == 0 ){
            if(s1 == s3)
                return true;
            return false;
        }
        //cout <<"here3";
        int i = 0, j = 0, k = 0;
        vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));
        dp[0][0] = 1;
        // if(s3[0] == s1[0]){
        //     dp[1][0] = 1;
        // }
        // if(s3[0] == s2[0]){
        //     dp[0][1] = 1;
        // }
        for(i = 0; i <= l1; ++i){
            if(i == 0){
                for( j = 1; j <= l2; ++j){
                    if(s3[i+j-1] == s2[j-1] && dp[i][j-1] == 1){
                        dp[i][j] = 1;
                    }
                }
            }else{
                for( j = 0; j <= l2; ++j){
                    if(s3[i+j-1] == s1[i-1] && dp[i-1][j] == 1){
                        dp[i][j] = 1;
                    }
                    if(j > 0){
                        if(s3[i+j-1] == s2[j-1] && dp[i][j-1] == 1){
                            dp[i][j] = 1;
                        }
                    }
                }
            }
        }

       

        // cout<<"here4"<<endl;
        // for(i = 0; i <= l1; ++i){
        //     for( j = 0; j <= l2; ++j){
        //         cout << "i: "<<i<<" j: "<<j<< "   "<<dp[i][j]<<endl;
        //     }
        // }
        
        return dp[l1][l2] == 1;
    }
};
