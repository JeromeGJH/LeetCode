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

        vector<vector<bool>> dp(len1+1, vector<bool>(len2+1, false));
        if(s1[0] == s3[0]){
            dp[1][0] = true;
        }
        if(s2[0] == s3[0]){
            dp[0][1] = true;
        }
        //cout << len1 << len2 << len3 << endl;
        int i, j, k;
        for(i = 2; i <= len3; ++i){
            for(j = 0; j <= i-1 && j <= len1; ++j){
                k = i - 1 - j;
                //cout << i << " "<< j << " " << k<< endl;
                if(k > len2){
                    //cout << "here"<<endl;
                    continue;
                }
                
                //cout << dp[j][k]<< endl;
                if(dp[j][k]){
                    if(j < len1 && s1[j] == s3[i-1]){
                        dp[j+1][k] = true;
                    }
                    if(k < len2 && s2[k] == s3[i-1]){
                        dp[j][k+1] = true;
                    }
                }
                
            }
        }
        
        return dp[len1][len2];



    }
};
