class Solution {
public:
    int minInsertions(string s) {
        int l = s.length();
        vector<int> v1(l, 0);
        vector<int> v2(l, 0);
        int i = 0, j = 0;
        for(j = 1; j < l; ++j){
            v2[j-1] = s[j-1] == s[j]? 0:1;
            for(i = j-2; i >= 0; --i){
                v2[i] = s[i] == s[j]? v1[i+1]:min(v2[i+1] + 1, v1[i] + 1);
            }
            v1 = v2;
        }
        return v2[0];
    }
};
