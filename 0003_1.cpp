class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if(len <= 1){
            return len;
        }

        int i = 0;
        int res = 1;
        int l=0 , r=1, flag = 0;
        while(l <= r && r < len){
            for(i = l; i < r; ++i){
                if(s[i] == s[r]){
                    l = i+1;
                    break;
                }
            }
            if(i == r){
                res = max(res, r-l+1);
            }
            ++r;
        }
        return res;
        


    }
};
