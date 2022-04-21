class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int i, res = 0;
        int left, right, mid;
        for(i = 0; i < m; ++i){
            left = 0;
            right = n -1;
            while(left < right){
                mid = (left + right)/2;
                if(grid[i][mid] >= 0 ){
                    left = mid + 1;
                }else{
                    right = mid;
                }
            }
            if(grid[i][left] < 0){
                res += n - left;
            }
        }
        return res;
    }
};
