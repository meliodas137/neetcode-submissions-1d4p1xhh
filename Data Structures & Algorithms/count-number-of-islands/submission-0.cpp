class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0, x = grid.size(), y = grid[0].size();

        for(int i = 0; i < x; i++) {
            for(int j = 0; j < y; j++) {
                if(grid[i][j] == '1') {
                    count++;
                    mark(grid, i, j, x, y);
                }
            }
        } 
        return count;
    }

    void mark(vector<vector<char>>& grid, int i, int j, int x, int y) {
        if(i < 0 || j < 0 || i >= x || j >= y) return;

        if(grid[i][j] == '0') return;
        grid[i][j] = '0';

        if(i > 0 && grid[i-1][j] == '1') {
            mark(grid, i-1, j, x, y);
        }
        if(j > 0 && grid[i][j-1] == '1') {
            mark(grid, i, j-1, x, y);
        }
        if(i < x - 1 && grid[i+1][j] == '1') {
            mark(grid, i+1, j, x, y);
        }
        if(j < y - 1 && grid[i][j+1] == '1') {
            mark(grid, i, j+1, x, y);
        }

        return;
    }
};
