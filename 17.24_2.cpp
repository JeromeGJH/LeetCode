class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = 0, k = 0, ans = matrix[0][0], l = 0, a = 0;
        vector<int> ret(4, 0);
        for( i = 0; i < m; ++i){
            vector<int> sum(n, 0);
            for(j = i; j < m ;++j){
                vector<int> s(n, 0);
                for(k = 0; k < n; ++k){
                    sum[k] += matrix[j][k];
                    if(k == 0){
                        s[0] = sum[0];
                    }else{
                        s[k] = s[k-1] + sum[k];
                    }
                }
                int start, value;
                if(s[0] >= 0){
                    value = s[0];
                    start = 0;
                }else{
                    value = 0;
                    start = 1;
                }
                for( a = 1; a < n; ++a){
                    value += sum[a];
                    if(value > ans){
                        // cout<<"here1";
                        // cout << j;
                        ans = value;
                        ret[0] = i;
                        ret[1] = start;
                        ret[2] = j;
                        ret[3] = a;
                    }
                    if(value < 0){
                        value = 0;
                        start = a+1;
                    }
                }
                 
                // if(j == 0){
                //     cout << sum[0]<<"  "<<sum[1];
                // }
            }
        }
        return ret;


    }
};
