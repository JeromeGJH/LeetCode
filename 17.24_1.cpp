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
                if(s[0] > ans){
                    ans = s[0];
                    ret[0] = i;
                    ret[1] = 0;
                    ret[2] = j;
                    ret[3] = 0;
                }
                for(l = 1; l < n; ++l){
                    if(s[l] > ans){
                        ans = s[l];
                        ret[0] = i;
                        ret[1] = 0;
                        ret[2] = j;
                        ret[3] = l;
                    }
                    for( a = 0; a < l; ++a){
                        if(s[l] - s[a] > ans){
                            ans =s[l] - s[a];
                            ret[0] = i;
                            ret[1] = a+1;
                            ret[2] = j;
                            ret[3] = l;
                        }
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
