class WordDictionary {
public:
    WordDictionary() {
        for(int i = 0; i < 26; i++) dict.emplace_back(nullptr);
    }
    bool ends = false;
    vector<WordDictionary*> dict;

    void addWord(string word) {
        auto node = this;
        for(int i = 0; i < word.size(); i++) {
            int idx = word[i] - 'a';
            if(node->dict[idx] == nullptr)
                node->dict[idx] = new WordDictionary();
            node = node->dict[idx];
            if(i == word.size() - 1) {
                node->ends = true;
            }
        }
    }
    
    bool search(string word) {
        return searchFrom(word, 0, this);
    }

    bool searchFrom(string word, int from, WordDictionary *node){
        if(from == word.size() && node->ends) return true;

        for(int i = from; i < word.size(); i++) {
            if(word[i] != '.') {
                int idx = word[i] - 'a';
                if(node->dict[idx] == nullptr) return false;
                node = node->dict[idx];
                if(i == word.size() - 1 && node->ends) {
                    return true;
                }
                continue;
            }
            else {
                for(int j = 0; j < 26; j++) {
                    if(node->dict[j] != nullptr && searchFrom(word, i+1, node->dict[j])) return true; 
                }
                break;
            }
        }
        return false;
    }
};
