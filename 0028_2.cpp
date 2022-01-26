class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == ""){
            return 0;
        }else{
            int len = haystack.length();
            int l = needle.length();
            if(len < l){
                return -1;
            }
            int i = 0;
            unsigned long int pow = 1;
            unsigned long int rfp1 = needle[l-1] - 'a';
            unsigned long int rfp2 = haystack[l-1] - 'a';
            for(i = l-2; i >= 0; --i){
                pow *= 32;
                rfp1 += (needle[i] - 'a') * pow;
                rfp2 += (haystack[i] - 'a') * pow;
            }
            if(rfp1 == rfp2){
                return 0;
            }else{
                for(i = 1; i <= len - l; ++i){
                    rfp2 = (rfp2 - (haystack[i-1] - 'a') * pow) * 32 + (haystack[i+l-1] - 'a');
                    if(rfp2 == rfp1){
                        return i;
                    }
                }
                return -1;
            }
        }
    }
};
