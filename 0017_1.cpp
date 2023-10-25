class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int len = digits.length();
        if(len == 0){
            return vector<string>();
        }
        int i, j;
        vector<int> nums(len, 0);
        vector<string> pre;
        vector<string> cur;
        vector<string> s;
        s.emplace_back("abc");
        s.emplace_back("def");
        s.emplace_back("ghi");
        s.emplace_back("jkl");
        s.emplace_back("mno");
        s.emplace_back("pqrs");
        s.emplace_back("tuv");
        s.emplace_back("wxyz");

        for(i = 0; i < len; ++i){
            nums[i] = digits[i] - '0';
        }
        string str = s[nums[0]-2];
        for(i = 0; i < str.length(); ++i){
            pre.emplace_back(str.substr(i, 1));
        }
        for(i = 1; i < len; ++i){
            string str = s[nums[i]-2];
            for(auto e : pre){
                for(j = 0; j < str.length(); ++j){
                    cur.emplace_back(e + str.substr(j, 1));
                }
            }
            pre = cur;
            cur = vector<string>();
            
        }
        return pre;
    }
};
