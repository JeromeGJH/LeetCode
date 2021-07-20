class Solution {
public:
    vector<int> findMin(map<int, int>& mp){
        vector<int> ans(2, -1);
        int min1 = INT_MAX, min2 = INT_MAX;
        for(map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it){
            if(min1 > it->second){
                ans[1] = ans[0];
                ans[0] = it->first;
                min2 = min1;
                min1 = it->second;
            }else{
                if(min1 <= it->second && it->second < min2){
                    min2 = it->second;
                    ans[1] = it->first;
                }
            }
        }
        return ans;
    }

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        int  i =  0, j = 0, k = 0;
        int res;
        vector<vector<map<int, int>>> dp(m, vector<map<int, int>>(target + 1, map<int, int>()));
        vector<vector<vector<int>>> min_index(m, vector<vector<int>>(target + 1, vector<int>(2, -1)));
        //vector<vector<int>> min_p(m, vector<int>(target + 1, INT_MAX));
        //vector<vector<int>> min_c(m, vector<int>(target + 1, -1));
        if(houses[0] > 0){
            dp[0][1][houses[0]-1] = 0;
        }else{
            for(j = 0; j < n; ++j ){
                dp[0][1][j] = cost[0][j];
                //cout << dp[0][1][j] << " ";
            }
        }
        min_index[0][1] = findMin(dp[0][1]);
        //cout<< min_index[0][1][0]<<" "<<endl;
        //cout<< min_index[0][1][1]<<" "<<endl;

        for(i = 1; i < m; ++i){
            if(!dp[i-1][1].empty()){
                if(houses[i] == 0){
                    for(map<int, int>::iterator it = dp[i-1][1].begin(); it != dp[i-1][1].end(); ++it){
                        dp[i][1][it->first] = dp[i-1][1][it->first] + cost[i][it->first];
                    }
                }else{
                    if(dp[i-1][1].count(houses[i]-1)){
                        dp[i][1][houses[i]-1] = dp[i-1][1][houses[i]-1];
                    }
                }    
            }
            min_index[i][1] = findMin(dp[i][1]);
            for(j = 2; j <= target && j <= i+1; ++j){
                if(!dp[i-1][j].empty()){
                    if(houses[i] == 0){
                        for(map<int, int>::iterator it = dp[i-1][j].begin(); it != dp[i-1][j].end(); ++it){   
                            dp[i][j][it->first] = dp[i-1][j][it->first] + cost[i][it->first];
                        }
                    }else{
                        if(dp[i-1][j].count(houses[i]-1)){
                            dp[i][j][houses[i]-1] = dp[i-1][j][houses[i]-1];
                        }
                    }    
                }
                if(!dp[i-1][j-1].empty()){
                    min_index[i-1][j-1] = findMin(dp[i-1][j-1]);
                    vector<int> tmp = min_index[i-1][j-1];
                    if(houses[i] == 0){
                        for(k = 0; k < n; ++k){
                            if(k != tmp[0]){
                                if(dp[i][j].count(k) == 0){
                                    dp[i][j][k] = dp[i-1][j-1][tmp[0]] + cost[i][k];
                                }else{
                                    dp[i][j][k] = min(dp[i-1][j-1][tmp[0]] + cost[i][k], dp[i][j][k]);
                                }
                            }else{
                                if(tmp[1] == -1){
                                    continue;
                                }else{
                                    if(dp[i][j].count(k) == 0){
                                        dp[i][j][k] = dp[i-1][j-1][tmp[1]] + cost[i][k];
                                    }else{
                                        dp[i][j][k] = min(dp[i-1][j-1][tmp[1]] + cost[i][k], dp[i][j][k]);

                                    }
                                }
                            }
                        }
                    }else{
                        if(houses[i] - 1 != tmp[0]){
                            if(dp[i][j].count(houses[i]-1) == 0){
                                dp[i][j][houses[i]-1] = dp[i-1][j-1][tmp[0]];
                            }else{
                                dp[i][j][houses[i]-1] = min(dp[i-1][j-1][tmp[0]], dp[i][j][houses[i]-1]);
                            }
                        }else{
                            if(tmp[1] == -1){
                                continue;
                            }else{
                                if(dp[i][j].count(houses[i]-1) == 0){
                                    dp[i][j][houses[i]-1] = dp[i-1][j-1][tmp[1]];
                                }else{
                                    dp[i][j][houses[i]-1] = min(dp[i-1][j-1][tmp[1]], dp[i][j][houses[i]-1]);
                                }
                            }                            
                        }
                    }    
                }
            }
        }
        // cout << dp[4][3][0]<<endl;
        // cout << dp[3][2][0]<<endl;
        // cout << dp[3][2][1]<<endl;
        // cout << dp[3][2][2]<<endl;
        //cout << dp[11][10][4]<<endl;
        //cout<<dp[11][11][4]<<endl;
        //cout<<dp[12][11][4]<<endl;
        //cout <<"here32 "<<endl;
        

        //cout << min_c[0][1]<<endl;
        // for(i = 0 ; i < m; ++i){
        //     for(j = 1; j <= target && j <= i+1; ++j){
        //         min_index[i][j] = findMin(dp[i][j]);
        //         cout <<"i: "<<i <<" j: "<<j <<"   ";
        //         cout<< min_index[i][j][0]<<" ";
        //         cout<< min_index[i][j][1]<<" "<<endl;
        //     }
        // }
        // for(i = 0 ; i < m; ++i){
        //     for(j = 1; j <= target && j <= i+1; ++j){
        //         cout <<"i: "<<i <<" j: "<<j <<" ";
        //         if(!dp[i][j].empty()){
        //             for(map<int, int>::iterator it = dp[i][j].begin(); it != dp[i][j].end(); ++it){
        //                 cout<< it->first<<" ";
        //             }
        //             cout <<endl;
        //         }
        //     }
        // }
        min_index[m-1][target] = findMin(dp[m-1][target]);

        

        if(min_index[m-1][target][0] == -1){
            return -1;
        }else{
            return dp[m-1][target][min_index[m-1][target][0]];
        }
    }
}; 
