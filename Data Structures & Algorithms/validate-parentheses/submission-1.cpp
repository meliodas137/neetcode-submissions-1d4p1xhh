class Solution {
public:
    bool isValid(string s) {
        vector<char> st;

        for(auto &ch: s) {
            if(ch == '[' || ch == '{' || ch == '(') st.emplace_back(ch);
            else if(!st.empty() && ((ch == '}' && st.back() == '{') ||
                (ch == ']' && st.back() == '[') ||
                (ch == ')' && st.back() == '('))) st.pop_back();
            else return false; 
        }

        return st.empty();
    }
};
