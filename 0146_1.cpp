class LRUCache {
public:
    vector<int> keys;
    unordered_map<int, int> cache;
    unordered_map<int, int> index;
    int limit = 0;

    void remove(vector<int>& v, int key){
        //cout << "here1"<< endl;
        int i;
        for(i = 0; i < v.size(); ++i){
            if(v[i] == key){
                break;
            }
        }
        //cout << "here"<< endl;
        v.erase(v.begin()+i, v.begin()+i+1);
        //cout << "here1"<< endl;
        return;
    }


    LRUCache(int capacity) {
        limit = capacity;

    }
    
    int get(int key) {
        //cout << "here2"<< endl;
        if(cache.count(key) == 0){
            return -1;
        }
        remove(keys, key);
        keys.emplace_back(key);
        //cout << "here2"<< endl;
        return cache[key];
        
    }
    
    void put(int key, int value) {
        //cout << "here3"<< endl;
        if(cache.count(key) == 0){
            if(keys.size() < limit){
                keys.emplace_back(key);
                cache[key] = value;
            }else{
                cout << "here4"<< endl;
                int tmp = keys[0];
                remove(keys, tmp);
                keys.emplace_back(key);
                cache.erase(tmp);
                cache[key] = value;
            }

        }else{
            cache[key] = value;
            remove(keys, key);
            keys.emplace_back(key);
        }
        //cout << "here3"<< endl;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
