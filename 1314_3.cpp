class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> P(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                P[i][j] = P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
        
        vector<vector<int>> ans(m, vector<int>(n));
        int u, d, r , l;
        for (int i = 0; i < m; ++i) {
            u = max(i - k, 0);
            d = min(m-1, i + k);
            for (int j = 0; j < n; ++j) {
                l = max(j - k, 0);
                r = min(n-1, j + k);
                ans[i][j] = P[d+1][r+1] - P[d+1][l] - P[u][r+1] + P[u][l];
            }
        }
        return ans;
    }
};
