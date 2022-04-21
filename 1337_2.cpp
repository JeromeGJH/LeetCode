class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<int> weakness = vector<int>(m, 0);
        for(int i = 0; i < m; ++i){
            int left = 0, right = n-1;
            int mid;
            while(left < right){
                mid = (left + right)/2 + 1;
                if(mat[i][mid] == 1){
                    left = mid;
                }else{
                    right = mid -1;
                }
            }
            if(mat[i][left] == 1){
                weakness[i] = left + 1;
            }
        }
        int i = 0, j = 0;
        vector<int> res;

        i = 0;
        for(i = 0; i <= n; ++i){
            for(j = 0; j < m; ++j){
                if(weakness[j] == i){
                    res.push_back(j);
                    k--;
                }
                if(k == 0){
                    return res;
                }
            }
        }
    
        return res;
    }
};
