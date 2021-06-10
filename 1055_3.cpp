class Solution {
public:
    int shortestWay(string source, string target) {
        int l1 = source.length();
        const int l2 = target.length();
        int count = 0;
        int i = 0, j = 0;
        int flag = j;
        int dp[l2];
        while(j < l2){
            flag = j;
            while(i < l1 && j < l2){
                if( flag == j){
                    if(source[i] == target[j]){
                        dp[j] = j > 0? dp[j - 1] + 1: 1;
                        ++j;
                    }
                }else{
                    if(source[i] == target[j]){
                        dp[j] = j > 0? dp[j - 1]: 1;
                        ++j;
                    }
                }
                ++i;
            }
            if(flag == j)
                return -1;
            if(j == l2){
                break;
            }
            i = 0;
        }
        return dp[l2 -1];
    }
};
