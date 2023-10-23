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

        vector<vector<pair<int, int>>> dp(len3, vector<pair<int, int>>());
        if(s1[0] == s3[0]){
            dp[0].emplace_back(make_pair(0, -1));
        }
        if(s2[0] == s3[0]){
            dp[0].emplace_back(make_pair(-1, 0));
        }
        int i, j, p1, p2;
        for(i = 1; i < len3; ++i){
            if(dp[i-1].empty()){
                return false;
            }
            for(j = 0; j < dp[i-1].size(); ++j){
                p1 = dp[i-1][j].first;
                p2 = dp[i-1][j].second;
                if(p1 < len1-1 && s1[p1+1] == s3[i]){
                    dp[i].emplace_back(make_pair(p1+1, p2));
                }
                if(p2 < len2-1 && s2[p2+1] == s3[i]){
                    dp[i].emplace_back(make_pair(p1, p2+1));
                }
            }
        }
        return !dp[len3-1].empty();



    }
};
