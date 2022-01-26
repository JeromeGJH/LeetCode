class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == ""){
            return 0;
        }else{
            int len = haystack.length();
            int l = needle.length();
            int i = 0, j = 0;
            for(i = 0; i <= len - l; ++i){
                for(j = 0; j < l; ++j){
                    if(haystack[i + j] != needle[j]){
                        break;
                    }
                }
                if(j == l){
                    return i;
                }
            }
            return -1;
        }

    }
};
