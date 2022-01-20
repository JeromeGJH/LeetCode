class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        if(len % 2 != 0){
            return false;
        }
        stack<int> ss;
        int i = 0;
        for( i = 0; i < len; ++i){
            if(s[i] == '('){
                ss.push(1);
                continue;
            }
            if(s[i] == '['){
                ss.push(2);
                continue;
            }
            if(s[i] == '{'){
                ss.push(3);
                continue;
            }
            if(!ss.empty()){
                if(s[i] == ')' && ss.top() == 1){
                    ss.pop();
                }else{
                    if(s[i] == ']' && ss.top() == 2){
                        ss.pop();
                    }else{
                        if(s[i] == '}' && ss.top() == 3){
                            ss.pop();
                        }else{
                            return false;
                        }
                    }
                }
            }else{
                return false;
            }
        }
        return ss.empty();
    }
};
