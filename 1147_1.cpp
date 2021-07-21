class Solution {
public:
    int ifEqual(string s, int l){
        for(int i = 1; i <= l/2; ++i){
            if(s.substr(0, i) == s.substr(l-i, i)){
                return 2 + ifEqual(s.substr(i, l - i*2), l - i*2);
            }
        }
        return l>0 ? 1:0;
    }

    int longestDecomposition(string text) {
        int l = text.length();
        return ifEqual(text, l);
    }
};
