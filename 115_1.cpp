class Solution {
public:
    int numDistinct(string s, string t) {
        int l1 = s.length(), l2 = t.length();
        if(l1 < l2){
            return false;
        }
        int i = 0 , j = 0;
        vector<vector<unsigned>> dp(l1+1, vector<unsigned>(l2+1, 0));
        long sum = 0;
        for(j = 0; j < l1; ++j){
            if(s[j] == t[0] ){
                sum += 1;
                dp[j+1][1] = sum;
            }else{
                dp[j+1][1] = sum;
            }
        }
        for(j = 2; j <= l2; ++j){
            for(i = 1; i <= l1; ++i){
                //cout<<"j: "<<j<<" i: "<<i <<endl;
                if(s[i-1] == t[j-1]){
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        // for(j = 1; j <= l2; ++j){
        //     for(i = 1; i <= l1; ++i){
        //         cout<<"j: "<<j<<" i: "<<i << "    "<<dp[i][j]<<endl;
        //     }
        // }
        return dp[l1][l2];
    }
};
 
