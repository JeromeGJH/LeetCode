class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length() == 0){
            if(s1.length() == 0 && s2.length() == 0){
                return true;
            }else{
                return false;
            }
        }

        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if(len1 + len2 != len3){
            return false;
        }
        if(len1 == 0){
            if(s2 == s3){
                return true;
            }
            return false;
        }
        if(len2 == 0){
            if(s1 == s3){
                return true;
            }
            return false;
        }

        vector<vector<vector<bool>>> dp(len3, vector<vector<bool>>(len1+1, vector<bool>(len2+1, false)));
        if(s1[0] == s3[0]){
            dp[0][1][0] = true;
        }
        if(s2[0] == s3[0]){
            dp[0][0][1] = true;
        }
        int i, j, k, p1, p2;
        for(i = 1; i < len3; ++i){
            for(j = 0; j <= len1; ++j){
                for(k = 0; k <= len2; ++k){
                    if(dp[i-1][j][k]){
                        p1 = j;
                        p2 = k;
                        if(p1 < len1 && s1[p1] == s3[i]){
                            dp[i][j+1][k] = true;;
                        }
                        if(p2 < len2 && s2[p2] == s3[i]){
                            dp[i][j][k+1] = true;;
                        }
                    }
                }
            }
        }
        
        return dp[len3-1][len1][len2];



    }
};
