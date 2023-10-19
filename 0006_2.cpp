class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> rows(numRows, "");
        int len = s.length();
        if(numRows == 1){
            return s;
        }
        
        int l = numRows *2 -2;
        int rindex;
        int i = 0, j;
        while(i < len){
            rindex = i % l;
            if(rindex < numRows){
                rows[rindex].push_back(s[i]);
            }else{
                rows[l-rindex].push_back(s[i]);
            }
            ++i;
        }

        string ans = "";
        for(i = 0; i < numRows; ++i){
            ans.append(rows[i]);
        }
        return ans;

    }
};
