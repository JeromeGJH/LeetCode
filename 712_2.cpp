class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int l1 = s1.length(), l2 = s2.length();
        int i = 0, j = 0, sum1 = s1[0], sum2 = s2[0];
        vector<vector<int>> sum(l1, vector<int>(l2 , 0));
        sum[0][0] = s1[0] == s2[0]? s1[0] + s2[0]:0;
        for( i = 1; i < l1; ++i){
            sum1 += s1[i];
            sum[i][0] = s1[i] == s2[0]? s1[i] + s2[0]:sum[i-1][0];
        }
        for( i = 1; i < l2; ++i){
            sum2 += s2[i];
            sum[0][i] = s1[0] == s2[i]? s1[0] + s2[i]:sum[0][i-1];
        }
        for(i  = 1; i < l1; ++i){
            for(j = 1; j < l2; ++j)
                sum[i][j] = s1[i] == s2[j]? sum[i-1][j-1] + s1[i] + s2[j]:max(sum[i-1][j], sum[i][j-1]);
        }
        return sum1 + sum2 - sum[l1-1][l2-1];
    }
};
