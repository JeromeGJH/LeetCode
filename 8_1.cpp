class Solution {
public:
    int myAtoi(string s) {
        int res = 0;
        int l = s.length();
        int i = 0;
        bool ifNeg = false;
        int ifStart = false;
        int pre = INT_MAX/10;
        int diff = 0;
        int neg = '-' - '0';
        int pos = '+' - '0';
        for(i = 0; i < l; ++i){
            if(!ifStart){
                if(s[i] == ' '){
                    continue;
                }else{
                    ifStart = true;
                    diff = s[i] - '0';
                    if(diff == neg || diff == pos){
                        ifNeg = diff == neg ? true:false;
                        continue;
                    }else{
                        if(diff >= 0 && diff <= 9){
                            res = res * 10 + diff;
                        }else{
                            return 0;
                        }
                    }
                }
            }else{
                diff = s[i] - '0';
                if(diff >= 0 && diff <= 9){
                    if(ifNeg){
                        if(res > pre){
                            return INT_MIN;
                        }
                        if(res == pre){
                            if(diff >= 8){
                                return INT_MIN;
                            }
                        }
                        res = res * 10 + diff;
                    }else{
                        if(res > pre){
                            return INT_MAX;
                        }
                        if(res == pre){
                            if(diff >= 7){
                                return INT_MAX;
                            }
                        }
                        res = res * 10 + diff;
                    }
                }else{
                    break;
                }
            }
        }
        if(ifNeg){
            return (-1)*res;
        }
        return res;

    }
};
