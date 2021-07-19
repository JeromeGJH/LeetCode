class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int l = arr.size(), n = queries.size();
        vector<int> dp(l, 0);
        dp[0] = arr[0];
        vector<int> res(n, 0);
        int i  = 0;
        for(i  =1; i <l; ++i){
            dp[i] = dp[i-1]^arr[i];
        }
        for(i = 0; i < n ; ++i){
            res[i] = queries[i][0] == 0?res[i] = dp[queries[i][1]]:dp[queries[i][1]] ^ dp[queries[i][0]-1];
        }
        
        return res;



    }
};
