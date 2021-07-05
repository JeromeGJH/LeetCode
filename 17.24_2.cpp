class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = 0, k = 0, ans = matrix[0][0];
        vector<int> ret(4, 0);
        for( i = 0; i < m; ++i){
            vector<int> sum(n, 0);
            for(j = i; j < m ;++j){
                int start, value;
                for(k = 0; k < n; ++k){
                    sum[k] += matrix[j][k];
                    if(k == 0){
                        value = sum[0]>=0?sum[0]:0;
                        start = sum[0]>=0?0:1;
                    }else{
                        value += sum[k];
                        if(value > ans){
                            ans = value;
                            ret[0] = i;
                            ret[1] = start;
                            ret[2] = j;
                            ret[3] = k;
                        }
                        if(value < 0){
                            value = 0;
                            start = k+1;
                        }
                    }
                }
            }
        }
        return ret;
    }
};
