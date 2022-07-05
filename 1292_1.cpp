class Solution {
public:
    bool check(vector<vector<int>>& sums, int threshold, int l){
        int m = sums.size()-1, n = sums[0].size()-1;
        int i = 0, j = 0, k;
        int s = 0;
        for(i = 0; i <= m - l; ++i){
            for(j = 0; j <= n - l; ++j){
                s = 0;
                for(k = i; k < i + l; ++k){
                    s += sums[k+1][j+l] - sums[k+1][j];
                }
                if(s <= threshold){
                    return true;
                }
            }
        }
        return false;
    }

    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> sums = vector<vector<int>>(m+1, vector<int>(n+1,0));
        int i, j;
        for(i = 1; i <= m; ++i){
            for(j = 1; j <= n; ++j){
                sums[i][j] = sums[i][j-1] + mat[i-1][j-1];
            }
        }

        int left = 0, right = min(m, n);
        int mid = (left + right ) / 2;
        while(left < right){
            mid = (left + right) / 2 + 1;
            if(check(sums, threshold, mid)){
                left = mid;
            }else{
                right = mid - 1;
            }
        }
        return left;
    }
};
