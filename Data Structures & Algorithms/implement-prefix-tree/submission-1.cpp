class PrefixTree {
public:
    PrefixTree() {
        for(int i = 0; i < 26; i++) dict.emplace_back(nullptr);
    }
    bool ends = false;
    vector<PrefixTree*> dict;

    void insert(string word) {
        auto node = this;
        for(int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if(node->dict[idx] == nullptr)
                node->dict[idx] = new PrefixTree();
            node = node->dict[idx];
            if(i == word.size() - 1) {
                node->ends = true;
            }
        }
    }
    
    bool search(string word) {
        auto node = this;
        for(int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if(node->dict[idx] == NULL) return false;
            node = node->dict[idx];
            if(i == word.size() - 1 && node->ends) {
                return true;
            }
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        auto node = this;
        for(int i = 0; i < prefix.size(); i++) {
            int idx = prefix[i] - 'a';
            if(node->dict[idx] == NULL) return false;
            node = node->dict[idx];
        }
        return true;
    }
};
