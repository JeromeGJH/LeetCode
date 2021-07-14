class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        int i = 0, j = 0, a = 0, b = 0, c= 0;
        int l = 0, r = 0, u = 0, d = 0;
        vector<vector<int>> res(m, vector<int>(n , 0));
        vector<vector<int>> sum(m, vector<int>(n , 0));
        for(i = 0; i <m; ++i){
            for(j = 0 ; j <n ;++j){
                sum[i][j] = j == 0? mat[i][0]:(sum[i][j-1] + mat[i][j]);
            }
        }
        for(i = 0; i < m; ++i){
            u = i - k <= 0? 0 : i - k;
            d = i + k >= m-1? m-1 : i + k;
            for(j = 0; j < n; ++j){
                l = j - k <= 0? 0 : j - k;
                r = j + k >= n-1? n-1 : j + k;
                for(a = u; a <= d; ++a){
                    if(l == 0){
                        res[i][j] += sum[a][r];
                    }else{
                        res[i][j] += sum[a][r] - sum[a][l-1];
                    }
                }
            }
        }
        return res;
    }
};
