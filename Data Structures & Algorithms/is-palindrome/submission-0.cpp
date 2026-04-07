class Solution {
public:
    bool isAlphaNum (char ch) {
        if ((ch >= 'a' && ch <='z') || 
            (ch >= 'A' && ch <='Z') ||
            (ch >= '0' && ch <='9')) return true;

        return false;
    }

    int to_l(char ch) {
        if(ch >= 'a' && ch <='z') return ch - 'a';
        if(ch >= 'A' && ch <='Z') return ch - 'A';
        return ch;
    }

    bool isPalindrome(string s) {
        int sz = s.size();
        if (sz <= 1) return true;

        int i = 0, j = sz - 1;
        while(j > i) {
            if(isAlphaNum(s[i]) && isAlphaNum(s[j])) {
                if(to_l(s[i]) != to_l(s[j])) return false;
                j--;
                i++;
                continue;
            }
            if(!isAlphaNum(s[i])) i++;
            if(!isAlphaNum(s[j])) j--;
        }
        return true;
    }
};
