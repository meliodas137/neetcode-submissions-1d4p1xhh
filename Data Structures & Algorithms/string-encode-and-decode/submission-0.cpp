class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";

        for(auto &str: strs) {
            for(auto &ch:str) {
                res+=to_string((int)ch);
                res+=',';
            }
            res+=';';
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        string curr = "";
        string temp = "";
        for(auto &ch: s) {
            if(ch == ',') 
            {
                curr += char(stoi(temp));
                temp = "";
            }
            else if(ch == ';')
            {
                res.emplace_back(curr);
                curr = "";
            }
            else 
            {
                temp += ch;
            }

        }
        return res;
    }
};
