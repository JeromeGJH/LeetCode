class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        if(row == 1){
            return triangle[0][0];
        }
        vector<int> pre(row, 0);
        vector<int> cur(row, 0);
        pre[0] = triangle[0][0];;
        int i = 0, j = 0;
        for(i = 1; i < row; ++i){
            cur[0] = pre[0] + triangle[i][0];
            for(j = 1; j < i; ++j){
                cur[j] = min(pre[j-1], pre[j]) + triangle[i][j];
            }
            cur[i] = pre[i-1] + triangle[i][i];
            pre = cur;
        }
        int res = cur[0];
        for(i = 1; i < row; ++i){
            if(res > cur[i]){
                res = cur[i];
            }
            //cout << dp[row-1][i] << endl;
        }
        return res;
    }
};
