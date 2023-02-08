class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        int i = 0, j = 0, l;
        string s, parentF;
        vector<string> res;
        unordered_map<string, int> fmap;
        for(i =0; i < n; ++i){
            fmap[folder[i]] = 1;
        }
        for(i =0; i < n; ++i){
            l = folder[i].length();
            s = folder[i];
            for(j = 1; j < l; ++j){
                if(s[j] == '/'){
                    parentF = string(s.begin(), s.begin() + j);
                    if(fmap.count(parentF) > 0 && fmap[parentF] == 1){
                        fmap[s] = 0;
                        break;
                    }

                }

            }
        }
        for(auto [name, count] : fmap){
            if(count == 1){
                res.emplace_back(name);
            }
        }
        return res;

    }
};
