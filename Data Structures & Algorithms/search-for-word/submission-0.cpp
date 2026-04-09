class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> used(board.size(), vector<int>(board[0].size(), 0));

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == word[0]) {
                    used[i][j] = 1;
                    if(match(board, used, word, i, j, 1))
                        return true;
                    used[i][j] = 0;
                }
            }
        }

        return false;
    }

    bool match(vector<vector<char>>& board, vector<vector<int>>& used, string word, int i, int j, int k) {
        if(k == word.size()) return true;
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false;

        if(i > 0 && used[i-1][j] == 0 && word[k] == board[i-1][j]){
            used[i-1][j] = 1;
            if(match(board, used, word, i-1, j, k+1))
                return true;
            used[i-1][j] = 0;
        }
        if(j > 0 && used[i][j-1] == 0 && word[k] == board[i][j-1]){
            used[i][j-1] = 1;
            if(match(board, used, word, i, j-1, k+1))
                return true;
            used[i][j-1] = 0;
        }
        if(i < board.size() - 1 && used[i+1][j] == 0 && word[k] == board[i+1][j]){
            used[i+1][j] = 1;
            if(match(board, used, word, i+1, j, k+1))
                return true;
            used[i+1][j] = 0;
        }
        if(j < board[0].size() - 1 && used[i][j+1] == 0 && word[k] == board[i][j+1]){
            used[i][j+1] = 1;
            if(match(board, used, word, i, j+1, k+1))
                return true;
            used[i][j+1] = 0;
        }

        return false;

    }
};
