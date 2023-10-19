class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> rows(numRows, vector<char>());
        int len = s.length();
        if(numRows == 1){
            return s;
        }
        
        int l = numRows *2 -2;
        int rindex;
        int cindex;
        int i = 0, j;
        while(i < len){
            rindex = i % l;
            if(rindex < numRows-1){
                rows[rindex].emplace_back(s[i]);
                for(j = 0; j < numRows-rindex-2; ++j){
                    rows[rindex].emplace_back(' ');
                }
            }else{
                rows[l-rindex].emplace_back(s[i]);
                for(j = 0; j < l-rindex-1; ++j){
                    rows[l-rindex].emplace_back(' ');
                }
            }
            ++i;
        }

        string ans = "";
        for(i = 0; i < numRows; ++i){
            for(j = 0; j < rows[i].size(); ++j){
                //cout << i <<" "<<  j << endl;
                //cout << rows[i][j] << endl;
                if(rows[i][j] != ' '){
                    ans.push_back(rows[i][j]);
                }
                //cout << ans << endl;
            }
        }
        return ans;

    }
};
