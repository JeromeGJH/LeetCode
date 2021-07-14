class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        int i = 0, j = 0, a = 0, b = 0, c= 0;
        vector<vector<int>> res(m, vector<int>(n , 0));
        //vector<vector<int>> sum(m, vector<int>(n , 0));
        for(i = 0; i < m; ++i){
            vector<int> num(n , 0);
            for(j = max(i-k, 0) ; j <= min(m-1, i+k); ++j){
                for(c = 0; c < n; ++c){
                    num[c] += mat[j][c];
                }
            }
            for(j = 0; j < n; ++j){
                for(a = max(j - k, 0); a <= min(j+k, n-1); ++a){
                    res[i][j] += num[a];
                }
            }
        }
        return res;
    }
};
