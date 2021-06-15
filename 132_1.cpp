class Solution {
public:
    int minCut(string s) {
        int l = s.length();
        if( l == 1){
            return 0;
        }
        vector<vector<int>> dp(l, vector<int>(l, 0));
        
        int i = 0, j = 0, k = 0;
        for(j = 0; j < l; ++j){
            for(i = 0; i <= j; ++i){
                if(i == j){
                    dp[i][j] = 1;
                }else{
                    if( j == i + 1){
                        if(s[i] == s[j]){
                            dp[i][j] = 1;
                        }
                    }else{
                        if(s[i] == s[j] && dp[i+1][j-1] == 1){
                            dp[i][j] = 1;
                        }
                    }
                }
            }
        }
        vector<vector<int>> cut(l, vector<int>(l, 0));
        cut[0][0] = 0;
        int mincut = 0;

        for(j = 0; j < l; ++j){
            cut[j][j] = 0;
            i = j-1;
            mincut = l - 1;
            while(i >= 0){
                if(dp[i][j] == 1){
                    cut[i][j] = 0;
                }else{
                    if(j == i + 1){
                        cut[i][j] = 1;
                    }else{
                        mincut = l - 1;
                        for(k=i; k<j; ++k){
                            // cout << "j: " << j << " ";
                            // cout << "i: " << i << " ";
                            // cout << "k: " << k << " " << endl;
                            // cout << " cut: ";
                            // cout << cut[i][k] + cut[k][j] + 1 << endl;
                            mincut = min(mincut, cut[i][k] + cut[k+1][j] + 1);
                        }
                        cut[i][j] = mincut;
                    }
                }
                --i;
            }
            
        }

        // cout << cut[1][2];
        // cout << cut[0][0];
        // cout << cut[0][3];
        // cout << cut[0][2];
        // cout << cut[1][3] << endl;

        // for(i = 0; i < l; ++i){
        //     for(j = 0; j < l; ++j){
        //         cout << cut[i][j];
        //     }
        //     cout << endl;
        // }
        return cut[0][l-1];
    }
};
