class Solution {
public:
    int longestDecomposition(string text) {
        int l = text.length();
        for(int i = 1; i <= l/2; ++i){
            if(text.substr(0, i) == text.substr(l-i, i)){
                return 2 + longestDecomposition(text.substr(i, l - i*2));
            }
        }
        return l>0 ? 1:0;
    }
};
