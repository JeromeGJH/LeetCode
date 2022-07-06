class TimeMap {
public:
    map<string, vector<pair<string, int>>> m;
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back(make_pair(value, timestamp));

    }
    
    string get(string key, int timestamp) {
        if(m.count(key) == 0){
            return "";
        }
        vector<pair<string, int>>& tmp = m[key];
        int left = 0, right = tmp.size()-1, mid;
        while(left < right){
            mid = (left + right) / 2 + 1;
            if(tmp[mid].second <= timestamp){
                left = mid;
            }else{
                right = mid - 1;
            }
        }
        if(tmp[left].second > timestamp){
            return "";
        }
        return tmp[left].first;


    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
