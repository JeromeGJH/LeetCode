class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int i  = 0, j = 0;
        
        int m = mat.size();
        int n = mat[0].size();
        
        vector<int> res(k, 0);
        vector<int> count(m, n);
        for(i = 0; i < m; ++i){
            for(j = 0; j < n; ++j){
                if(mat[i][j] == 0){
                    count[i] = j;
                    break;
                }
            }
        }
        
        int c = 0;
        for(i = 0; i <= n; ++i){
            for(j = 0; j < m; ++j){
                if(count[j] == i){
                    res[c] = j;
                    c ++;
                    if(c == k){
                        return res;
                    }
                }
            }
        }
        return res;
    }
};
