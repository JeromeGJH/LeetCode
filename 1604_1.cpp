class Solution {
public:
    int extractInfo(string& s){
        int res = stoi(string(s.begin(), s.begin() + 2)) * 60;
        res += stoi(string(s.begin() + 3, s.end()));
        return res;
    }

    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        vector<string> ret;
        int n = keyName.size();
        int i;
        int curr_time;
        unordered_map<string, vector<int>> record;
        for(i = 0; i < n; ++i){
            record[keyName[i]].emplace_back(extractInfo(keyTime[i]));
        }

        for(auto [name, time] : record){
            sort(time.begin(), time.end());
            for(i = 0; i < time.size()-2; ++i){
                if(time[i+2] - time[i] <= 60){
                    ret.emplace_back(name);
                    break;
                }
            }
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
};
