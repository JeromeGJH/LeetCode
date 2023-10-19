class RandomizedSet {
public:
    unordered_map<int, int> set;
    vector<int> ele;
    int len = 0;
    RandomizedSet() {
        //cout << "here1" <<endl;
        //srand(1);
        
    }
    
    bool insert(int val) {
        //cout << "here2" <<endl;
        if(set.count(val) == 0){
            ele.emplace_back(val);
            len += 1;
            set[val] = len-1;
            return true;
        }else{
            return false;
        }
    }
    
    bool remove(int val) {
        //cout << "here3" <<endl;
        if(set.count(val) == 0){
            return false;
        }else{
            int index = set[val];
            ele[index] = ele[len-1];
            set[ele[len-1]] = index;
            ele.pop_back();
            len -= 1;
            set.erase(val);
            return true;
        }

    }
    
    int getRandom() {
        //cout << "here4" <<endl;
        int res = rand()%len;
        //cout << res <<endl;
        //cout << len <<endl;

        //cout << ele[res] <<endl;
        //cout << "here5" <<endl;
        return ele[res];

    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
