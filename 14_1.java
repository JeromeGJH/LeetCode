class Solution {
    public String longestCommonPrefix(String[] strs) {
        int l = strs.length;
        int length = 1;
        int i = 0;
        if(l == 1){
            return strs[0];
        }
        if(l == 0){
            return "";
        }else{
            while(true){
                for(i = 0; i < l; ++i){
                    if(strs[i].length() < length){
                        return strs[i];
                    } else{
                        if(strs[0].charAt(length-1) != strs[i].charAt(length-1)){
                            return strs[0].substring(0, length-1);
                        } else{
                            if(i == l-1)
                                length += 1;
                        }
                    }
                }
            }
        }
    }
}
