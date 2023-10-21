struct DLinkedNode {
    int key, val;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), val(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), val(_value), prev(nullptr), next(nullptr) {}
};


class LRUCache {
public:
    DLinkedNode * DH = new DLinkedNode();
    DLinkedNode * DT = new DLinkedNode();

    //unordered_map<int, int> cache;
    unordered_map<int, DLinkedNode *> cache;
    int limit = 0;
    int size = 0;

    void moveToHead(int key){
        DLinkedNode * tmp = cache[key];
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
        tmp->next = DH->next;
        tmp->next->prev = tmp;
        tmp->prev = DH;
        DH->next = tmp;
    }

    void addToHead(int key, int val){
        DLinkedNode * tmp = new DLinkedNode(key, val);
        tmp->next = DH->next;
        tmp->next->prev = tmp;
        tmp->prev = DH;
        DH->next = tmp;
        cache[key] = tmp;
    }

    int removeTail(){
        int key = DT->prev->key;
        //DLinkedNode * tmp = DT->prev;
        DT->prev->prev->next = DT;
        DT->prev = DT->prev->prev;
        return key;
    }

    LRUCache(int capacity) {
        limit = capacity;
        DH->next = DT;
        DT->prev = DH;

    }
    
    int get(int key) {
        //cout << "here2"<< endl;
        if(cache.count(key) == 0){
            return -1;
        }
        moveToHead(key);
        return cache[key]->val;
        
    }
    
    void put(int key, int value) {
        //cout << "here3"<< endl;
        if(cache.count(key) == 0){
            if(size < limit){
                addToHead(key, value);
                ++size;
            }else{
                //cout << "here4"<< endl;
                int tmp = removeTail();
                addToHead(key, value);
                cache.erase(tmp);
            }
        }else{
            cache[key]->val = value;
            moveToHead(key);
        }
    }


};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
