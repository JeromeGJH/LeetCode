class WordDictionary {
private:
vector<WordDictionary*> children;
bool isEnd;
bool find = false;

bool searchPrefix(WordDictionary* node, string prefix, int index) {
    if(find){
        return true;
    }
    int len = prefix.length();
    //cout << prefix<<" "<<index << endl;
    //cout << word << endl;
    if(index == len){
        if(node->isEnd){
            find = true;
            return true;
        }else{
            return false;
        }
    }
    bool res = false;
    int i = 0;
    char ch;
    

    ch = prefix[index];
    //cout << ch-'a' <<endl;
    if(ch == '.'){
        //cout << "get ."<<endl;
        int i = 0;
        for(i = 0; i < 26; ++i){
            if (node->children[i] != nullptr) {
                res |= searchPrefix(node->children[i], prefix, index+1);
            }
        }
    }else{
        ch -= 'a';
        if (node->children[ch] == nullptr) {
            return false;
        }else{
            res |= searchPrefix(node->children[ch], prefix, index+1);
        }
    }
    return res;
}

public:
    WordDictionary(): children(26), isEnd(false) {

    }
    
    void addWord(string word) {
        WordDictionary* node = this;
        for (char ch : word) {
            ch -= 'a';
            if (node->children[ch] == nullptr) {
                node->children[ch] = new WordDictionary();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        bool res = this->searchPrefix(this, word, 0);
        find = false;
        return res;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
