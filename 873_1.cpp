class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int l = arr.size();
        int i = 0, j;
        unordered_map<int, int> index;
        for(i = 0; i < l; ++i){
            index[arr[i]] = i;
        }
        int dp[l][l];
        
        for( i = 0; i < l; ++i){
            for(j = 0; j < l; ++j){
                dp[i][j] = 0;
            }
        }
        
        int ans = 0;
        for(j = 2 ; j < l; ++j){
            for(i = 0; i < j; ++i){
                if(arr[j] - arr[i] < arr[i] && index.count(arr[j] - arr[i])){
                    int k = index[arr[j] - arr[i]];
                    dp[i][j] = dp[k][i] + 1;
                    ans = max(ans, dp[i][j] + 2);
                }
            }
        }
        
        return ans;
    }
};
