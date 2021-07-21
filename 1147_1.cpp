class Solution {
public:
    int ifEqual(string s, int l){
        if(l <= 1){
            return l;
        }
        int i = 1, ans = 0, flag = 0;
        for(i = 1; i <= l/2; ++i){
            if(s.substr(0, i) == s.substr(l-i, i)){
                flag = 1;
                ans = max(ans, 2 + ifEqual(s.substr(i, l - i*2), l - i*2));
                break;
            }
        }
        return flag == 0? 1:ans;
    }

    int longestDecomposition(string text) {
        int l = text.length();
        return ifEqual(text, l);
    }
};
