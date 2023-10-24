class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        int res = 0;
        int a = n*n - mines.size();
        if(a > 0){
            res = 1;
        }else{
            return 0;
        }
        vector<vector<int>> grid(n, vector<int>(n, 1));
        vector<vector<int>> dp1(n, vector<int>(n, 0));
        vector<vector<int>> dp2(n, vector<int>(n, 0));
        for(auto e : mines){
            grid[e[0]][e[1]] = 0;
        }
        //cout << "here1"<<endl;
        int i, j, k;
        
        for(i = 0; i < n; ++i){
            dp1[i][0] = grid[i][0];
            for(j = 1; j < n; ++j){
                dp1[i][j] = dp1[i][j-1] * grid[i][j] + grid[i][j];
            }
        }
        //cout << "here2"<<endl;
        for(j = 0; j < n; ++j){
            dp2[0][j] = grid[0][j];
            for(i = 1; i < n; ++i){
                dp2[i][j] = dp2[i-1][j] * grid[i][j] + grid[i][j];
            }
        }
        // cout << "here3"<<endl;

        // for(j = 0; j < n; ++j){
        //     cout << dp2[n-1][j] << " ";
        // }
        // cout << endl;
        // for(i = 0; i < n; ++i){
        //     cout << dp1[i][n-1] << " ";
            
        // }
        // cout<< endl;

        
        for(i = 0; i < n; ++i){
            if(i < res*2){
                continue;
            }
            for(j = 0; j < n; ++j){
                if(j < res*2){
                    continue;
                }
                for(k = res+1; k <= min(i, j); ++k){
                    if(dp1[i-k+1][j] >= 2 * k - 1){
                        if(dp2[i][j-k+1] >= 2 * k - 1){
                            //cout << i << " "<<j << endl;
                            res = k;
                        }
                    }
                }
            }
        }
        return res;

    }
};
