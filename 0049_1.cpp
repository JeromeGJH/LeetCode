class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int len = strs.size();
        if(len <= 1){
            ans.emplace_back(strs);
            return ans;
        }

        unordered_map<string, vector<int>> word;
        int i, j, k;
        for(i = 0; i< len; ++i){
            string s = "";
            vector<int> count(26, 0);
            for(j = 0; j < strs[i].length(); ++j){
                int index = strs[i][j] - 'a';
                count[index] += 1;
            }
            for(k = 0; k < 26; ++k){
                s.append(to_string(count[k]));
                s.append("0");
            }
            cout << s << endl;
            if(word.count(s) == 0){
                word[s] = vector<int>({i});
            }else{
                word[s].emplace_back(i);
            }
        }
        for(auto it = word.begin(); it != word.end(); ++it){
            vector<string> vs;
            int size = it->second.size();
            for(i = 0; i < size; ++i){
                vs.emplace_back(strs[it->second[i]]);
            }
            ans.emplace_back(vs);
            vs.clear();
        }
        return ans;
    }
};
