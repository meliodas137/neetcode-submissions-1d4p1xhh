class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> v(n, 0);

        vector<vector<int>> adj(n, vector<int>(n, 0));

        for(auto &e: edges) {
            adj[e[0]][e[1]] = 1;
            adj[e[1]][e[0]] = 1;
        }

        int count = 0;

        for(int i = 0; i < n; i++) {
            if(v[i] == 0){
                count++;
                DFS(v, adj, i);
            }
        }

        return count;
    }

    void DFS(vector<int> &v, vector<vector<int>> &adj, int s) {
        v[s] = 1;

        for(int i = 0; i < v.size(); i++) {
            if(adj[s][i] == 1 && v[i] == 0) DFS(v, adj, i); 
        }

        return;
    } 
};
